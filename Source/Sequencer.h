/*
  ==============================================================================

    Sequencer.h
    Created: 22 Jan 2015 3:56:57pm
    Author:  Karl

  ==============================================================================
*/

#ifndef SEQUENCER_H_INCLUDED
#define SEQUENCER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Mixer.h"
#include "ClockListener.h"

class Sequencer : public ClockListener
{
public:
    Sequencer(MidiMessageCollector& midiCollector);
    ~Sequencer();
    
    int getNumCells();
    Array<float> getCells(int trackId);
    void setCell(int trackId, int cellId, float value);
    void clockStep(int counter);
    
protected:
    MidiMessageCollector& midiCollector;
    MidiKeyboardState keyboardState;
    int numCells = 16;
    OwnedArray<Array<float>> matrix;
    
    int notes[3] = {36, 38, 42};
};


#endif  // SEQUENCER_H_INCLUDED
