/*
  ==============================================================================

    Controller.h
    Created: 9 Mar 2014 3:22:47pm
    Author:  Pannek Karl

  ==============================================================================
*/

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Source.h"
#include "Mixer.h"
#include "Clock.h"
#include "ClockListener.h"
#include "Sequencer.h"

class Controller  {
public:
    Controller();
    ~Controller();
    
    void addClockListener(ClockListener* listener);
    void removeClockListener(ClockListener* listener);

    Sequencer sequencer;
    Clock clock;
    Mixer mixer;
    int dead = 1234;

protected:
    void bootstrap();
    AudioSourcePlayer audioSourcePlayer;
    AudioDeviceManager audioDeviceManager;
    

};

#endif  // CONTROLLER_H_INCLUDED
