/*//-------------------------------------------------------------------------------
*  pixelwriter.h
*
*  Header file for PixelWriter
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

#ifndef PIXEL_WRITER_H
#define PIXEL_WRITER_H

#include "pixelWriterInterface.h"

// 'type' flags for LED pixels (third parameter to constructor):
#define PXW_RGB     0x00 // Wired for RGB data order
#define PXW_GRB     0x01 // Wired for GRB data order
#define PXW_BRG     0x04

class Color;

//--------------------------------------------------------
// pixel writer
// holds pointer to pixel array
class PixelWriter : public PixelWriterInterface
{
public:  
  PixelWriter(uint8_t* _pixels, uint8_t _count, uint8_t order=PXW_GRB);
  
  virtual void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
  virtual void setPixelColor(uint16_t n, uint32_t c);

  void setShowFunc( void (*)(void) );
  bool isShowFunc() {return (showFunc>0);};
  void show();

private:
  uint8_t* m_pixels;
  uint8_t  m_pixelCount;
   
  uint8_t rOffset;       // Index of red byte within each 3-byte pixel
  uint8_t gOffset;       // Index of green byte
  uint8_t bOffset;       // Index of blue byte

  // callbacks
  void (*showFunc)(void);  
};


#endif
