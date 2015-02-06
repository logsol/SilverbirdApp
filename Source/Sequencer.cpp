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
    //delete sequencerMessage;
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
    matrix.getUnchecked(trackId)->set(cellId, value);
}

void Sequencer::clockStep(int cursorPosition)
{
    
    for (int trackId = 0; trackId < matrix.size(); trackId++) {
        if (matrix.getUnchecked(trackId)->getUnchecked(cursorPosition)) {
            sequencerMessage = new SequencerMessage();
            sequencerMessage->type = SequencerMessage::type_note;
            sequencerMessage->trackId = trackId;
            sequencerMessage->cellId = cursorPosition;
            postMessage(sequencerMessage);
        }
    }
    
}

void Sequencer::handleMessage (const Message& message)
{
    SequencerMessage* sequencerMessage = (SequencerMessage*) &message;
    float value = matrix.getUnchecked(sequencerMessage->trackId)->getUnchecked(sequencerMessage->cellId);
    
    mixer.playNote(notes[sequencerMessage->trackId], value);
}