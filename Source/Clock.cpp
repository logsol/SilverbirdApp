/*
  ==============================================================================

    Clock.cpp
    Created: 22 Jan 2015 1:58:43pm
    Author:  Karl

  ==============================================================================
*/

#include "Clock.h"


Clock::Clock(OwnedArray<Parameter>* parameters, Mixer& mixer, Sequencer& sequencer)
    : parameters(parameters),
      mixer(mixer),
      sequencer(sequencer) 
{
    listeners.clear(true);
}

Clock::~Clock()
{
    //stopTimer();
    listeners.clear(false);
}

void Clock::addListener(ClockListener* listener)
{
    listeners.add(listener);
}

void Clock::removeListener(ClockListener* listener)
{
    listeners.removeObject(listener, false);
}

//void Clock::timerCallback()
/*
void Clock::hiResTimerCallback()
{
    //cursor++;
    //cursor = cursor % numCells;
    
 
    // 1e&a 2e&a 3e&a 4e&a (all e/a hits)
    if(cursor % 2) {
        float shl = 1 / (bpm / 60 * 4) * 1000 * globalParams->shuffle / 5;
        juce::Thread::sleep(shl);
    }
 
    
    //postMessage(new Message());
}
*/

// handle asynchronous calls for gui
void Clock::handleMessage(const Message& message){
    
    for (int i = 0; i < listeners.size(); i++) {
        listeners[i]->clockStep(cursor);
    }
}


void Clock::togglePlayPause()
{
    setPlayPause(!isPlaying);
}

void Clock::setPlayPause(bool play) {
    if(play) {
        lastClockStepTimeMs = Time::getMillisecondCounterHiRes() - sixteenthTimeMs;
    } else {
        cursor = -1;
        postMessage(new Message());
    }
    
    isPlaying = play;
}

void Clock::setBpm(float bpm)
{
    this->bpm = bpm;
    this->sixteenthTimeMs = 60000 / this->bpm / 4;
}

void Clock::tick(float shuffle, AudioSampleBuffer& buffer, double sampleRate)
{
    if (!isPlaying) {
        return;
    }
    
    double now = Time::getMillisecondCounterHiRes();
    double nextStepTimeMs = lastClockStepTimeMs + sixteenthTimeMs;
    
    int numSamples = buffer.getNumSamples();
    double singleSampleTimeMs = 1000/sampleRate;
    double endOfBlockTimeMs = now + (numSamples * singleSampleTimeMs);
    
    double shuffleTimeMs = cursor % 2
      ? 0.0
      : 1 / (bpm / 60 * 4) * 1000 * shuffle / 5;
    
    //nextStepTimeMs += shuffleTimeMs;
    
    if (nextStepTimeMs <= endOfBlockTimeMs) {
        
        lastClockStepTimeMs = nextStepTimeMs;
        cursor++;
        cursor = cursor % numCells;
        
        sequencer.clockStep(cursor, nextStepTimeMs);
        
        postMessage(new Message());
    }
}