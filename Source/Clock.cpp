/*
  ==============================================================================

    Clock.cpp
    Created: 22 Jan 2015 1:58:43pm
    Author:  Karl

  ==============================================================================
*/

#include "Clock.h"
#include "Controller.h"

Clock::Clock(Controller* controller)
    : controller(controller)
{
    listeners.clear(true);
    
    for (int trackId=0; trackId < Mixer::tracks::max; trackId++) {
        midiSequencers.add(new MidiSequencer(controller, trackId));
    }
    
    for (int modTrackId=0; modTrackId < Mixer::mods::max; modTrackId++) {
        modulationSequencers.add(new ModulationSequencer(controller, modTrackId));
    }
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
    
    controller->resetStepModulations();
    
    for (int i=0 ; i<modulationSequencers.size(); i++) {
        modulationSequencers[i]->clockStep(cursor);
    }
    
    for (int i = 0; i < listeners.size(); i++) {
        listeners[i]->clockStep();
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
        for (int i=0 ; i<midiSequencers.size(); i++) {
            midiSequencers[i]->resetCursor();
        }
        for (int i=0 ; i<modulationSequencers.size(); i++) {
            modulationSequencers[i]->resetCursor();
        }
        postMessage(new Message());
    }
    
    isPlaying = play;
}

void Clock::setBpm(float bpm)
{
    this->bpm = bpm;
    this->sixteenthTimeMs = 60000.0 / this->bpm / 4.0;
//    std::cout << "16th ms: " << this->sixteenthTimeMs << std::endl;
}

float Clock::getBpm()
{
    return bpm;
}

Sequencer* Clock::getMidiSequencerByTrackId(int trackId)
{
    return midiSequencers[trackId]; // todo its a bit too simple
}

Sequencer* Clock::getModulationSequencerByTrackId(int trackId)
{
    return modulationSequencers[trackId]; // todo its a bit too simple
}

void Clock::tick(float shuffle, AudioSampleBuffer& buffer, double sampleRate)
{
    if (!isPlaying) {
        return;
    }
    
    double now = Time::getMillisecondCounterHiRes();
    double nextStepTimeMs = lastClockStepTimeMs + sixteenthTimeMs;
    
    int numSamples = buffer.getNumSamples();
    double singleSampleTimeMs = 1000.0/sampleRate;
    

    double endOfBlockTimeMs = now + (numSamples * singleSampleTimeMs);
    
    double shuffleTimeMs =  cursor % 2
    ? 0.0
    : 1 / (bpm / 60.0 * 4.0) * 1000.0 * shuffle / 3.0;

    if (nextStepTimeMs+shuffleTimeMs <= endOfBlockTimeMs) {
    
        cursor++;
        cursor = cursor % numCells;
        
        for (int i=0 ; i<midiSequencers.size(); i++) {
            midiSequencers[i]->clockStep(cursor, nextStepTimeMs + shuffleTimeMs);
        }
    
        postMessage(new Message());
        
        lastClockStepTimeMs = nextStepTimeMs;
    }
}