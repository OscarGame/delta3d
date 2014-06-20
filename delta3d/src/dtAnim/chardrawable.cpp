
#include <dtAnim/basemodelwrapper.h>
#include <dtAnim/chardrawable.h>
#include <dtCore/system.h>
#include <dtUtil/log.h>
#include <osg/MatrixTransform>
#include <osg/Node>
#include <osg/Timer>
#include <osg/Texture2D> //Cal3DLoader needs this

#include <cassert>

using namespace dtAnim;

////////////////////////////////////////////////////////////////////////////////
CharDrawable::CharDrawable(dtAnim::BaseModelWrapper* wrapper)
   : dtCore::Transformable()
   , mNode(new osg::Node())
   , mLastMeshCount(0)
{
   AddSender(&dtCore::System::GetInstance());

   GetMatrixNode()->addChild(mNode.get());

   SetModelWrapper(wrapper);
}

////////////////////////////////////////////////////////////////////////////////
CharDrawable::~CharDrawable()
{
   RemoveSender(&dtCore::System::GetInstance());
}

////////////////////////////////////////////////////////////////////////////////
void CharDrawable::OnMessage(dtCore::Base::MessageData* data)
{
   // tick the animation
   if (data->message == dtCore::System::MESSAGE_PRE_FRAME)
   {
      if (mModel.valid())
      {
         dtAnim::AnimationUpdaterInterface* animator = mModel->GetAnimator();
         if (animator != NULL)
         {
            double dt = *static_cast<double*>(data->userData);
            animator->Update(dt);
         }

         if (mLastMeshCount != mModel->GetMeshCount())
         {
            //there are a different number of meshes, better rebuild our drawables
            RebuildSubmeshes();
            mLastMeshCount = mModel->GetMeshCount();
         }
      }
   }
}

////////////////////////////////////////////////////////////////////////////////
osg::Node* CharDrawable::GetNode() const
{
   return mNode.get();
}

////////////////////////////////////////////////////////////////////////////////
void CharDrawable::SetNode(osg::Node* node)
{
   if (mNode != node)
   {
      if (mNode.valid())
      {
         GetMatrixNode()->removeChild(mNode.get());
      }

      mNode = node;

      if (mNode.valid())
      {
         GetMatrixNode()->addChild(mNode.get());
      }
   }
}

////////////////////////////////////////////////////////////////////////////////
osg::Node* CharDrawable::RebuildSubmeshes()
{
   if (mModel.valid())
   {
      SetNode(mModel->CreateDrawableNode(false));
   }

   return mNode.get();
}

////////////////////////////////////////////////////////////////////////////////
void CharDrawable::SetModelWrapper(dtAnim::BaseModelWrapper* wrapper)
{
   if (mModel.get() != wrapper)
   {
      mModel = wrapper;

      if (mModel.valid())
      {
         if (mModel->GetDrawableNode() != NULL)
         {
            SetNode(mModel->GetDrawableNode());
         }
         else
         {
            RebuildSubmeshes();
         }
         mLastMeshCount = mModel->GetMeshCount();
      }
      else
      {
         mLastMeshCount = 0;
      }
   }
}

////////////////////////////////////////////////////////////////////////////////
dtAnim::BaseModelWrapper* CharDrawable::GetModelWrapper()
{
   return mModel.get();
}
