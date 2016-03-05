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
BaseComponent::BaseComponent(Controller* controller, String componentId) : controller(controller)
{
    setComponentID(componentId);
}

BaseComponent::~BaseComponent()
{
    controller = nullptr;
}
