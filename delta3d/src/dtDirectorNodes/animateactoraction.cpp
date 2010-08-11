/*
 * Delta3D Open Source Game and Simulation Engine
 * Copyright (C) 2008 MOVES Institute
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2.1 of the License, or (at your option)
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * Author: Jeff P. Houde
 */

#include <dtDirectorNodes/animateactoraction.h>

#include <dtDAL/actoridactorproperty.h>
#include <dtDAL/floatactorproperty.h>
#include <dtDAL/stringactorproperty.h>
#include <dtDAL/vectoractorproperties.h>
#include <dtDAL/arrayactorproperty.h>
#include <dtDAL/containeractorproperty.h>

#include <dtDirector/director.h>

#include <dtAnim/animationgameactor.h>
#include <dtAnim/animationchannel.h>
#include <dtAnim/animationhelper.h>
#include <dtAnim/sequencemixer.h>

namespace dtDirector
{
   ////////////////////////////////////////////////////////////////////////////////
   AnimateActorAction::AnimateActorAction()
      : ActionNode()
      , mTime(0.0f)
      , mIsActive(false)
      , mAnimIndex(0)
   {
      mAnimActor = "";

      AddAuthor("Jeff P. Houde");
   }

   ////////////////////////////////////////////////////////////////////////////////
   AnimateActorAction::~AnimateActorAction()
   {
   }

   ////////////////////////////////////////////////////////////////////////////////
   void AnimateActorAction::Init(const NodeType& nodeType, DirectorGraph* graph)
   {
      ActionNode::Init(nodeType, graph);

      // Create multiple inputs for different operations.
      mInputs.clear();
      mInputs.push_back(InputLink(this, "Start"));
      mInputs.push_back(InputLink(this, "Stop"));

      mOutputs.clear();
      mOutputs.push_back(OutputLink(this, "Started"));
      mOutputs.push_back(OutputLink(this, "Stopped"));
      mOutputs.push_back(OutputLink(this, "Finished"));
   }

   ////////////////////////////////////////////////////////////////////////////////
   void AnimateActorAction::BuildPropertyMap()
   {
      ActionNode::BuildPropertyMap();

      // Create our value links.
      dtDAL::ActorIDActorProperty* actorProp = new dtDAL::ActorIDActorProperty(
         "Actor", "Actor",
         dtDAL::ActorIDActorProperty::SetFuncType(this, &AnimateActorAction::SetAnimActor),
         dtDAL::ActorIDActorProperty::GetFuncType(this, &AnimateActorAction::GetAnimActor),
         "dtActors::AnimationGameActor", "The actor to animate.");
      AddProperty(actorProp);

      // Animation Data Properties
      {
         dtDAL::ContainerActorProperty* animDataProp = new dtDAL::ContainerActorProperty(
            "Anim Data", "Anim Data", "The animation data.", "");

         dtDAL::StringActorProperty* nameProp = new dtDAL::StringActorProperty(
            "Name", "Name",
            dtDAL::StringActorProperty::SetFuncType(this, &AnimateActorAction::SetAnimName),
            dtDAL::StringActorProperty::GetFuncType(this, &AnimateActorAction::GetAnimName),
            "The name of the animation to play.");
         animDataProp->AddProperty(nameProp);

         dtDAL::FloatActorProperty* timeProp = new dtDAL::FloatActorProperty(
            "Start Time", "Start Time",
            dtDAL::FloatActorProperty::SetFuncType(this, &AnimateActorAction::SetAnimTime),
            dtDAL::FloatActorProperty::GetFuncType(this, &AnimateActorAction::GetAnimTime),
            "The time to start the animation.");
         animDataProp->AddProperty(timeProp);

         dtDAL::FloatActorProperty* durationProp = new dtDAL::FloatActorProperty(
            "Duration", "Duration",
            dtDAL::FloatActorProperty::SetFuncType(this, &AnimateActorAction::SetAnimDuration),
            dtDAL::FloatActorProperty::GetFuncType(this, &AnimateActorAction::GetAnimDuration),
            "The duration of the animation.");
         animDataProp->AddProperty(durationProp);

         dtDAL::FloatActorProperty* blendInProp = new dtDAL::FloatActorProperty(
            "Blend in Time", "Blend in Time",
            dtDAL::FloatActorProperty::SetFuncType(this, &AnimateActorAction::SetBlendInTime),
            dtDAL::FloatActorProperty::GetFuncType(this, &AnimateActorAction::GetBlendInTime),
            "The animation blend in time.");
         animDataProp->AddProperty(blendInProp);

         dtDAL::FloatActorProperty* blendOutProp = new dtDAL::FloatActorProperty(
            "Blend out Time", "Blend out Time",
            dtDAL::FloatActorProperty::SetFuncType(this, &AnimateActorAction::SetBlendOutTime),
            dtDAL::FloatActorProperty::GetFuncType(this, &AnimateActorAction::GetBlendOutTime),
            "The animation blend out time.");
         animDataProp->AddProperty(blendOutProp);

         dtDAL::FloatActorProperty* weightProp = new dtDAL::FloatActorProperty(
            "Weight", "Weight",
            dtDAL::FloatActorProperty::SetFuncType(this, &AnimateActorAction::SetAnimWeight),
            dtDAL::FloatActorProperty::GetFuncType(this, &AnimateActorAction::GetAnimWeight),
            "The animation weight.");
         animDataProp->AddProperty(weightProp);

         dtDAL::ArrayActorPropertyBase* animListProp = new dtDAL::ArrayActorProperty<AnimData>(
            "Animations", "Animations", "List of animations to play.",
            dtDAL::ArrayActorProperty<AnimData>::SetIndexFuncType(this, &AnimateActorAction::SetAnimIndex),
            dtDAL::ArrayActorProperty<AnimData>::GetDefaultFuncType(this, &AnimateActorAction::GetDefaultAnim),
            dtDAL::ArrayActorProperty<AnimData>::GetArrayFuncType(this, &AnimateActorAction::GetAnimArray),
            dtDAL::ArrayActorProperty<AnimData>::SetArrayFuncType(this, &AnimateActorAction::SetAnimArray),
            animDataProp, "");
         AddProperty(animListProp);
      }

      dtDAL::FloatActorProperty* timeProp = new dtDAL::FloatActorProperty(
         "Time", "Time",
         dtDAL::FloatActorProperty::SetFuncType(this, &AnimateActorAction::SetTime),
         dtDAL::FloatActorProperty::GetFuncType(this, &AnimateActorAction::GetTime),
         "The current time.");

      // This will expose the properties in the editor and allow
      // them to be connected to ValueNodes.
      mValues.push_back(ValueLink(this, actorProp, true, true, true));
      mValues.push_back(ValueLink(this, timeProp, false, false, true));
   }

   //////////////////////////////////////////////////////////////////////////
   bool AnimateActorAction::Update(float simDelta, float delta, int input, bool firstUpdate)
   {
      switch (input)
      {
      case INPUT_START:
         {
            if (firstUpdate)
            {
               OutputLink* link = GetOutputLink("Started");
               if (link) link->Activate();
            }

            // On the first activation, initialize.
            if (!mIsActive)
            {
               if (firstUpdate)
               {
                  mIsActive = true;

                  // Activate the "Out" output link.
                  ActionNode::Update(simDelta, delta, input, firstUpdate);
               }
               else
               {
                  // TODO: Stop all animations.

                  OutputLink* link = GetOutputLink("Finished");
                  if (link) link->Activate();
                  return false;
               }
            }

            float curTime = GetFloat("Time");

            // Find any animations that need to play.
            std::vector<AnimData> playList;
            int count = (int)mAnimList.size();
            for (int index = 0; index < count; ++index)
            {
               AnimData& data = mAnimList[index];

               if (data.mTime <= curTime && data.mTime + data.mDuration >= curTime)
               {
                  // Add this animation to the play list, sorted by start time.
                  bool added = false;
                  int sortCount = (int)playList.size();
                  for (int sortIndex = 0; sortIndex < sortCount; ++sortIndex)
                  {
                     if (playList[sortIndex].mTime >= data.mTime)
                     {
                        playList.insert(playList.begin() + sortIndex, data);
                        added = true;
                     }
                  }

                  if (!added)
                  {
                     playList.push_back(data);
                  }
               }
            }

            count = GetPropertyCount("Actor");
            for (int index = 0; index < count; ++index)
            {
               dtDAL::ActorProxy* proxy = GetActor("Actor", index);
               if (proxy)
               {
                  dtAnim::AnimationGameActor* actor = dynamic_cast<dtAnim::AnimationGameActor*>(proxy->GetActor());
                  if (actor)
                  {
                     // First clear all animations currently playing in this actor.
                     dtAnim::SequenceMixer& mixer = actor->GetHelper()->GetSequenceMixer();
                     mixer.ClearActiveAnimations(0.0f);
                     mixer.Update(0.0f);

                     float elapsedTime = 0.0f;
                     int animCount = (int)playList.size();
                     for (int animIndex = 0; animIndex < animCount; ++animIndex)
                     {
                        AnimData& data = playList[animIndex];
                        if (elapsedTime < data.mTime)
                        {
                           float increment = data.mTime - elapsedTime;
                           elapsedTime = data.mTime;

                           actor->GetHelper()->Update(increment);
                        }

                        // Create the animation.
                        const dtAnim::AnimationChannel* anim = dynamic_cast<const dtAnim::AnimationChannel*>(mixer.GetRegisteredAnimation(data.mName));
                        if (anim)
                        {
                           dtCore::RefPtr<dtAnim::AnimationChannel> newAnim = NULL;
                           newAnim = dynamic_cast<dtAnim::AnimationChannel*>(anim->Clone(actor->GetHelper()->GetModelWrapper()).get());
                           newAnim->SetLooping(false);
                           newAnim->SetAction(true);
                           newAnim->SetFadeIn(data.mBlendInTime);
                           newAnim->SetFadeOut(data.mBlendOutTime);
                           newAnim->SetBaseWeight(data.mWeight);

                           // TODO: Fix Speed, Start time, and End time attributes.
                           //newAnim->GetAnimation()->SetSpeed(data.mSpeed);
                           //newAnim->SetStartTime(data.mStartTime);

                           mixer.PlayAnimation(newAnim);
                        }
                     }

                     if (elapsedTime <= curTime)
                     {
                        float increment = curTime - elapsedTime;
                        elapsedTime = curTime;

                        actor->GetHelper()->Update(increment);
                     }
                  }
               }
            }

            return true;
         }
         break;

      case INPUT_STOP:
         {
            mIsActive = false;

            // Activate the "Stopped" output link.
            if (firstUpdate)
            {
               OutputLink* link = GetOutputLink("Stopped");
               if (link) link->Activate();
            }
         }
         break;
      }

      return false;
   }

   ////////////////////////////////////////////////////////////////////////////////
   void AnimateActorAction::SetAnimActor(const dtCore::UniqueId& value)
   {
      mAnimActor = value;
   }

   ////////////////////////////////////////////////////////////////////////////////
   dtCore::UniqueId AnimateActorAction::GetAnimActor()
   {
      return mAnimActor;
   }

   ////////////////////////////////////////////////////////////////////////////////
   void AnimateActorAction::SetAnimName(const std::string& value)
   {
      if (mAnimIndex >= (int)mAnimList.size()) return;

      AnimData& data = mAnimList[mAnimIndex];
      data.mName = value;
   }

   ////////////////////////////////////////////////////////////////////////////////
   std::string AnimateActorAction::GetAnimName()
   {
      if (mAnimIndex >= (int)mAnimList.size()) return "";

      AnimData& data = mAnimList[mAnimIndex];
      return data.mName;
   }

   ////////////////////////////////////////////////////////////////////////////////
   void AnimateActorAction::SetAnimTime(float value)
   {
      if (mAnimIndex >= (int)mAnimList.size()) return;

      AnimData& data = mAnimList[mAnimIndex];
      data.mTime = value;
   }

   ////////////////////////////////////////////////////////////////////////////////
   float AnimateActorAction::GetAnimTime()
   {
      if (mAnimIndex >= (int)mAnimList.size()) return 0.0f;

      AnimData& data = mAnimList[mAnimIndex];
      return data.mTime;
   }

   ////////////////////////////////////////////////////////////////////////////////
   void AnimateActorAction::SetAnimDuration(float value)
   {
      if (mAnimIndex >= (int)mAnimList.size()) return;

      AnimData& data = mAnimList[mAnimIndex];
      data.mDuration = value;
   }

   ////////////////////////////////////////////////////////////////////////////////
   float AnimateActorAction::GetAnimDuration()
   {
      if (mAnimIndex >= (int)mAnimList.size()) return 0.0f;

      AnimData& data = mAnimList[mAnimIndex];
      return data.mDuration;
   }

   ////////////////////////////////////////////////////////////////////////////////
   void AnimateActorAction::SetBlendInTime(float value)
   {
      if (mAnimIndex >= (int)mAnimList.size()) return;

      AnimData& data = mAnimList[mAnimIndex];
      data.mBlendInTime = value;
   }

   ////////////////////////////////////////////////////////////////////////////////
   float AnimateActorAction::GetBlendInTime()
   {
      if (mAnimIndex >= (int)mAnimList.size()) return 0.0f;

      AnimData& data = mAnimList[mAnimIndex];
      return data.mBlendInTime;
   }

   ////////////////////////////////////////////////////////////////////////////////
   void AnimateActorAction::SetBlendOutTime(float value)
   {
      if (mAnimIndex >= (int)mAnimList.size()) return;

      AnimData& data = mAnimList[mAnimIndex];
      data.mBlendOutTime = value;
   }

   ////////////////////////////////////////////////////////////////////////////////
   float AnimateActorAction::GetBlendOutTime()
   {
      if (mAnimIndex >= (int)mAnimList.size()) return 0.0f;

      AnimData& data = mAnimList[mAnimIndex];
      return data.mBlendOutTime;
   }

   ////////////////////////////////////////////////////////////////////////////////
   void AnimateActorAction::SetAnimWeight(float value)
   {
      if (mAnimIndex >= (int)mAnimList.size()) return;

      AnimData& data = mAnimList[mAnimIndex];
      data.mWeight = value;
   }

   ////////////////////////////////////////////////////////////////////////////////
   float AnimateActorAction::GetAnimWeight()
   {
      if (mAnimIndex >= (int)mAnimList.size()) return 1.0f;

      AnimData& data = mAnimList[mAnimIndex];
      return data.mWeight;
   }

   ////////////////////////////////////////////////////////////////////////////////
   void AnimateActorAction::SetAnimIndex(int index)
   {
      mAnimIndex = index;
   }

   ////////////////////////////////////////////////////////////////////////////////
   AnimateActorAction::AnimData AnimateActorAction::GetDefaultAnim()
   {
      AnimData data;
      data.mName = "";
      data.mTime = 0.0f;
      data.mDuration = 0.0f;
      data.mBlendInTime = 0.0f;
      data.mBlendOutTime = 0.0f;
      data.mWeight = 1.0f;
      return data;
   }

   ////////////////////////////////////////////////////////////////////////////////
   std::vector<AnimateActorAction::AnimData> AnimateActorAction::GetAnimArray()
   {
      return mAnimList;
   }

   ////////////////////////////////////////////////////////////////////////////////
   void AnimateActorAction::SetAnimArray(const std::vector<AnimateActorAction::AnimData>& value)
   {
      mAnimList = value;
   }

   ////////////////////////////////////////////////////////////////////////////////
   void AnimateActorAction::SetTime(float value)
   {
      mTime = value;
   }

   ////////////////////////////////////////////////////////////////////////////////
   float AnimateActorAction::GetTime()
   {
      return mTime;
   }
}

////////////////////////////////////////////////////////////////////////////////