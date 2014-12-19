/*//-------------------------------------------------------------------------------
*  Pixelgroup.cpp
*
*  Pixelgroup class with all abilities
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
#include "Pixelgroup.h"


//--------------------------------------------------------
// constructor, deconstructor
Pixelgroup::Pixelgroup() : PixelgroupBase(), PixelgroupE(), PixelgroupS()
  ,m_isFlickering(false)
{
}


Pixelgroup::Pixelgroup(uint8_t count, ...) : PixelgroupBase(), PixelgroupE(), PixelgroupS()
  ,m_isFlickering(false)
{
  va_list args;
  va_start(args, count);

  // setup pixels
  v_setPixels(count, args);
  
  va_end(args);
}



//--------------------------------------------------------
void Pixelgroup::setStrobing(boolean b)
{
  PixelgroupS::setStrobing(b);

  setDirty(true);
}


//--------------------------------------------------------
void Pixelgroup::tick()
{
  unsigned long _now = millis();  
  tick(_now);
}


void Pixelgroup::tick(unsigned long _now)
{
  // EASING
  boolean d = PixelgroupE::tick(_now, getColor());  
  setDirty(d);
  
  // STROBE
  boolean c = PixelgroupS::tick(_now);
  if (c) setDirty(c);
}


//--------------------------------------------------------
void Pixelgroup::paint(PixelWriterInterface& writer)
{
  // safeties
  if (!isDirty() && !m_isFlickering) return;
  if (getPixels() == 0 || getSize() == 0) return;
  
  
  boolean strobeState = getStrobeState();
  boolean flickeringDone = false;
  
  
  // mark as clean
  setDirty(false);
  
  
  for (uint8_t i=0; i<getSize(); i++) {
  
    uint8_t pixelIndex = getPixels()[i];
  
    if (m_isFlickering > 0 &&
      !flickeringDone)
    {
      if (random(100) > 80) {
        strobeState &= 0;
        flickeringDone = true;
        m_isFlickering--;
    
        // mark as dirty to redraw on next cycle
        setDirty(true);
      }    
    }
  
    // set pixel color (or black)
    // sets color in pixelWriter
    // sets pixelwriter to dirty
    if (!strobeState || flickeringDone) {
      writer.setPixelColor(pixelIndex, 0, 0, 0);
    } else { 
      writer.setPixelColor((uint8_t)pixelIndex, getR(), getG(), getB());
    }
  }
}





