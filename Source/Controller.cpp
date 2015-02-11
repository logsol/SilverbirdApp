/*
  ==============================================================================

    Controller.cpp
    Created: 9 Mar 2014 3:22:47pm
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Controller.h"


Controller::Controller() : sequencer(mixer)
{
    clock.setGlobalParams(&mixer.globalParams);
    clock.addListener(&sequencer);
}

Controller::~Controller()
{
}

void Controller::addClockListener(ClockListener* listener)
{
    clock.addListener(listener);
}

void Controller::removeClockListener(ClockListener* listener)
{
    clock.removeListener(listener);
}

void Controller::togglePlayPause()
{
    clock.togglePlayPause();
}

void Controller::setPlayPause(bool play)
{
    clock.setPlayPause(play);
}

void Controller::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    mixer.prepareToPlay(samplesPerBlock, sampleRate);
}

void Controller::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    
    AudioSourceChannelInfo channelInfo (&buffer, 0, buffer.getNumSamples());
    mixer.getNextAudioBlock(channelInfo);
    
    if (!JUCEApplication::isStandaloneApp()) {
        
        AudioPlayHead::CurrentPositionInfo info;
        getPlayHead()->getCurrentPosition(info);
        
        if (positionInfo.isPlaying != info.isPlaying) {
            setPlayPause(info.isPlaying);
        }
        
        positionInfo = info;
    }

    
    // merging incoming midi (from host) into midiCollector
    MidiBuffer::Iterator iterator(midiMessages);
    MidiMessage result;
    int position;
    
    while (iterator.getNextEvent(result, position)) {
        result.setTimeStamp(Time::getMillisecondCounter() / 1000.0);
        mixer.midiCollector.addMessageToQueue(result);
    }
    
    clock.tick();
}

AudioProcessorEditor* Controller::createEditor()
{
    return new Gui (this);
}


//==============================================================================
// This creates new instances of the plugin..

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Controller();
}







/*
int Controller::getParamId(int paramId, bool isGlobal, int trackId, int cellId)
{
    if (isGlobal) {
        return paramId;
    }
    
    if (trackId > 0) {
        
        if (cellId > 0) {
        }
        
        //return Controller::Param::max * trackId;
    }
    
    */
    
    /*
    i=0;
    
    while (globalParams as globalParam) {
        ++i
    }
    
    while (tracks as track) {
        while (trackParams as trackParam) {
            ++i;
        }
    }
    
     */
/*
    return 0;
}
*/