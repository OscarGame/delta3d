/*
 * Delta3D Open Source Game and Simulation Engine
 * Copyright (C) 2005, BMH Associates, Inc.
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
 * David Guthrie
 */
#include <prefix/dtdalprefix-src.h>
#include <osgDB/FileNameUtils>

#include <dtUtil/stringutils.h>
#include <dtDAL/map.h>
#include <dtDAL/actortype.h>
#include <dtDAL/enginepropertytypes.h>
#include <dtDAL/environmentactor.h>
#include <string>

namespace dtDAL 
{
   const std::string Map::MAP_FILE_EXTENSION(".xml");
   
   Map::Map(const std::string& mFileName, const std::string& name) : 
      mModified(true), mName(name) 
   {
      //mFileName requires some processing.
      SetFileName(mFileName);
      mEventManager = new MapGameEvents(*this);
   }
   
   Map::~Map() {}
   
   Map::MapGameEvents::MapGameEvents(Map& parent): GameEventManager(), mParent(parent)
   {}

   void Map::MapGameEvents::AddEvent(GameEvent& event)
   {
      GameEventManager::AddEvent(event);
      mParent.SetModified(true);
   }

   void Map::MapGameEvents::RemoveEvent(GameEvent& event)
   {
      GameEventManager::RemoveEvent(event);
      mParent.SetModified(true);
   }

   void Map::MapGameEvents::RemoveEvent(const dtCore::UniqueId& id)
   {
      GameEventManager::RemoveEvent(id);
      mParent.SetModified(true);
   }

   void Map::MapGameEvents::ClearAllEvents()
   {
      GameEventManager::ClearAllEvents();
      mParent.SetModified(true);
   }

   ActorProxy* Map::GetProxyById(const dtCore::UniqueId& id) 
   {
      std::map<dtCore::UniqueId, dtCore::RefPtr<ActorProxy> >::iterator i = mProxyMap.find(id);
      if (i != mProxyMap.end())
      {
         return i->second.get();
      }
      return NULL;
   }
   
   const ActorProxy* Map::GetProxyById(const dtCore::UniqueId& id) const 
   {
      std::map<dtCore::UniqueId, dtCore::RefPtr<ActorProxy> >::const_iterator i = mProxyMap.find(id);
      if (i != mProxyMap.end()) 
      {     
         return i->second.get();
      }
      return NULL;
   }
   
   void Map::SetFileName(const std::string& newFileName) 
   {
      //if "" is passed into the constructor is SetFileName
      //then it should be ignored.
      mFileName = newFileName;
      
      if (mFileName.empty())
         return;
      
      //see if the file already has the extension.  Note also that MAP_FILE_EXTENSION
      // has a "." but osgDB.get... doesn't return one, hence the substr(1)
      if ((osgDB::getLowerCaseFileExtension(mFileName)) != MAP_FILE_EXTENSION.substr(1))
         mFileName += MAP_FILE_EXTENSION;
   }
   
   void Map::FindProxies(std::vector<dtCore::RefPtr<ActorProxy> >& container,
                         const std::string& name,
                         const std::string& category,
                         const std::string& typeName,
                         const std::string& className,
                         PlaceableFilter placeable) 
   {
      container.clear();
      
      if (name != "" || category != "" || typeName != "" || className != "" || placeable != Either ) 
      {
         for (std::map<dtCore::UniqueId, dtCore::RefPtr<ActorProxy> >::iterator i = mProxyMap.begin();
              i != mProxyMap.end(); ++i) 
         {
            ActorProxy* ap = i->second.get();
            
            if (name == "" || WildMatch(name, ap->GetName()))
               if (MatchesSearch(*ap, category, typeName, className, placeable))
                  container.push_back(dtCore::RefPtr<ActorProxy>(ap));
         }
      } 
      else 
      {
         //return everything.
         container.reserve(mProxyMap.size());
         for (std::map<dtCore::UniqueId, dtCore::RefPtr<ActorProxy> >::iterator i = mProxyMap.begin();
              i != mProxyMap.end(); ++i) 
         {
            ActorProxy* ap = i->second.get();
            container.push_back(ap);
         }
      }
      
   }
   
   void Map::FindProxies(std::vector<dtCore::RefPtr<const ActorProxy> >& container,
                         const std::string& name,
                         const std::string& category,
                         const std::string& typeName,
                         const std::string& className,
                         PlaceableFilter placeable) const 
   {
      
      container.clear();
      
      if (name != "" || category != "" || typeName != "" || className != "" || placeable != Either) 
      {
         for (std::map<dtCore::UniqueId, dtCore::RefPtr<ActorProxy> >::const_iterator i = mProxyMap.begin();
              i != mProxyMap.end(); ++i) 
         {
            const ActorProxy* ap = i->second.get();

            if (name == "" || WildMatch(name, ap->GetName()))
               if (MatchesSearch(*ap, category, typeName, className, placeable))
                  container.push_back(ap);
         }
      } 
      else 
      {
         //return everything.
         container.reserve(mProxyMap.size());
         for (std::map<dtCore::UniqueId, dtCore::RefPtr<ActorProxy> >::const_iterator i = mProxyMap.begin();
              i != mProxyMap.end(); ++i) 
         {
            const ActorProxy* ap = i->second.get();
            container.push_back(ap);
         }
      }
   }

   bool Map::MatchesSearch(const ActorProxy& actorProxy,
                           const std::string& category,
                           const std::string& typeName,
                           const std::string& className,
                           PlaceableFilter placeable) const
   {


      if (!className.empty() && !actorProxy.IsInstanceOf(className))
         return false;

      if (!typeName.empty() || !category.empty())
      {
         const ActorType* actorType = &actorProxy.GetActorType();         
         bool matches = false;
         
         while (!matches && actorType != NULL)
         {
            bool nameMatches = typeName.empty() || actorType->GetName() == typeName;       
            const std::string& actualCategory = actorType->GetCategory();      
            bool catMatches = false; 
            
            if (actualCategory.size() >= category.size())
            {
               //The category needs to be either the whole name or be a substring up to a '.'
               catMatches = category.empty() ||
                            (actualCategory.substr(0, category.size()) == category
                            && (actualCategory.size() == category.size() || actualCategory[category.size()] == '.'));
            }
            
            matches = catMatches && nameMatches;
            actorType = actorType->GetParentActorType();
         }
         
         if (!matches)
            return false;
      }
      
      if (placeable == Placeable && !actorProxy.IsPlaceable())
         return false;
      else if (placeable == NotPlaceable && actorProxy.IsPlaceable())
         return false;

      return true;

   }

   void Map::AddProxy(ActorProxy& proxy) 
   {
      if (mProxyMap.insert(std::make_pair(proxy.GetId(), dtCore::RefPtr<ActorProxy>(&proxy))).second) 
      {
         const std::set<std::string>& hierarchy = proxy.GetClassHierarchy();
         mProxyActorClasses.insert(proxy.GetClassName());
         mProxyActorClasses.insert(hierarchy.begin(), hierarchy.end());
         mModified = true;
      }
   }

   bool Map::RemoveProxy(const ActorProxy& proxy)
   {
      //This needs to be faster.
      std::map<dtCore::UniqueId, dtCore::RefPtr<ActorProxy> >::iterator i = mProxyMap.find(proxy.GetId());
      if (i != mProxyMap.end()) 
      {
         mModified = true;

         //notify proxy it is being removed from map
         proxy.OnRemove();
         std::vector<dtCore::RefPtr<ActorProxy> > proxies;

         GetAllProxies(proxies);
         for(unsigned int j = 0; j < proxies.size(); j++)
         {
            std::vector<ActorProperty*> props;
            proxies[j]->GetPropertyList(props);
            for(unsigned int k = 0; k < props.size(); k++)
            {
               if(props[k]->GetDataType() == DataType::ACTOR)
               {
                  ActorActorProperty *aap = static_cast<ActorActorProperty*>(props[k]);
                  if(aap->GetValue() == &proxy)
                     aap->SetValue(NULL);
               }
                  
            }
         }
         mProxyMap.erase(i);
         return true;
      }
      return false;
   }

   void Map::ClearProxies() 
   {
      mProxyMap.clear();
      mProxyActorClasses.clear();
   }

   void Map::RebuildProxyActorClassSet() const 
   {
      mProxyActorClasses.clear();
      for (std::map<dtCore::UniqueId, dtCore::RefPtr<ActorProxy> >::const_iterator i = mProxyMap.begin(); i != mProxyMap.end(); ++i) 
      {
         const ActorProxy& proxy = *(i->second);
         const std::set<std::string>& hierarchy = proxy.GetClassHierarchy();
         mProxyActorClasses.insert(proxy.GetClassName());
         mProxyActorClasses.insert(hierarchy.begin(), hierarchy.end());
      }
   }

   void Map::InsertLibrary(unsigned pos, const std::string& name, const std::string& version) 
   {
      std::map<std::string,std::string>::iterator old = mLibraryVersionMap.find(name);

      bool alreadyExists;
      if (old != mLibraryVersionMap.end()) 
      {
         old->second = version;
         alreadyExists = true;
      } 
      else 
      {
         mLibraryVersionMap.insert(make_pair(name,version));
         alreadyExists = false;
      }

      for (std::vector<std::string>::iterator i = mLibraryOrder.begin(); i != mLibraryOrder.end(); ++i) 
      {
         if (*i == name) 
         {
            mLibraryOrder.erase(i);
            break;
         }
      }

      if (pos < mLibraryOrder.size())
         mLibraryOrder.insert(mLibraryOrder.begin() + pos, name);
      else
         mLibraryOrder.push_back(name);

      mModified = true;
   }

   void Map::AddLibrary(const std::string& name, const std::string& version) 
   {
      InsertLibrary(mLibraryOrder.size(), name, version);
   }

   bool Map::RemoveLibrary(const std::string& name) 
   {

      std::map<std::string, std::string>::iterator oldMap = mLibraryVersionMap.find(name);

      if (oldMap != mLibraryVersionMap.end())
         mLibraryVersionMap.erase(oldMap);
      else
         return false;

      for (std::vector<std::string>::iterator i = mLibraryOrder.begin(); i != mLibraryOrder.end(); ++i) 
      {
         if (*i == name) 
         {
            mLibraryOrder.erase(i);
            break;
         }
      }

      mModified = true;
      return true;
   }

   void Map::ClearModified() 
   {
      mModified = false;
      mSavedName = mName;
      mMissingActorTypes.clear();
      mMissingLibraries.clear();
   }

   void Map::AddMissingActorTypes(const std::set<std::string>& types) 
   {
      mMissingActorTypes.insert(types.begin(), types.end());
   }

   void Map::AddMissingLibraries(const std::vector<std::string>& libs) 
   {
      mMissingLibraries.insert(mMissingLibraries.end(), libs.begin(), libs.end());
   }

   bool Map::WildMatch(const std::string& sWild, const std::string& sString) 
   {
      char* WildChars = new char[sWild.size() + 1];
      char* str = new char[sString.size() + 1];
      strcpy(WildChars, sWild.c_str());
      strcpy(str, sString.c_str());
      bool result = dtUtil::Match(WildChars, str);
      delete[] WildChars;
      delete[] str;
      return result;
   }
    
   GameEventManager& Map::GetEventManager()
   {
      return *mEventManager;
   }
   
   const GameEventManager& Map::GetEventManager() const
   {
      return *mEventManager;
   }
   
   void Map::SetEnvironmentActor(ActorProxy *envActor)
   {
      if(envActor == NULL)
      {
         RemoveProxy(*mEnvActor);
         mEnvActor = NULL;
         return;
      }

      IEnvironmentActor *ea = dynamic_cast<IEnvironmentActor*>(envActor->GetActor());
      if(ea == NULL)
      {
         LOG_ERROR("The actor specified is not an EnvironmentActor. Ignoring.");
         return;
      }
      mEnvActor = envActor;
      AddProxy(*mEnvActor);
   }
}
