/*
  ==============================================================================

    BaseComponent.cpp
    Created: 26 Feb 2016 11:56:11am
    Author:  Karl

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "BaseComponent.h"

//==============================================================================
BaseComponent::BaseComponent(Controller* controller) : controller(controller)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
}

BaseComponent::~BaseComponent()
{
    controller = nullptr;
}
