/*
  ==============================================================================

    Sequencer.cpp
    Created: 22 Jan 2015 3:56:57pm
    Author:  Karl

  ==============================================================================
*/

#include "Sequencer.h"

Sequencer::Sequencer(MidiMessageCollector& midiCollector) : midiCollector(midiCollector)
{
    // setting up matrix
    
    for (int i = 0; i < Mixer::maxTracks; i++) {
        matrix.add(new Array<float>);
        
        for (int j = 0; j < numCells; j++) {
            matrix[i]->insert(j, 0);
        }
    }
}

Sequencer::~Sequencer()
{
}

int Sequencer::getNumCells()
{
    return numCells;
}

Array<float> Sequencer::getCells(int trackId)
{
    return *matrix.getUnchecked(trackId);
}

void Sequencer::setCell(int trackId, int cellId, float value)
{
    //std::cout << trackId << " " << cellId << " "  << value << std::endl;
    matrix.getUnchecked(trackId)->set(cellId, value);
}

void Sequencer::clockStep(int counter)
{
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix.getUnchecked(i)->getUnchecked(counter)) {
            midiCollector.handleNoteOn(&keyboardState, 1, notes[i], matrix.getUnchecked(i)->getUnchecked(counter));
        }
    }
}