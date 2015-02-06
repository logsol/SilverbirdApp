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
    startTimer(125);
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
    
    postMessage(new Message());
}

void Clock::handleMessage(const Message& message){
    for (int i = 0; i < listeners.size(); i++) {
        listeners[i]->clockStep(cursor);
    }
}