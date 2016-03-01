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
#include "ModulationSequencer.h"
#include "MidiSequencer.h"
class Controller;

class Clock : public MessageListener
{
public:
    Clock(Controller* controller);
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
    
    Sequencer* getMidiSequencerByTrackId(int trackId);
    Sequencer* getModulationSequencerByTrackId(int trackId);
    
protected:
    bool isPlaying = false;
    double bpm = 120.0;
    int cursor = -1;
    int numCells = 16;
    double sixteenthTimeMs = 60000.0 / bpm / 4.0;
    double lastClockStepTimeMs = 0;
    OwnedArray<ClockListener> listeners;
    Controller* controller;
    
    // TODO add counter: int cycles = 0;
    
    OwnedArray<MidiSequencer> midiSequencers;
    OwnedArray<ModulationSequencer> modulationSequencers;
};

#endif  // CLOCK_H_INCLUDED
