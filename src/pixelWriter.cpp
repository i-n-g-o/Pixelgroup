/*//-------------------------------------------------------------------------------
*  Pixelwriter.cpp
*
*  Pixelwriter which satisfies PixelWriterInterface
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

#include "pixelWriter.h"
#include "color.h"

PixelWriter::PixelWriter(uint8_t* pixels, uint8_t pixelCount, uint8_t order) :
  m_pixels(pixels)
  ,m_pixelCount(pixelCount)
  ,showFunc(0)
  ,rOffset(1)
  ,gOffset(0)
  ,bOffset(2)
{
  setDirty(true);
  
  if(order & PXW_RGB) {
    rOffset = 0;
    gOffset = 1;
    bOffset = 2;
  } else if (order & PXW_BRG) {
    rOffset = 1;
    gOffset = 2;
    bOffset = 0;
  }
}



void PixelWriter::setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b)
{
  if(n < m_pixelCount) {
    uint8_t *p = &m_pixels[n * 3];

    // set pixels
    p[rOffset] = r;
    p[gOffset] = g;
    p[bOffset] = b;

    setDirty(true);
  }

}


void PixelWriter::setPixelColor(uint16_t n, uint32_t c)
{
  if(n < m_pixelCount) {
    uint8_t *p = &m_pixels[n * 3];
    
    // set pixels
    p[rOffset] = (uint8_t)(c >> 16); // Red
    p[gOffset] = (uint8_t)(c >>  8); // Green
    p[bOffset] = (uint8_t)c;     // Blue
    
    setDirty(true);
  }
  
}



void PixelWriter::setShowFunc( void (*function)(void) )
{
  showFunc = function;
}


void PixelWriter::show()
{
  if (isDirty() && showFunc != 0) {
    showFunc();
    setDirty(false);
  }
}