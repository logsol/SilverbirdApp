/*
  ==============================================================================

    ModulationSequencer.cpp
    Created: 29 Feb 2016 9:42:57pm
    Author:  Karl

  ==============================================================================
*/

#include "ModulationSequencer.h"
#include "Controller.h"


ModulationSequencer::ModulationSequencer(Controller* controller, int modTrackId) : Sequencer(controller),
                                                                                   modTrackId(modTrackId)
{

    for (int i = 0; i < numPatterns; i++) {
        matrix.add(new Array<float>);
        
        for (int j = 0; j < numCells; j++) {
            matrix[i]->insert(j, 0.5);
        }
    }
    
    for (int i = 0; i < Mixer::tracks::max; i++) {
        modulationTargetFlags.add(false);
    }
    
    jassert(modulationTargetFlags.size() == Mixer::tracks::max);
}

ModulationSequencer::~ModulationSequencer()
{
    modulationTargetFlags.clear();
}

void ModulationSequencer::setModulationTargetEnabled(int trackId, bool isEnabled)
{
    jassert(isPositiveAndBelow(trackId, modulationTargetFlags.size()));
    modulationTargetFlags.set(trackId, isEnabled);
}

void ModulationSequencer::clockStep(int cursorPosition)
{
    if (cursorPosition == -1) {
        return;
    }
    
    Sequencer::clockStep(cursorPosition);

    int patternId = 1; // TODO set pattern
    
    float value = matrix.getUnchecked(patternId)->getUnchecked(cursor);

    for (int targetTrackId = 0; targetTrackId < modulationTargetFlags.size(); targetTrackId++) {
        if(modulationTargetFlags[targetTrackId]) {
            controller->addStepModulationValue(modTrackId, value, targetTrackId);
        }
    }
}