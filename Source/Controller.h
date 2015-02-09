/*
  ==============================================================================

    Controller.h
    Created: 9 Mar 2014 3:22:47pm
    Author:  Pannek Karl

  ==============================================================================
*/

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "JuceHeader.h"
#include "Source.h"
#include "Mixer.h"
#include "Clock.h"
#include "ClockListener.h"
#include "Sequencer.h"
#include "Knob.h"

class Controller  {
public:
    Controller();
    ~Controller();
    
    void addClockListener(ClockListener* listener);
    void removeClockListener(ClockListener* listener);
    void setParameter(int parameterIndex, float value);
    void togglePlayPause();
    void setPlayPause(bool play);

    Sequencer sequencer;
    Clock clock;
    Mixer mixer;

protected:
};

#endif  // CONTROLLER_H_INCLUDED
