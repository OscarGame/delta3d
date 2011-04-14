/* -*-c++-*-
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
 * Matthew W. Campbell
 * David Guthrie
 */

#ifndef DELTA_NAMED_DOUBLE_PARAMETER
#define DELTA_NAMED_DOUBLE_PARAMETER

#include <dtDAL/namedpodparameter.h>

namespace dtDAL
{
   /**
     * @class DoubleMessageParameter
     */
   class DT_DAL_EXPORT NamedDoubleParameter: public NamedPODParameter<double>
   {
      public:
         NamedDoubleParameter(const dtUtil::RefString& name, double defaultValue = 0.0, bool isList = false);

         virtual void SetFromProperty(const dtDAL::ActorProperty& property);
         virtual void ApplyValueToProperty(dtDAL::ActorProperty& property) const;

      protected:
         virtual ~NamedDoubleParameter();
   };
}

#endif //DELTA_NAMED_DOUBLE_PARAMETER