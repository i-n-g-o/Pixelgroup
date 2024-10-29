/*//-------------------------------------------------------------------------------
*  Pixelgroup.cpp
*
*  Pixelgroup class with all abilities
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
#include "Pixelgroup.h"

//--------------------------------------------------------
// constructor, deconstructor
Pixelgroup::Pixelgroup() : PixelgroupBase(), ColorEaser(), Strobe()
  ,m_isFlickering(false)
{
}


Pixelgroup::Pixelgroup(uint8_t count, ...) : PixelgroupBase(), ColorEaser(), Strobe()
  ,m_isFlickering(false)
{
  va_list args;
  va_start(args, count);

  // setup pixels
  v_setPixels(count, args);
  
  va_end(args);
}



//--------------------------------------------------------
void Pixelgroup::setStrobing(bool b)
{
  Strobe::setStrobing(b);

  setDirty(true);
}


//--------------------------------------------------------
void Pixelgroup::update(unsigned long _now)
{
  // EASING
  bool d = ColorEaser::update(_now, getColor());  
  if (d) setDirty(true);
  
  // STROBE
  bool c = Strobe::update(_now);
  if (c) setDirty(true);
}


//--------------------------------------------------------
void Pixelgroup::paint(PixelWriterInterface& writer)
{
  // safeties
  if (!isDirty() && !m_isFlickering) return;
  if (getPixels() == 0 || getSize() == 0) return;
  
  
  bool strobeState = !Strobe::isStrobing() || Strobe::getStrobeState();
  bool flickeringDone = false;
  
  
  // mark as clean
  setDirty(false);
  
  
  for (uint8_t i=0; i<getSize(); i++) {
  
    uint8_t pixelIndex = getPixels()[i];
  
    if (m_isFlickering > 0 &&
      !flickeringDone)
    {
#ifdef ESP8266
      if ((rand() % 100) > 80) {
#else
      if ((random() % 100) > 80) {
#endif
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





