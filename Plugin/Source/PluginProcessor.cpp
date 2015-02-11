/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
SilverbirdAudioProcessor::SilverbirdAudioProcessor()
{
    gui = new Gui(this);
}

SilverbirdAudioProcessor::~SilverbirdAudioProcessor()
{
    delete gui;
}

//==============================================================================
const String SilverbirdAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int SilverbirdAudioProcessor::getNumParameters()
{
    
    return 2;
}

float SilverbirdAudioProcessor::getParameter (int index)
{
    return 0.0f;
}

void SilverbirdAudioProcessor::setParameter (int index, float newValue)
{
    mixer.globalParams.master = newValue;
}

const String SilverbirdAudioProcessor::getParameterName (int index)
{
    return String("Master");
}

const String SilverbirdAudioProcessor::getParameterText (int index)
{
    return String("OA");
}

const String SilverbirdAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String SilverbirdAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool SilverbirdAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool SilverbirdAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool SilverbirdAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SilverbirdAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SilverbirdAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double SilverbirdAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SilverbirdAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SilverbirdAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SilverbirdAudioProcessor::setCurrentProgram (int index)
{
}

const String SilverbirdAudioProcessor::getProgramName (int index)
{
    return String();
}

void SilverbirdAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SilverbirdAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    mixer.prepareToPlay(samplesPerBlock, sampleRate);
}

void SilverbirdAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void SilverbirdAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    
    /*
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
    */

    AudioSourceChannelInfo channelInfo (&buffer, 0, buffer.getNumSamples());
    mixer.getNextAudioBlock(channelInfo);
    
    AudioPlayHead::CurrentPositionInfo info;
    getPlayHead()->getCurrentPosition(info);
    
    if (positionInfo.isPlaying != info.isPlaying) {
        setPlayPause(info.isPlaying);
    }
    
    positionInfo = info;
    
    // merging incoming midi (from host) into midiCollector
    MidiBuffer::Iterator iterator(midiMessages);
    MidiMessage result;
    int position;
    
    while (iterator.getNextEvent(result, position)) {
        result.setTimeStamp(Time::getMillisecondCounter() / 1000.0);
        mixer.midiCollector.addMessageToQueue(result);
    }
}

//==============================================================================
bool SilverbirdAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SilverbirdAudioProcessor::createEditor()
{
    return new SilverbirdAudioProcessorEditor (*this);
}

//==============================================================================
void SilverbirdAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SilverbirdAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SilverbirdAudioProcessor();
}
