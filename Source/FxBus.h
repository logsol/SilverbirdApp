/*
  ==============================================================================

    FxBus.h
    Created: 5 Mar 2016 11:22:08pm
    Author:  Karl

  ==============================================================================
*/

#ifndef FXBUS_H_INCLUDED
#define FXBUS_H_INCLUDED

#include "JuceHeader.h"

class FxBus : public AudioSource {
public:
    
    FxBus(int trackId);
    
    void getNextAudioBlock (const AudioSourceChannelInfo&) override;
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void releaseResources() override;
    
    void setGain(float gain);
    void copyChannelInfoToBus(const AudioSourceChannelInfo& sourceInfo);
    
protected:
    float gain = 1.0;
    AudioBuffer<float> fxBuffer;
    AudioSourceChannelInfo input;
    float lastLevel = 1.0;
    int trackId = -99;
};



#endif  // FXBUS_H_INCLUDED
