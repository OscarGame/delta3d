#ifndef __ACTION_ACTOR_PROXY_H__
#define __ACTION_ACTOR_PROXY_H__

#include <dtCore/deltadrawable.h>
#include <dtCore/plugin_export.h>
#include <dtABC/action.h>
#include <dtCore/actorproxy.h>


/* 
* Delta3D Open Source Game and Simulation Engine 
* Copyright (C) 2004-2005 MOVES Institute 
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
* Bradley Anderegg
*/

namespace dtActors
{


   class DT_PLUGIN_EXPORT ActionActorProxy: public dtCore::BaseActorObject
   {

   public:
      ActionActorProxy(){SetClassName("dtABC::Action");}

      /*virtual*/ void BuildPropertyMap();

    protected:

      virtual ~ActionActorProxy() {}

   };



}//namespace dtActors

#endif //__ACTION_ACTOR_PROXY_H__

