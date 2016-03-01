/*
  ==============================================================================

    MidiSequencer.cpp
    Created: 29 Feb 2016 6:29:25pm
    Author:  Karl

  ==============================================================================
*/

#include "MidiSequencer.h"
#include "Controller.h"


MidiSequencer::MidiSequencer(Controller* controller, int trackId) : Sequencer(controller), trackId(trackId)
{
    // todo simplify notes in one place, use enum
    notes[0] = 36;
    notes[1] = 38;
    notes[2] = 42;
    notes[3] = 45;
    notes[4] = 48;
    notes[5] = 52;
    
    for (int i = 0; i < numPatterns; i++) {
        matrix.add(new Array<float>);
        
        for (int j = 0; j < numCells; j++) {
            matrix[i]->insert(j, 0.0);
        }
    }
    
    /*
    length = 4;
    if(trackId==1 || trackId>2) length=8;
    if(trackId==3) length=16;
    */
}

MidiSequencer::~MidiSequencer()
{
}

void MidiSequencer::clockStep(int cursorPosition, double nextStepTimeMs)
{
    if (cursorPosition == -1) {
        return;
    }
    
    Sequencer::clockStep(cursorPosition);

    /*
    for (int i = 0; i < Mixer::mods::max; i++) {
        float value = modulationMatrix.getUnchecked(i)->getUnchecked(cursorPosition);
        columnModulations.insert(i, value);
    }
    mixer.setColumnModulations(&columnModulations);
     */
    
    int patternId = 1; // TODO set pattern
    
    float value = matrix.getUnchecked(patternId)->getUnchecked(cursor);
    

    if (value > 0.0) {
        MidiMessage m = MidiMessage::noteOn(1, notes[trackId], static_cast<float>(value));
        m.setTimeStamp(nextStepTimeMs / 1000.0);
        controller->mixer.midiCollector.addMessageToQueue(m);
    }
    
}
