/*
  ==============================================================================

    Sequencer.cpp
    Created: 22 Jan 2015 3:56:57pm
    Author:  Karl

  ==============================================================================
*/

#include "Sequencer.h"


Sequencer::Sequencer(Controller* controller) : controller(controller)
{
    
    // setting up matrix
    for (int i = 0; i < numPatterns; i++) {
        matrix.add(new Array<float>);
        
        for (int j = 0; j < numCells; j++) {
            matrix[i]->insert(j, 0.5);
        }
    }
    
    /*
    for (int i = 0; i < Mixer::mods::max; i++) {
        modulationMatrix.add(new Array<float>);
        
        for (int j = 0; j < numCells; j++) {
            modulationMatrix[i]->insert(j, 0.5);
        }
    }
     */
}

Sequencer::~Sequencer()
{
}

int Sequencer::getNumCells()
{
    return numCells;
}

Array<float> Sequencer::getCells(int patternId)
{
    return *matrix.getUnchecked(patternId);
}




int Sequencer::getCursorPosition()
{
    return cursor;
}


void Sequencer::setCell(int patternId, int cellId, float value)
{
    matrix.getUnchecked(patternId)->set(cellId, value);
}

/*
void Sequencer::setModulationCell(int trackId, int cellId, float value)
{
    modulationMatrix.getUnchecked(trackId)->set(cellId, value);
}
*/

void Sequencer::clockStep(int cursorPosition)
{
    if (cursorPosition == -1) {
        return;
    }
    
    cursor++;
    
    if (cursor >= length) {
        cursor = 0;
    }
    


    /*
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
     */
}

void Sequencer::resetCursor()
{
    cursor = -1;
}
