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
    button1->setBounds (70, 70, 100, 20);
    button1->addListener(this);
    button1->setTriggeredOnMouseDown(true);
    addAndMakeVisible (button1);
    
    button2 = new TextButton ("Snare!");
    button2->setBounds (70, 100, 100, 20);
    button2->addListener(this);
    button2->setTriggeredOnMouseDown(true);
    addAndMakeVisible (button2);
    
    button3 = new TextButton ("Hihat!");
    button3->setBounds (70, 130, 100, 20);
    button3->addListener(this);
    button3->setTriggeredOnMouseDown(true);
    addAndMakeVisible (button3);
    
    knob = new Slider("Master"/*, 45, 40*/);
    knob->setBounds (100, 220, 45, 40);
    knob->setDoubleClickReturnValue (true, 50.0); // double-clicking this slider will set it to 50.0
    knob->setSkewFactor(0.33);
    knob->addListener(this);
    knob->setSliderStyle (Slider::RotaryVerticalDrag);
    knob->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    knob->setSize(50, 70);
    knob->setRange (0.0, 1.0, 0.001);
    knob->setScrollWheelEnabled(false);
    knob->setPopupMenuEnabled (false);
    knob->setValue(3);
    addAndMakeVisible (knob);
    
    
    selectKnob = new Slider("Select"/*, 45, 40*/);
    selectKnob->setBounds (200, 220, 45, 40);
    selectKnob->setDoubleClickReturnValue (true, 50.0); // double-clicking this slider will set it to 50.0
    selectKnob->addListener(this);
    selectKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    selectKnob->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    selectKnob->setSize(50, 70);
    selectKnob->setRange (0.0, 4, 1);
    selectKnob->setScrollWheelEnabled(false);
    selectKnob->setPopupMenuEnabled (false);
    selectKnob->setValue(3);
    addAndMakeVisible (selectKnob);
    
    
    audioDeviceManager = new AudioDeviceManager();
    audioDeviceManager->initialise (2, 2, 0, true, String::empty, 0);
    
    audioSourcePlayer = new AudioSourcePlayer();
    synthAudioSource = new SynthAudioSource(keyboardState);
    
    audioSourcePlayer->setSource(synthAudioSource);
    
    audioDeviceManager->addAudioCallback(audioSourcePlayer);
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
    if(button == button1) {
        synthAudioSource->synth.noteOn(1, 36, 127.0);
    } else if (button == button2) {
        synthAudioSource->synth.noteOn(1, 38, 127.0);
    } else if (button == button3) {
        synthAudioSource->synth.noteOn(1, 42, 127.0);
    }
}

void MainContentComponent::sliderValueChanged(Slider* slider) {
    if(slider == knob) {
        synthAudioSource->setGain(slider->getValue() / 100);
    } else if (slider == selectKnob) {
        synthAudioSource->synth.kickTrack.setSelection(slider->getValue());
    }
    
 }
