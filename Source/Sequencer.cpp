/*
  ==============================================================================

    Sequencer.cpp
    Created: 22 Jan 2015 3:56:57pm
    Author:  Karl

  ==============================================================================
*/

#include "Sequencer.h"


Sequencer::Sequencer(Mixer& mixer) : mixer(mixer)
{
    notes[0] = 36;
    notes[1] = 38;
    notes[2] = 42;
    notes[3] = 45;
    notes[4] = 48;
    notes[5] = 52;
    
    // setting up matrix
    
    for (int i = 0; i < Mixer::tracks::max; i++) {
        matrix.add(new Array<float>);
        
        for (int j = 0; j < numCells; j++) {
            matrix[i]->insert(j, 0);
        }
    }
    
    for (int i = 0; i < Mixer::mods::max; i++) {
        modulationMatrix.add(new Array<float>);
        
        for (int j = 0; j < numCells; j++) {
            modulationMatrix[i]->insert(j, 0.5);
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

Array<float> Sequencer::getModulationCells(int trackId)
{
    return *modulationMatrix.getUnchecked(trackId);
}

void Sequencer::setCell(int trackId, int cellId, float value)
{
    matrix.getUnchecked(trackId)->set(cellId, value);
}

void Sequencer::setModulationCell(int trackId, int cellId, float value)
{
    modulationMatrix.getUnchecked(trackId)->set(cellId, value);
}

void Sequencer::clockStep(int cursorPosition, double nextStepTimeMs)
{
    if (cursorPosition == -1) {
        return;
    }

    for (int i = 0; i < Mixer::mods::max; i++) {
        float value = modulationMatrix.getUnchecked(i)->getUnchecked(cursorPosition);
        columnModulations.insert(i, value);
    }
    mixer.setColumnModulations(&columnModulations);
    
    for (int trackId = 0; trackId < Mixer::tracks::max; trackId++) {
        float value = matrix.getUnchecked(trackId)->getUnchecked(cursorPosition);
        
        MidiMessage m = MidiMessage::noteOn(1, notes[trackId], static_cast<float>(value));
        m.setTimeStamp(nextStepTimeMs / 1000.0);
        mixer.midiCollector.addMessageToQueue(m);
    }
}