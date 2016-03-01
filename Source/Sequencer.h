/*
  ==============================================================================

    Sequencer.h
    Created: 22 Jan 2015 3:56:57pm
    Author:  Karl

  ==============================================================================
*/

#ifndef SEQUENCER_H_INCLUDED
#define SEQUENCER_H_INCLUDED

#include "JuceHeader.h"
#include "Mixer.h"
#include "ClockListener.h"
#include "SequencerMessage.h"

class Sequencer
{
public:
    Sequencer(Controller* controller);
    virtual ~Sequencer();
    
    int getNumCells();
    Array<float> getCells(int trackId);
    void setCell(int trackId, int cellId, float value);
    virtual void clockStep(int counter);
    
    //void setModulationCell(int trackId, int cellId, float value);
    Array<float> getModulationCells(int trackId);
    int getCursorPosition();
    void resetCursor();
    
protected:
    Controller* controller;
    int numCells = 16;
    int numPatterns = 16;
    
    OwnedArray<Array<float>> matrix; // first dimension = pattern
    
    SequencerMessage* sequencerMessage; // gotta be on the heap.
    
    float playbackSpeed = 1.0;
    int length = numCells;
    int cursor = 0;
};


#endif  // SEQUENCER_H_INCLUDED
