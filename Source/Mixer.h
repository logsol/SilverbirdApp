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
#include "GlobalParamList.h"
#include <vector>

class Mixer : public MixerAudioSource {
public:
    Mixer();
    ~Mixer();
    
    int getTrackByName(String name);
    String getNameByTrackId(int trackId);
    
    void playNote(int note, float velocity);
    
    void setSampleAll(int value);
    void setPitch(float value);
    void setDecay(float value);
    void setDistort(float value);
    void setCutoff(float value);
    void setShuffle(float value);
    void setMaster(float value);
    
    void setTrackLevel(float value, int trackId);
    void setTrackMute(bool value, int trackId);
    void setTrackSample(int value, int trackId);
    void setTrackAttack(float value, int trackId);
    void setTrackDecay(float value, int trackId);
    void setTrackPitch(float value, int trackId);
    void setTrackDistort(float value, int trackId);
    void setTrackCutoff(float value, int trackId);
    
    enum trackIndex {
        kick,
        snare,
        hihat,
        perc1,
        perc2,
        tones,
        maxTracks
    };
    
    OwnedArray<Source> sources;
    MidiMessageCollector midiCollector;
    globalParamList globalParams;
    
protected:
    
    void createAndAddTrack(int trackId);
    void getNextAudioBlock (const AudioSourceChannelInfo&) override;
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    Source* getTrackById(int trackId);
    
    MidiKeyboardState keyboardState;
};

#endif  // MIXER_H_INCLUDED
