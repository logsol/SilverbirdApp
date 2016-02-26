/*
  ==============================================================================

    Clock.h
    Created: 22 Jan 2015 1:58:43pm
    Author:  Karl

  ==============================================================================
*/

#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED

#include "JuceHeader.h"
#include "ClockListener.h"
#include "Parameter.h"
#include "Mixer.h"
#include "Sequencer.h"

class Clock : public MessageListener
{
public:
    Clock(OwnedArray<Parameter>* parameters, Mixer& mixer, Sequencer& sequencer);
    ~Clock();
    
    void addListener(ClockListener* listener);
    void removeListener(ClockListener* listener);
    
    //void hiResTimerCallback();
    
    void handleMessage(const Message& message);
    
    bool togglePlayPause();
    void setPlayPause(bool play);
    void setBpm(float bpm);
    
    void tick(float shuffle, AudioSampleBuffer& buffer, double sampleRate);
    float getBpm();
    
protected:
    bool isPlaying = false;
    double bpm = 120.0;
    int cursor = -1;
    int numCells = 16;
    double sixteenthTimeMs = 60000.0 / bpm / 4.0;
    double lastClockStepTimeMs = 0;
    OwnedArray<ClockListener> listeners;
    OwnedArray<Parameter>* parameters;
    Mixer& mixer;
    Sequencer& sequencer;
};

#endif  // CLOCK_H_INCLUDED
