/*//-------------------------------------------------------------------------------
*  PixelgroupEaser.cpp
*
*  PixelgroupEaser Class. A Pixelgroup which can do a color ease
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
#include "PixelgroupEaser.h"


//--------------------------------------------------------
// constructor, deconstructor
PixelgroupEaser::PixelgroupEaser() : PixelgroupBase(), PixelgroupE()
{}


PixelgroupEaser::PixelgroupEaser(uint8_t count, ...) : PixelgroupBase(), PixelgroupE()
{
  va_list args;
  va_start(args, count);

  // setup pixels
  v_setPixels(count, args);
  
  va_end(args);
}


//--------------------------------------------------------
void PixelgroupEaser::tick()
{
  unsigned long _now = millis();  
  tick(_now);
}


void PixelgroupEaser::tick(unsigned long _now)
{
  boolean d = PixelgroupE::tick(_now, getColor());  
  setDirty(d);
}
