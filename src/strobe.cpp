/*//-------------------------------------------------------------------------------
*  strobe.cpp
*
*  strobing class
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
#include <limits.h>
#include "strobe.h"


//--------------------------------------------------------
Strobe::Strobe() :
   m_strobeOffTime(250)
  ,m_strobeOnTime(250)
//  ,m_offMultiplier(0.0)
//  ,m_onMultiplier(1.0)
  ,m_lastUpdate(0)
  ,m_state(true)
  ,m_isStrobing(0)
{
}



//--------------------------------------------------------
void Strobe::setStrobing(bool b)
{
  m_isStrobing = b;
  setStrobeState(false);
}


void Strobe::setStrobeState(bool state)
{
  m_state = state;
}

void Strobe::setStrobeState(bool state, unsigned long _now)
{
  m_state = state;
  // reset time
  m_lastUpdate = _now;
}


//--------------------------------------------------------
bool Strobe::update(unsigned long _now)
{
  // if not turned on return false (not changed = not dirty)
  if (!m_isStrobing) return false;
  
  
  // do strobe
  unsigned long diff = 0;
  bool changed = false;

  // take care of type limits
  if (_now >= m_lastUpdate) {  
    diff = _now - m_lastUpdate;
  } else {
    // type overflow
    diff = ULONG_MAX - m_lastUpdate + _now;
  }

  if (m_state) {
    // strobe on
    if (diff > m_strobeOnTime) {
      // turn off
      m_state = false;
      m_lastUpdate = _now;
        
      changed = true;
    }
  } else {
    // strobe off
    if (diff > m_strobeOffTime) {
      // turn on
      m_state = true;
      m_lastUpdate = _now;
      
      changed = true;
    }
  }
  
  // return if state changed or not
  return changed;
}

