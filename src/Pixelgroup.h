/*//-------------------------------------------------------------------------------
*  Pixelgroup.h
*
*  Header file for Pixelgroup
*  
*  written by: Ingo Randolf - 2014
*
*
*  Pixelgroup is a library to group pixels in a LED-strip.
*  It can be used together with a pixel-strip library like Adafruit_NeoPixel
*  or Adafruit_WS2801, but can be used for any kind of backend.
*  The PixelWriter class can be used to write into a uint8_t array.
*  The PixelWriterInterface can be used to subclass existing pixelstrip
*  writers or to build your own writer.
*
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
#ifndef PIXELGROUP_H
#define PIXELGROUP_H

#include <stdarg.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>


#include "PixelgroupBase.h"
#include "colorEaser.h"
#include "strobe.h"
#include "PixelgroupEaserInterface.h"
#include "PixelgroupStrobeInterface.h"


/*
*  TODO
- bug in easer with bounce!?
- flickermode needed?
*
*/


typedef enum {
  FLICKER_BLACK = 0,
  FLICKER_COLOR,
  
  FLICKER_MAX
} flickerMode;


//--------------------------------------------------------
// a pixelgroup which can: ease, strobe, flicker
class Pixelgroup : 
  public PixelgroupBase,
  public ColorEaser,
  public Strobe,
  public PixelgroupEaserInterface,
  public PixelgroupStrobeInterface
{
public:
  
  Pixelgroup();
  Pixelgroup(uint8_t count, ...);

  
  void setFlicker(uint8_t num) {m_isFlickering = num;};
  bool isFlicker() {return m_isFlickering;};
//  void setFlickerMode(uint8_t mode) {m_flickerMode = mode;};
//  uint8_t getFlickerMode() {return m_flickerMode;};
  
  
  // satisfy interfaces
  
  // Pixelgroup strobe interface
  void setStrobing(bool b);
  bool isStrobing() {return Strobe::isStrobing();};
  
  void paint(PixelWriterInterface&);
  
  // Pixelgroup strobe interface
  // Pixelgroup easer interface
  void update(unsigned long _now);
  

private:
  
  // flicker
  uint8_t        m_isFlickering;
//  uint8_t        m_flickerMode;

};

#endif
