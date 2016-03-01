/*
  ==============================================================================

    ModulationSequencer.h
    Created: 29 Feb 2016 9:42:57pm
    Author:  Karl

  ==============================================================================
*/

#ifndef MODULATIONSEQUENCER_H_INCLUDED
#define MODULATIONSEQUENCER_H_INCLUDED

#include "ClockListener.h"
#include "SequencerMessage.h"
#include "Sequencer.h"
class Controller;

class ModulationSequencer : public Sequencer
{
public:
    ModulationSequencer(Controller* controller, int modTrackId);
    ~ModulationSequencer();
    
    void clockStep(int counter) override;
    
    void setModulationTargetEnabled(int trackId, bool isEnabled);

protected:
    
    int modTrackId = -1;
    Array<bool> modulationTargetFlags;
};


#endif  // MODULATIONSEQUENCER_H_INCLUDED
