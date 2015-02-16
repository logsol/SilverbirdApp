/*
  ==============================================================================

    Controller.cpp
    Created: 9 Mar 2014 3:22:47pm
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Controller.h"


Controller::Controller() : mixer(&parameters),
                           clock(&parameters),
                           sequencer(mixer)
{
    int parameterId = 0;
    
    // FIXME: outsource into method
    
    for (int paramNameId = 0; paramNameId < Controller::params::max; ++paramNameId) {
        Parameter* p = new Parameter(parameterId, paramNameId);
        parameters.add(p);
        parameterId++;
    }
    
    for (int trackId = 0; trackId < Mixer::maxTracks; ++trackId) {
        for (int paramNameId = 0; paramNameId < Controller::params::max; ++paramNameId) {
            Parameter* p = new Parameter(parameterId, paramNameId, trackId, mixer.getNumberOfSoundsByTrack(trackId));
            parameters.add(p);
            parameterId++;
        }
    }
    
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

void Controller::setParameter (int index, float newValue)
{
    Value value = *parameters[index];
    value.setValue(newValue);
}

int Controller::getParameterId(int paramNameId, int trackId, int cellId)
{
    // trackId -1 means it's global
    
    if (trackId != -1) {
        if (cellId != -1) {
        }
        
        return (trackId + 1) * Controller::params::max + paramNameId;
    }
    
    return paramNameId;
}

Parameter* Controller::getParameterByAttrs(int paramNameId, int trackId, int cellId)
{
    for (int i = 0; i < parameters.size(); ++i) {
        Parameter* parameter = parameters.getUnchecked(i);
        if (parameter && parameter->paramNameId == paramNameId
            && parameter->trackId == trackId
            && parameter->cellId == cellId) {
            return parameter;
        }
    }
    
    return nullptr; // FIXME : should not crash here (create if() everywhere this method is called)
}

const String Controller::getParameterName (int index)
{
    return parameters.getUnchecked(index)->name;
}

const String Controller::getParameterText (int index)
{
    return (String) parameters.getUnchecked(index)->getScaledValue();
}

void Controller::getStateInformation (MemoryBlock& destData)
{
    //copyXmlToBinary();
}

void Controller::setStateInformation (const void* data, int sizeInBytes)
{
    //getXmlFromBinary();
}

void Controller::sliderValueChanged(Slider *slider)
{
    onGuiParameterChange(slider->getValueObject());
}

void Controller::buttonClicked (Button* button)
{
    onGuiParameterChange(button->getToggleStateValue());
}

void Controller::onGuiParameterChange (Value& value)
{
    for (int i=0; i < parameters.size(); i++) {
        Parameter* p = parameters.getUnchecked(i);
        if (p->refersToSameSourceAs(value)) {
            setParameterNotifyingHost(p->parameterId, p->getValue());   
            return;
        }
    }
    std::cout << "should not be happenign;" << std::endl;
    
}
//==============================================================================
// This creates new instances of the plugin..

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Controller();
}
