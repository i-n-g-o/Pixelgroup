/*//-------------------------------------------------------------------------------
*  PixelgropuE.cpp
*
*  Easer funtionality for Pixelgroup Easer
*  turn easing on/off
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
#include "PixelgroupE.h"


//--------------------------------------------------------
// constructor, deconstructor
PixelgroupE::PixelgroupE() : m_isEasing(false)
{}


boolean PixelgroupE::tick(Color& color)
{
  unsigned long _now = millis();  
  return tick(_now, color);
}


//--------------------------------------------------------
boolean PixelgroupE::tick(unsigned long _now, Color& color)
{
  boolean dirty = false;
  // EASING
  if (m_isEasing) {
      m_isEasing = ColorEaser::tick(_now, color);
      dirty = true;
  }
  
  return dirty;
}
