/*//-------------------------------------------------------------------------------
*  easer.h
*
*  Header file for Easer
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
#ifndef EASER_H
#define EASER_H


#include <inttypes.h>
#include <stdbool.h>

#include "easerTypes.h"


//--------------------------------------------------------
// easer (linear only for now)
class Easer
{
public:
  Easer();
  Easer(easingFunc);

  void setEasingFunc(easingFunc func) {m_easingFunc = func;};
  uint8_t getEasingFunc() {return m_easingFunc;};

  void setEasingType(easingType _type) {m_easingType = _type;};
  uint8_t getEasingType() {return m_easingType;};

  void setDuration(uint16_t dur) {m_duration = dur;};
  uint16_t getDuration() {return m_duration;};

  void setLoop(easingLoop _loop) {m_loop = _loop;};
  uint8_t getLoop() {return m_loop;};
  
  void rewind();

  bool update(unsigned long, double*);
  
private:
  
  double calcCurrent(long);
  
  uint8_t      m_easingFunc;
  uint8_t      m_easingType;
  uint16_t     m_duration; // in milliseconds (max 65536 ms)
  
  uint8_t      m_loop;
  
  unsigned long  m_startTime;
};


#endif
