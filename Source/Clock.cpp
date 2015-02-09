/*
  ==============================================================================

    Clock.cpp
    Created: 22 Jan 2015 1:58:43pm
    Author:  Karl

  ==============================================================================
*/

#include "Clock.h"

Clock::Clock()
{
    listeners.clear(true);
}

Clock::~Clock()
{
    stopTimer();
    listeners.clear(false);
}

void Clock::addListener(ClockListener* listener)
{
    listeners.add(listener);
}

void Clock::removeListener(ClockListener* listener)
{
    listeners.removeObject(listener);
}

//void Clock::timerCallback()
void Clock::hiResTimerCallback()
{
    cursor++;
    cursor = cursor % numCells;
    
    /*
    // 1e&a 2e&a 3e&a 4e&a (all e/a hits)
    if(cursor % 2) {
        float shl = 1 / (bpm / 60 * 4) * 1000 * globalParams->shuffle / 5;
        juce::Thread::sleep(shl);
    }
    */
    
    postMessage(new Message());
}

void Clock::handleMessage(const Message& message){
    
    for (int i = 0; i < listeners.size(); i++) {
        listeners[i]->clockStep(cursor);
    }
}

void Clock::setGlobalParams(globalParamList* globalParams)
{
    this->globalParams = globalParams;
}


void Clock::togglePlayPause()
{
    setPlayPause(!isPlaying);
}

void Clock::setPlayPause(bool play) {
    if(play) {
        float sixteenthTime = 60000 / bpm / 4;
        startTimer(sixteenthTime);
    } else {
        stopTimer();
        cursor = -1;
        postMessage(new Message());
    }
    
    isPlaying = play;
}