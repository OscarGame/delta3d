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
 */
 
#ifndef lightmanager_h__
#define lightmanager_h__

#include <dtInspectorQt/imanager.h>
#include <QtCore/QObject>
#include <dtCore/observerptr.h>
#include <dtCore/light.h>
#include <dtCore/positionallight.h>
#include <dtCore/spotlight.h>

namespace Ui
{
   class InspectorWidget;
}

namespace dtInspectorQt
{
   ///Handles the properties of dtCore::Light
   class LightManager : public IManager
   {
      Q_OBJECT

   public:
      LightManager(Ui::InspectorWidget &ui);
      virtual ~LightManager();

      virtual void OperateOn(dtCore::Base* b);

   protected slots:
      // General Light slots
      void OnEnabled(int checked);
      void OnLightNumberChanged(int newValue);
      void OnModeChanged(const QString& newValue);
      void OnAmbientChanged(double newValue);
      void OnAmbientColorChooserClicked();
      void OnDiffuseChanged(double newValue);
      void OnDiffuseColorChooserClicked();
      void OnSpecularChanged(double newValue);
      void OnSpecularColorChooserClicked();

      // Positional light slots
      void OnAttenuationChanged(double newValue);

      // Spotlight slots
      void OnSpotCutoffChanged(double newValue);
      void OnSpotExponentChanged(double newValue);

   private:
      void Update();
      void UpdateGeneralLightProperties();
      void UpdatePositionalLightProperties();
      void UpdateSpotLightProperties();

      Ui::InspectorWidget* mUI;
      dtCore::ObserverPtr<dtCore::Light> mOperateOn;
      dtCore::ObserverPtr<dtCore::PositionalLight> mPositionalLight;
      dtCore::ObserverPtr<dtCore::SpotLight> mSpotLight;
   };
}  
#endif //lightmanager_h__
