/*//-------------------------------------------------------------------------------
*  easer.cpp
*
*  Easer Class
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

#include <limits.h>

#include "easer.h"
#include "easerTypes.h"


//--------------------------------------------------------
Easer::Easer() :
  m_easingFunc(EASING_LINEAR)
  ,m_easingType(EASING_IN_OUT)
  ,m_duration(1.0)
  ,m_loop(EASING_LOOP_NONE)
  ,m_startTime(0)
{};



Easer::Easer(easingFunc func) :
  m_easingFunc(func)
  ,m_easingType(EASING_IN_OUT)  
  ,m_duration(1.0)
  ,m_loop(EASING_LOOP_NONE)
  ,m_startTime(0)
{};



//--------------------------------------------------------
void Easer::rewind()
{
  // make it start over the next tick
  m_startTime = 0;
}


boolean Easer::tick(double* current)
{
  unsigned long _now = millis();
  
  return tick(_now, current);
}


boolean Easer::tick(unsigned long _now, double* current)
{
  boolean result = true;
  unsigned long currentTime = 0;
  
  // did we start already?
  if (m_startTime == 0) {
    // first time... so we start
    m_startTime = _now;    
    return true;
  }
  
  // calc current time
  // take care of type limits
  if (_now >= m_startTime) {
    currentTime = _now - m_startTime;
  } else {
    // type overflow
    currentTime = ULONG_MAX - m_startTime + _now;
  }

  
//    // only linear for now
//  // calc current value
//  switch(m_easingType)
//  {
//    case EASING_IN:
//      *current = (double)currentTime/(double)m_duration;
//      break;
//      
//    case EASING_OUT:
//      *current = (double)currentTime/(double)m_duration;
//      break;
//      
//    case EASING_IN_OUT:
//      *current = (double)currentTime/(double)m_duration;
//      break;
//
//       
//     default:
//       *current = (double)currentTime/(double)m_duration;
//       break;
//   }
  
  // only linear for now!
  *current = (double)currentTime/(double)m_duration;
  
  
  // test if we are withing time bound
  if (currentTime > m_duration) {
  
  // set starttime = 0
//  rewind();
//  while(currentTime > m_duration) {
//    currentTime -= m_duration;
//  }
  
    // correct starttime
    m_startTime = _now;// - currentTime;
  }
  
  
  if (*current >= 1.0 && m_loop == EASING_LOOP_NONE) {    
    *current = 1.0;
    result = false;
  }
  
  return result;
}
