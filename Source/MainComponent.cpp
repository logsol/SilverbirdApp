/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (1076, 611);
    Image image = ImageCache::getFromMemory (BinaryData::Background_png, BinaryData::Background_pngSize);
    background = new ImageComponent();
    background->setImage(image);
    background->setBounds(0, 0, 1079, 639);
    addAndMakeVisible (background);
    
    button1 = new TextButton ("Kickdrum!");
    button1->setBounds (70, 70, 100, 30);
    button1->addListener(this);
    addAndMakeVisible (button1);
    
    knob = new Knob("myknob", 45, 40);
    knob->setBounds (100, 120, 45, 40);
    knob->setDoubleClickReturnValue (true, 50.0); // double-clicking this slider will set it to 50.0
    addAndMakeVisible (knob);
    
    
    audioDeviceManager = new AudioDeviceManager();
    audioDeviceManager->initialise (2, 2, 0, true, String::empty, 0);
    
    audioSourcePlayer = new AudioSourcePlayer();
    synthAudioSource = new SynthAudioSource(keyboardState);
    
    synthAudioSource->setUsingSampledSound();
    audioSourcePlayer->setSource(synthAudioSource);
    
    audioDeviceManager->addAudioCallback(audioSourcePlayer);
    
    std::cout << "yo run";
}


MainContentComponent::~MainContentComponent()
{
    deleteAllChildren();
    audioSourcePlayer->setSource (nullptr);
    audioDeviceManager->removeAudioCallback(audioSourcePlayer);
    delete audioDeviceManager;
    delete synthAudioSource;
    delete audioSourcePlayer;
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xffeeddff));
    g.setFont (Font (16.0f));
    g.setColour (Colours::black);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
     
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

void MainContentComponent::buttonClicked (Button* button)
{
    synthAudioSource->synth.noteOn(1, 69, 127.0);
}

