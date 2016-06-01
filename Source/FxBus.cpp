/*
  ==============================================================================

    FxBus.cpp
    Created: 5 Mar 2016 11:22:08pm
    Author:  Karl

  ==============================================================================
*/

#include "FxBus.h"


FxBus::FxBus(int trackId) : fxBuffer(2, 2048), input(fxBuffer), trackId(trackId)
{
    
}

void FxBus::getNextAudioBlock (const AudioSourceChannelInfo& output)
{
    output.clearActiveBufferRegion();
    
    if(lastLevel != gain) {
        input.buffer->applyGainRamp(0, input.buffer->getNumSamples(), lastLevel, gain);
        lastLevel = gain;
    } else if (gain <= 0.0) {
        return;
    }
    
    int minSamples = (output.buffer->getNumSamples() < input.buffer->getNumSamples())
    ? output.buffer->getNumSamples()
    : input.buffer->getNumSamples();
    
    output.buffer->copyFrom(0, 0, input.buffer->getReadPointer(0), minSamples);
    output.buffer->copyFrom(1, 0, input.buffer->getReadPointer(1), minSamples);
    
    if (trackId == 1) {
        //std::cout << *output.buffer->getReadPointer(0) << std::endl;
    }
}

void FxBus::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
}

void FxBus::releaseResources()
{
}

void FxBus::setGain(float gain)
{
    this->gain = gain;
}

void FxBus::copyChannelInfoToBus(const AudioSourceChannelInfo& source)
{
    input.clearActiveBufferRegion();
    
    int minSamples = source.buffer->getNumSamples() < input.buffer->getNumSamples() ? source.buffer->getNumSamples() : input.buffer->getNumSamples();
    
    input.buffer->copyFrom(0, 0, source.buffer->getReadPointer(0), minSamples);
    input.buffer->copyFrom(1, 0, source.buffer->getReadPointer(1), minSamples);
    
}
