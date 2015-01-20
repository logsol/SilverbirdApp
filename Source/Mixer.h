/*
  ==============================================================================

    Mixer.h
    Created: 16 Jan 2015 11:11:23am
    Author:  Karl

  ==============================================================================
*/

#ifndef MIXER_H_INCLUDED
#define MIXER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Source.h"
#include <vector>

struct paramList {
    int sample;
    float pitch;
    float decay;
    float distort;
    float filter;
    float shuffle;
    float master;
};

class Mixer : public MixerAudioSource {
public:
    Mixer();
    ~Mixer();
    
    void playNote(int note);
    void setMaster(float value);
    void setSampleAll(int value);
    void setTrackLevel(float value, int trackId);
    void setTrackMute(bool value, int trackId);
    void setTrackSample(int value, int trackId);
    
    enum trackIndex {
        kick,
        snare,
        hihat,
        maxTracks
    };
    
    OwnedArray<Source> sources;
    MidiMessageCollector midiCollector;
    
protected:
    
    void createAndAddTrack(int trackId, String name);
    void getNextAudioBlock (const AudioSourceChannelInfo&) override;
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    Source* getTrackById(int trackId);
    
    MidiKeyboardState keyboardState;

    paramList* globalParams = new paramList();
};

#endif  // MIXER_H_INCLUDED
