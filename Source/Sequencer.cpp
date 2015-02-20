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

void Sequencer::clockStep(int cursorPosition)
{
    if (cursorPosition == -1) {
        return;
    }
    
    sequencerMessage = new SequencerMessage();
    sequencerMessage->type = SequencerMessage::type_modulation;
    sequencerMessage->cellId = cursorPosition;
    postMessage(sequencerMessage);
    
    for (int trackId = 0; trackId < Mixer::tracks::max; trackId++) {
        sequencerMessage = new SequencerMessage();
        sequencerMessage->type = SequencerMessage::type_note;
        sequencerMessage->trackId = trackId;
        sequencerMessage->cellId = cursorPosition;
        postMessage(sequencerMessage);
    }
}

void Sequencer::handleMessage (const Message& message)
{
    SequencerMessage* sequencerMessage = (SequencerMessage*) &message;
    
    if (sequencerMessage->type == SequencerMessage::type_modulation) {
        for (int i = 0; i < Mixer::mods::max; i++) {
            float value = modulationMatrix.getUnchecked(i)->getUnchecked(sequencerMessage->cellId);
            columnModulations.insert(i, value);
        }
        mixer.setColumnModulations(&columnModulations);
        return;
    }
    
    
    if (sequencerMessage->type == SequencerMessage::type_note) {
        float value = matrix.getUnchecked(sequencerMessage->trackId)->getUnchecked(sequencerMessage->cellId);
        mixer.playNote(notes[sequencerMessage->trackId], value);
        return;
    } 
}