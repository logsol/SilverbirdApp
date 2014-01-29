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
    
    button1 = new TextButton ("Button 1");
    button1->setBounds (20, 70, 260, 20);
    addAndMakeVisible (button1);
}


MainContentComponent::~MainContentComponent()
{
    deleteAllChildren();

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
