/*
  ==============================================================================

    Mixer.h
    Created: 16 Jan 2015 11:11:23am
    Author:  Karl

  ==============================================================================
*/

#ifndef MIXER_H_INCLUDED
#define MIXER_H_INCLUDED

#include "JuceHeader.h"
#include "Source.h"
#include "Parameter.h"

class Mixer : public MixerAudioSource {
public:
    Mixer(OwnedArray<Parameter>* parameters);
    ~Mixer();
    
    enum trackIndex {
        kick,
        snare,
        hihat,
        perc1,
        perc2,
        tones,
        maxTracks
    };
    
    static const int SelectAllOffset = 21;
    static int getTrackByName(String name);
    static String getNameByTrackId(int trackId);
    
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo&) override;
    
    void playNote(int note, float velocity);
    
    int getNumberOfSoundsByTrack(int track);
    
    OwnedArray<Source> sources;
    MidiMessageCollector midiCollector;
    OwnedArray<Parameter>* parameters;
    
protected:
    
    void createAndAddTrack(int trackId);
    
    Source* getTrackById(int trackId);
    
    MidiKeyboardState keyboardState;
    
    float lastLevel = 1;
};

#endif  // MIXER_H_INCLUDED
