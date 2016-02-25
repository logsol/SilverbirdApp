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

// handle asynchronous calls - for gui only
void Clock::handleMessage(const Message& message){
    
    for (int i = 0; i < listeners.size(); i++) {
        listeners[i]->clockStep(cursor);
    }
}

bool Clock::togglePlayPause()
{
    setPlayPause(!isPlaying);
    return isPlaying;
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

float Clock::getBpm()
{
    return bpm;
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
    ? 1 / (bpm / 60 * 4) * 1000 * shuffle / 3
    : 0.0;

    
    //std::cout << shuffleTimeMs << std::endl;
    
    if (nextStepTimeMs <= endOfBlockTimeMs + shuffleTimeMs) {
        
        lastClockStepTimeMs = nextStepTimeMs;
        cursor++;
        cursor = cursor % numCells;
        
        sequencer.clockStep(cursor, nextStepTimeMs);
        
        postMessage(new Message());
    }
}