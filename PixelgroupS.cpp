/*//-------------------------------------------------------------------------------
*  PixelgroupS.cpp
*
*  Class PixelgroupS. adds on/off switch to Strobe
*  
*  written by: Ingo Randolf - 2014
*
*
*  This library is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*
*  This library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
//-------------------------------------------------------------------------------*/
#include "PixelgroupS.h"


//--------------------------------------------------------
// constructor, deconstructor
PixelgroupS::PixelgroupS() : Strobe()
{
}



void PixelgroupS::setStrobing(boolean b)
{
  m_isStrobing = b;
  Strobe::setStrobeState(false);
}


//--------------------------------------------------------
boolean PixelgroupS::tick()
{
  unsigned long _now = millis();  
  return tick(_now);
}


boolean PixelgroupS::tick(unsigned long _now)
{
  boolean changed = false;
  
  // tick strobe
  if (m_isStrobing) {  
    changed = Strobe::tick(_now);
  }
  
  return changed;
}