/*
 * Delta3D Open Source Game and Simulation Engine
 * Copyright (C) 2009 MOVES Institute
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
 * Author: Eric R. Heine
 */

#include <dtDirectorGUINodes/getwidgetproperty.h>
#include <dtDirectorGUINodes/guinodemanager.h>

#include <dtDAL/stringactorproperty.h>
#include <dtDAL/stringselectoractorproperty.h>

#include <dtGUI/gui.h>
#include <CEGUI/CEGUIWindow.h>
#include <CEGUI/CEGUIExceptions.h>

#include <dtDirector/director.h>

namespace dtDirector
{
   /////////////////////////////////////////////////////////////////////////////
   GetWidgetProperty::GetWidgetProperty()
      : ActionNode()
   {
      AddAuthor("Eric R. Heine");
   }

   /////////////////////////////////////////////////////////////////////////////
   GetWidgetProperty::~GetWidgetProperty()
   {
   }

   /////////////////////////////////////////////////////////////////////////////
   void GetWidgetProperty::Init(const NodeType& nodeType, DirectorGraph* graph)
   {
      ActionNode::Init(nodeType, graph);

      mOutputs.push_back(OutputLink(this, "Failed", "Activates if Widget could not be found."));
   }

   /////////////////////////////////////////////////////////////////////////////
   void GetWidgetProperty::OnFinishedLoading()
   {
      GUINodeManager::GetLayout(GetString("Layout"));
   }

   /////////////////////////////////////////////////////////////////////////////
   void GetWidgetProperty::BuildPropertyMap()
   {
      ActionNode::BuildPropertyMap();

      dtDAL::StringSelectorActorProperty* layoutProp = new dtDAL::StringSelectorActorProperty(
         "Layout", "Layout",
         dtDAL::StringSelectorActorProperty::SetFuncType(this, &GetWidgetProperty::SetLayout),
         dtDAL::StringSelectorActorProperty::GetFuncType(this, &GetWidgetProperty::GetLayout),
         dtDAL::StringSelectorActorProperty::GetListFuncType(this, &GetWidgetProperty::GetLayoutList),
         "The Layout.", "", true);
      AddProperty(layoutProp);

      dtDAL::StringSelectorActorProperty* widgetProp = new dtDAL::StringSelectorActorProperty(
         "Widget", "Widget",
         dtDAL::StringSelectorActorProperty::SetFuncType(this, &GetWidgetProperty::SetWidget),
         dtDAL::StringSelectorActorProperty::GetFuncType(this, &GetWidgetProperty::GetWidget),
         dtDAL::StringSelectorActorProperty::GetListFuncType(this, &GetWidgetProperty::GetWidgetList),
         "The Widget to set the text on.", "", true);
      AddProperty(widgetProp);

      dtDAL::StringActorProperty* propertyProp = new dtDAL::StringActorProperty(
         "Property", "Property",
         dtDAL::StringActorProperty::SetFuncType(this, &GetWidgetProperty::SetProperty),
         dtDAL::StringActorProperty::GetFuncType(this, &GetWidgetProperty::GetProperty),
         "The property to set.");
      AddProperty(propertyProp);

      mpValueProp = new dtDAL::StringActorProperty(
         "Value", "Value",
         dtDAL::StringActorProperty::SetFuncType(this, &GetWidgetProperty::SetValue),
         dtDAL::StringActorProperty::GetFuncType(this, &GetWidgetProperty::GetValue),
         "The value to set.");

      // This will expose the properties in the editor and allow
      // them to be connected to ValueNodes.
      mValues.push_back(ValueLink(this, layoutProp, false, false, true, false));
      mValues.push_back(ValueLink(this, widgetProp, false, false, true, false));
      mValues.push_back(ValueLink(this, propertyProp));
      mValues.push_back(ValueLink(this, mpValueProp, true, true, false));
   }

   /////////////////////////////////////////////////////////////////////////////
   bool GetWidgetProperty::Update(float simDelta, float delta, int input, bool firstUpdate)
   {
      CEGUI::Window* layout = GUINodeManager::GetLayout(GetString("Layout"));
      if (!layout)
      {
         ActivateOutput("Failed");
         return false;
      }

      dtGUI::GUI* gui = GUINodeManager::GetGUI();
      if (gui)
      {
         std::string widgetName = GetString("Widget");
         std::string prop = GetString("Property");

         CEGUI::Window* widget = gui->GetWidget(widgetName);
         if (widget)
         {
            try
            {
               SetString(widget->getProperty(prop).c_str(), "Value");
            }
            catch (CEGUI::UnknownObjectException e)
            {
               LOG_ERROR("There is no property named " + prop);
            }
         }
      }

      // Fire the "Out" link
      return ActionNode::Update(simDelta, delta, input, firstUpdate);
   }

   ////////////////////////////////////////////////////////////////////////////////
   void GetWidgetProperty::UpdateName()
   {
      std::string layoutName = GetString("Layout");
      std::string widgetName = GetString("Widget");
      std::string prop = GetString("Property");

      if (layoutName.empty())
      {
         mName.clear();
      }
      else
      {
         mName = "Layout: " + layoutName;
      }

      if (!widgetName.empty())
      {
         if (!mName.empty())
         {
            mName += "::";
         }
         mName += widgetName;
      }

      if (!prop.empty())
      {
         if (!mName.empty())
         {
            mName += " - ";
         }
         mName += prop;
      }
   }

   //////////////////////////////////////////////////////////////////////////
   void GetWidgetProperty::OnLinkValueChanged(const std::string& linkName)
   {
      if (!GetDirector()->IsLoading())
      {
         if (linkName == "Layout")
         {
            std::string layoutName = GetString("Layout");
            GUINodeManager::GetLayout(layoutName);

            UpdateName();
         }
         else if (linkName == "Widget" || linkName == "Text")
         {
            UpdateName();
         }
      }
   }

   /////////////////////////////////////////////////////////////////////////////
   void GetWidgetProperty::SetLayout(const std::string& value)
   {
      mLayout = value;

      UpdateName();

      if (!GetDirector()->IsLoading())
      {
         GUINodeManager::GetLayout(mLayout);
      }
   }

   /////////////////////////////////////////////////////////////////////////////
   std::string GetWidgetProperty::GetLayout() const
   {
      return mLayout;
   }

   /////////////////////////////////////////////////////////////////////////////
   std::vector<std::string> GetWidgetProperty::GetLayoutList()
   {
      return GUINodeManager::GetLayoutList();
   }

   /////////////////////////////////////////////////////////////////////////////
   void GetWidgetProperty::SetWidget(const std::string& value)
   {
      mWidget = value;

      UpdateName();
   }

   /////////////////////////////////////////////////////////////////////////////
   std::string GetWidgetProperty::GetWidget() const
   {
      return mWidget;
   }

   /////////////////////////////////////////////////////////////////////////////
   std::vector<std::string> GetWidgetProperty::GetWidgetList()
   {
      std::vector<std::string> list;
      RecurseWidgetList(list, GUINodeManager::GetLayout(GetString("Layout")));
      return list;
   }

   ////////////////////////////////////////////////////////////////////////////////
   void GetWidgetProperty::RecurseWidgetList(std::vector<std::string>& widgetList, CEGUI::Window* parent)
   {
      if (!parent)
      {
         return;
      }

      size_t count = parent->getChildCount();
      for (size_t index = 0; index < count; ++index)
      {
         CEGUI::Window* child = parent->getChildAtIdx(index);

         if (child)
         {
            widgetList.push_back(child->getName().c_str());
         }

         RecurseWidgetList(widgetList, child);
      }
   }

   /////////////////////////////////////////////////////////////////////////////
   void GetWidgetProperty::SetProperty(const std::string& value)
   {
      mProperty = value;

      UpdateName();
   }

   /////////////////////////////////////////////////////////////////////////////
   std::string GetWidgetProperty::GetProperty() const
   {
      return mProperty;
   }

   /////////////////////////////////////////////////////////////////////////////
   void GetWidgetProperty::SetValue(const std::string& value)
   {
   }

   /////////////////////////////////////////////////////////////////////////////
   std::string GetWidgetProperty::GetValue() const
   {
      return "";
   }
}

////////////////////////////////////////////////////////////////////////////////