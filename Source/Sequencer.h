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

class Sequencer : public MessageListener
{
public:
    Sequencer(Mixer& mixer);
    ~Sequencer();
    
    int getNumCells();
    Array<float> getCells(int trackId);
    Array<float> getModulationCells(int trackId);
    void setCell(int trackId, int cellId, float value);
    void setModulationCell(int trackId, int cellId, float value);
    void clockStep(int counter, double nextStepTimeMs);
    
    void handleMessage (const Message& message);
    
protected:
    Mixer& mixer;
    int numCells = 16;
    OwnedArray<Array<float>> matrix;
    OwnedArray<Array<float>> modulationMatrix;
    Array<float> columnModulations;
    
    int notes[Mixer::tracks::max];
    SequencerMessage* sequencerMessage; // gotta be on the heap.
     
};


#endif  // SEQUENCER_H_INCLUDED
