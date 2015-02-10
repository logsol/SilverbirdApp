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

class Controller
{
public:
    Controller();
    ~Controller();
    
    void addClockListener(ClockListener* listener);
    void removeClockListener(ClockListener* listener);
    void togglePlayPause();
    void setPlayPause(bool play);
    
    void setParameter(int parameterIndex, float value);
    const String getName();
    
    //int getParamId(int paramId, bool isGlobal, int trackId, int cellId);

    Sequencer sequencer;
    Clock clock;
    Mixer mixer;
    
    /*
    enum class Param {
        shuffle,
        level,
        mute,
        sample,
        pitch,
        attack,
        decay,
        distort,
        cutoff,
        max
    };*/
    
protected:
};

#endif  // CONTROLLER_H_INCLUDED
