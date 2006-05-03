#include <tests/dtGUI/GUIApp.h>
#include <tests/dtGUI/GUIManager.h>
#include <dtGUI/scriptmodule.h>
#include <dtCore/globals.h>
#include <string>

using namespace dtTest;

GUIApp::GUIApp() : BaseClass(),
   mGUIManager(new dtGUI::GUIManager()),
   mScriptModule(new dtGUI::ScriptModule())
{
   // should only need this for delta .xsd files
   std::string deltadata( dtCore::GetDeltaRootPath() );

   // need this for gui .xsd files
   std::string deltagui( dtCore::GetDeltaDataPathList()+"/gui" );

   dtCore::SetDataFilePathList( deltadata + ";" + deltagui );
}

GUIApp::~GUIApp()
{
   ///\todo shutdown the GUI system when CEUIDrawable stops calling delete on the damn thing.
   //mGUIManager->ShutdownGUI();

   ///\todo do not leak the scriptmodule
   //delete mScriptModule;
}

void GUIApp::Config()
{
   BaseClass::Config();

   mGUIManager->InitializeGUI( GetWindow(), mScriptModule );
}

dtGUI::GUIManager* GUIApp::GetGUIManager()
{
   return mGUIManager.get();
}

dtGUI::ScriptModule* GUIApp::GetScriptModule()
{
   return mScriptModule;
}

