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
#include "GlobalParamList.h"

class Clock : public HighResolutionTimer, MessageListener
{
public:
    Clock();
    ~Clock();
    
    void addListener(ClockListener* listener);
    void removeListener(ClockListener* listener);
    
//    void timerCallback() override;
    void hiResTimerCallback();
    
    void handleMessage(const Message& message);
    void setGlobalParams(globalParamList* globalParams);
    
    void togglePlayPause();
    void setPlayPause(bool play);
    
    void tick();
    
protected:
    bool isPlaying = false;
    float bpm = 120;
    int cursor = -1;
    int numCells = 16;
    float sixteenthTime = 60000 / bpm / 4;
    float lastClockStepTime = 0;
    OwnedArray<ClockListener> listeners;
    
    globalParamList* globalParams;
};

#endif  // CLOCK_H_INCLUDED
