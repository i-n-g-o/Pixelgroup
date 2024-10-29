/*//-------------------------------------------------------------------------------
*  PixelgroupBase.h
*
*  Header file for Pixelgroup Base Class
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
#ifndef PIXELGROUP_BASE_H
#define PIXELGROUP_BASE_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>


#include "pixelWriter.h"
#include "pixelWriterInterface.h"

#include "color.h"


//--------------------------------------------------------
// pixelgroup base. most simple. just set color
class PixelgroupBase
{
public:
  
  PixelgroupBase();
  PixelgroupBase(uint8_t count, ...);
  ~PixelgroupBase();
  
  
  void setPixels(uint8_t count, ...);
  void addPixel(uint8_t p);
  void removePixel(uint8_t p);
  void clear();
  
  uint8_t* getPixels() {return m_pixels;};
  uint8_t getSize() {return m_pixelLength;};
  uint8_t getPixelIndex(uint8_t);
  
  void setRGB(Color&);
  void setRGB(uint8_t, uint8_t, uint8_t);
  Color& getColor();
  
  uint8_t getR() {return m_color.getR();};
  uint8_t getG() {return m_color.getG();};
  uint8_t getB() {return m_color.getB();};
  
  bool isDirty() {return m_dirty;};
  void setDirty(bool state) {m_dirty = state;};
  
  void paint(PixelWriterInterface&);
  
  
protected:
  void v_setPixels(uint8_t count, va_list args);


private:  
  // array of pixel ids
  uint8_t*       m_pixels;
  uint8_t        m_pixelLength;
  
  // pixelgroup colors
  Color           m_color;

  // dirtyflag
  bool        m_dirty;
  
};

#endif
