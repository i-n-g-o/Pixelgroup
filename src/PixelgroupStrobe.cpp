/*//-------------------------------------------------------------------------------
*  PixelgroupStrobe.cpp
*
*  Class PixelgroupStrobe. A Pixelgroup with strobing ability
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
#include "PixelgroupStrobe.h"


//--------------------------------------------------------
// constructor, deconstructor
PixelgroupStrobe::PixelgroupStrobe() : PixelgroupBase(), Strobe()
{
}


PixelgroupStrobe::PixelgroupStrobe(uint8_t count, ...) : PixelgroupBase(), Strobe()
{
  va_list args;
  va_start(args, count);

  // setup pixels
  v_setPixels(count, args);
  
  va_end(args);
}



//--------------------------------------------------------
void PixelgroupStrobe::setStrobing(bool b)
{
  Strobe::setStrobing(b);

  setDirty(true);
}


//--------------------------------------------------------
// update with time
void PixelgroupStrobe::update(unsigned long _now)
{
  bool changed = Strobe::update(_now);
  
  if (changed) setDirty(true);
}


//--------------------------------------------------------
void PixelgroupStrobe::paint(PixelWriterInterface& writer)
{
  // safeties
  if (!isDirty()) return;
  if (getPixels() == 0 || getSize() == 0) return;

  bool strobeState = !Strobe::isStrobing() || Strobe::getStrobeState();
  
  // mark as clean
  setDirty(false);
  
  
  for (uint8_t i=0; i<getSize(); i++) {
  
    uint8_t pixelIndex = getPixels()[i];
  
    // set pixel color (or black)
    // sets color in pixelWriter
    // sets pixelwriter to dirty
    
    if (!strobeState) {
      writer.setPixelColor(pixelIndex, 0, 0, 0);
    } else {
      writer.setPixelColor((uint8_t)pixelIndex, getR(), getG(), getB());
    }
  }
}





