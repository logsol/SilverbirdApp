/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Gui.h"


//==============================================================================
SilverbirdAudioProcessorEditor::SilverbirdAudioProcessorEditor (SilverbirdAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (1076, 639);
    
    addAndMakeVisible (processor.gui);
}

SilverbirdAudioProcessorEditor::~SilverbirdAudioProcessorEditor()
{
}

//==============================================================================
void SilverbirdAudioProcessorEditor::paint (Graphics& g)
{
}

void SilverbirdAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
