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

#include <dtDirectorGUINodes/buttonevent.h>
#include <dtDirectorGUINodes/guinodemanager.h>

#include <dtDAL/stringselectoractorproperty.h>

#include <dtGUI/gui.h>
#include <dtGUI/scriptmodule.h>
#include <CEGUI/CEGUIWindow.h>
#include <CEGUI/elements/CEGUIButtonBase.h>

#include <dtDirector/director.h>

namespace dtDirector
{
   ///////////////////////////////////////////////////////////////////////////////////////
   ButtonEvent::ButtonEvent()
       : EventNode()
   {
      AddAuthor("Jeff P. Houde");
   }

   /////////////////////////////////////////////////////////////////////////////
   ButtonEvent::~ButtonEvent()
   {
   }

   /////////////////////////////////////////////////////////////////////////////
   void ButtonEvent::Init(const NodeType& nodeType, DirectorGraph* graph)
   {
      EventNode::Init(nodeType, graph);

      mOutputs.clear();
      mOutputs.push_back(OutputLink(this, "Clicked", "Activated when the GUI button has been clicked."));
      mOutputs.push_back(OutputLink(this, "Double Clicked", "Activated when the GUI button has been double clicked."));
      mOutputs.push_back(OutputLink(this, "Hover Enter", "Activated when the mouse has entered the bounds of the GUI button."));
      mOutputs.push_back(OutputLink(this, "Hover Leave", "Activated when the mouse has left the bounds of the GUI button."));
   }

   /////////////////////////////////////////////////////////////////////////////
   void ButtonEvent::OnStart()
   {
      GUINodeManager::GetLayout(GetString("Layout"));
      RefreshConnections();
   }

   ////////////////////////////////////////////////////////////////////////////////
   void ButtonEvent::OnFinishedLoading()
   {
   }

   /////////////////////////////////////////////////////////////////////////////
   void ButtonEvent::BuildPropertyMap()
   {
      EventNode::BuildPropertyMap();

      dtDAL::StringSelectorActorProperty* layoutProp =
         new dtDAL::StringSelectorActorProperty(
         "Layout", "Layout",
         dtDAL::StringSelectorActorProperty::SetFuncType(this, &ButtonEvent::SetLayout),
         dtDAL::StringSelectorActorProperty::GetFuncType(this, &ButtonEvent::GetLayout),
         dtDAL::StringSelectorActorProperty::GetListFuncType(this, &ButtonEvent::GetLayoutList),
         "The Layout.", "", true);
      AddProperty(layoutProp);

      dtDAL::StringSelectorActorProperty* buttonProp =
         new dtDAL::StringSelectorActorProperty(
         "Button", "Button",
         dtDAL::StringSelectorActorProperty::SetFuncType(this, &ButtonEvent::SetButton),
         dtDAL::StringSelectorActorProperty::GetFuncType(this, &ButtonEvent::GetButton),
         dtDAL::StringSelectorActorProperty::GetListFuncType(this, &ButtonEvent::GetButtonList),
         "The Button.", "", true);
      AddProperty(buttonProp);

      // This will expose the properties in the editor and allow
      // them to be connected to ValueNodes.
      mValues.push_back(ValueLink(this, layoutProp, false, false, true, false));
      mValues.push_back(ValueLink(this, buttonProp, false, false, true, false));
   }

   /////////////////////////////////////////////////////////////////////////////
   bool ButtonEvent::UsesInstigator()
   {
      return false;
   }

   //////////////////////////////////////////////////////////////////////////
   void ButtonEvent::OnLinkValueChanged(const std::string& linkName)
   {
      if (!GetDirector()->IsLoading())
      {
         UpdateName();

         if (linkName == "Layout")
         {
            std::string layoutName = GetString("Layout");
            GUINodeManager::GetLayout(layoutName);
         }
         else if (linkName == "Event")
         {
         }
      }
   }

   ////////////////////////////////////////////////////////////////////////////////
   void ButtonEvent::UpdateName()
   {
      std::string layoutName = GetString("Layout");
      std::string buttonName = GetString("Button");

      if (layoutName.empty() && buttonName.empty())
      {
         mName.clear();
      }
      else if (buttonName.empty())
      {
         mName = "Layout: " + layoutName;
      }
      else if (layoutName.empty())
      {
         mName = "Button: " + buttonName;
      }
      else
      {
         mName = layoutName + "::" + buttonName;
      }
   }

   ////////////////////////////////////////////////////////////////////////////////
   void ButtonEvent::RefreshConnections()
   {
      if (mClickedConnection.isValid())
      {
         mClickedConnection->disconnect();
         mClickedConnection = NULL;
      }

      if (mDoubleClickedConnection.isValid())
      {
         mDoubleClickedConnection->disconnect();
         mDoubleClickedConnection = NULL;
      }

      if (mEnterConnection.isValid())
      {
         mEnterConnection->disconnect();
         mEnterConnection = NULL;
      }

      if (mLeaveConnection.isValid())
      {
         mLeaveConnection->disconnect();
         mLeaveConnection = NULL;
      }

      dtGUI::GUI* gui = GUINodeManager::GetGUI();
      if (gui)
      {
         std::string buttonName = GetString("Button");

         if (!buttonName.empty())
         {
            mClickedConnection = gui->SubscribeEvent(buttonName,
               CEGUI::Window::EventMouseClick.c_str(),
               dtGUI::GUI::Subscriber(&ButtonEvent::OnClicked, this));
            mDoubleClickedConnection = gui->SubscribeEvent(buttonName,
               CEGUI::Window::EventMouseDoubleClick.c_str(),
               dtGUI::GUI::Subscriber(&ButtonEvent::OnDoubleClicked, this));
            mEnterConnection = gui->SubscribeEvent(buttonName,
               CEGUI::Window::EventMouseEnters.c_str(),
               dtGUI::GUI::Subscriber(&ButtonEvent::OnHoverEnter, this));
            mLeaveConnection = gui->SubscribeEvent(buttonName,
               CEGUI::Window::EventMouseLeaves.c_str(),
               dtGUI::GUI::Subscriber(&ButtonEvent::OnHoverLeave, this));
         }
      }
   }

   /////////////////////////////////////////////////////////////////////////////
   void ButtonEvent::SetLayout(const std::string& value)
   {
      mLayout = value;

      UpdateName();

      if (!GetDirector()->IsLoading())
      {
         GUINodeManager::GetLayout(mLayout);
      }
   }

   /////////////////////////////////////////////////////////////////////////////
   std::string ButtonEvent::GetLayout()
   {
      return mLayout;
   }

   /////////////////////////////////////////////////////////////////////////////
   std::vector<std::string> ButtonEvent::GetLayoutList()
   {
      return GUINodeManager::GetLayoutList();
   }

   /////////////////////////////////////////////////////////////////////////////
   void ButtonEvent::SetButton(const std::string& value)
   {
      mButton = value;

      UpdateName();

      if (GetDirector()->HasStarted())
      {
         RefreshConnections();
      }
   }

   /////////////////////////////////////////////////////////////////////////////
   std::string ButtonEvent::GetButton()
   {
      return mButton;
   }

   /////////////////////////////////////////////////////////////////////////////
   std::vector<std::string> ButtonEvent::GetButtonList()
   {
      std::vector<std::string> stringList;

      CEGUI::Window* layout = GUINodeManager::GetLayout(GetString("Layout"));
      RecurseButtonList(stringList, layout);

      return stringList;
   }

   ////////////////////////////////////////////////////////////////////////////////
   void ButtonEvent::RecurseButtonList(std::vector<std::string>& buttonList, CEGUI::Window* parent)
   {
      if (!parent)
      {
         return;
      }

      size_t count = parent->getChildCount();
      for (size_t index = 0; index < count; ++index)
      {
         CEGUI::Window* child = parent->getChildAtIdx(index);
         CEGUI::ButtonBase* button = dynamic_cast<CEGUI::ButtonBase*>(child);

         if (button)
         {
            buttonList.push_back(button->getName().c_str());
         }

         RecurseButtonList(buttonList, child);
      }
   }

   ////////////////////////////////////////////////////////////////////////////////
   bool ButtonEvent::OnClicked(const CEGUI::EventArgs& e)
   {
      Trigger("Clicked", NULL, true, false);
      return true;
   }

   ////////////////////////////////////////////////////////////////////////////////
   bool ButtonEvent::OnDoubleClicked(const CEGUI::EventArgs& e)
   {
      Trigger("Double Clicked", NULL, true, false);
      return true;
   }

   ////////////////////////////////////////////////////////////////////////////////
   bool ButtonEvent::OnHoverEnter(const CEGUI::EventArgs& e)
   {
      Trigger("Hover Enter", NULL, true, false);
      return true;
   }

   ////////////////////////////////////////////////////////////////////////////////
   bool ButtonEvent::OnHoverLeave(const CEGUI::EventArgs& e)
   {
      Trigger("Hover Leave", NULL, true, false);
      return true;
   }
}