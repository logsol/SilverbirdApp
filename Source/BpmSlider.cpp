/*
  ==============================================================================

    BpmSlider.cpp
    Created: 17 Feb 2015 5:06:24pm
    Author:  Karl

  ==============================================================================
*/

#include "JuceHeader.h"
#include "BpmSlider.h"

//==============================================================================
BpmSlider::BpmSlider(String name) : Slider(name)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
}

BpmSlider::~BpmSlider()
{
}

void BpmSlider::paint (Graphics& g)
{
    Slider::paint(g);
}

void BpmSlider::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    Slider::resized();
}
