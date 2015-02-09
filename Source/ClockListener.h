/*
  ==============================================================================

    ClockListener.h
    Created: 22 Jan 2015 1:58:51pm
    Author:  Karl

  ==============================================================================
*/

#ifndef CLOCKLISTENER_H_INCLUDED
#define CLOCKLISTENER_H_INCLUDED


#include "JuceHeader.h"

class ClockListener
{
public:
    ClockListener();
    virtual ~ClockListener();
    
    virtual void clockStep (int cursor) = 0;

protected:
};


#endif  // CLOCKLISTENER_H_INCLUDED
