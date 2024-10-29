/*//-------------------------------------------------------------------------------
*  PixelWriterInterface.h
*
*  Interface for PixelWriter
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

#ifndef PIXEL_WRITER_INTERFACE_H
#define PIXEL_WRITER_INTERFACE_H

#include <inttypes.h>
#include <stdbool.h>

//--------------------------------------------------------
// a pixel writer interface
class PixelWriterInterface
{
public:
  virtual void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b) = 0;
  virtual void setPixelColor(uint16_t n, uint32_t c) = 0;
  
  virtual void show() = 0;
  
  void setDirty(bool state) {m_dirty = state;};
  bool isDirty() {return m_dirty;};
  
private:
  bool     m_dirty;
  
};


#endif
