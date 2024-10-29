/*//-------------------------------------------------------------------------------
*  PixelgroupEaser.cpp
*
*  PixelgroupEaser Class. A Pixelgroup which can do a color ease
*  
*  This file is part of Pixelgroup library.
*  https://github.com/i-n-g-o/Pixelgroup
*
*  Copyright (c) Ingo Randolf, 2014
*
*  This Source Code Form is subject to the terms of the Mozilla Public
*  License, v. 2.0. If a copy of the MPL was not distributed with this
*  file, You can obtain one at https://mozilla.org/MPL/2.0/.
//-------------------------------------------------------------------------------*/
#include "PixelgroupEaser.h"


//--------------------------------------------------------
// constructor, deconstructor
PixelgroupEaser::PixelgroupEaser() : PixelgroupBase(), ColorEaser()
{}


PixelgroupEaser::PixelgroupEaser(uint8_t count, ...) : PixelgroupBase(), ColorEaser()
{
  va_list args;
  va_start(args, count);

  // setup pixels
  v_setPixels(count, args);
  
  va_end(args);
}


//--------------------------------------------------------
void PixelgroupEaser::update(unsigned long _now)
{
  bool d = ColorEaser::update(_now, getColor());  
  if (d) setDirty(true);
}