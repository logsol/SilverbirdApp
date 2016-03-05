/*
  ==============================================================================

    FxBus.cpp
    Created: 5 Mar 2016 11:22:08pm
    Author:  Karl

  ==============================================================================
*/

#include "FxBus.h"

FxBus::FxBus() : buffer(2, 512), busInfo(buffer)
{
}

void FxBus::getNextAudioBlock (const AudioSourceChannelInfo& info)
{
    busInfo.buffer->applyGainRamp(0, busInfo.numSamples, lastLevel, gain);
    lastLevel = gain;
    
    info.buffer->copyFrom(0, 0, busInfo.buffer->getReadPointer(0), info.numSamples);
    info.buffer->copyFrom(1, 0, busInfo.buffer->getReadPointer(1), info.numSamples);
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

void FxBus::copyChannelInfoToBus(AudioSourceChannelInfo sourceInfo)
{
    busInfo.clearActiveBufferRegion();
    busInfo.buffer->copyFrom(0, 0, sourceInfo.buffer->getReadPointer(0), sourceInfo.numSamples);
    busInfo.buffer->copyFrom(1, 0, sourceInfo.buffer->getReadPointer(1), sourceInfo.numSamples);
}