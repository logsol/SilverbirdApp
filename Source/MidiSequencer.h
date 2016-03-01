/*
  ==============================================================================

    MidiSequencer.h
    Created: 29 Feb 2016 6:29:25pm
    Author:  Karl

  ==============================================================================
*/

#ifndef MIDISEQUENCER_H_INCLUDED
#define MIDISEQUENCER_H_INCLUDED

#include "JuceHeader.h"
#include "ClockListener.h"
#include "SequencerMessage.h"
#include "Sequencer.h"
#include "Mixer.h"
class Controller;

class MidiSequencer : public Sequencer
{
public:
    MidiSequencer(Controller* controller, int trackId);
    ~MidiSequencer();
    
    void clockStep(int counter, double nextStepTimeMs);

protected:
    int notes[Mixer::tracks::max];
    int trackId = -1;
};

#endif  // MIDISEQUENCER_H_INCLUDED
