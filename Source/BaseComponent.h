/*
  ==============================================================================

    BaseComponent.h
    Created: 26 Feb 2016 11:56:11am
    Author:  Karl

  ==============================================================================
*/

#ifndef BaseComponent_H_INCLUDED
#define BaseComponent_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Controller.h"

//==============================================================================
/*
*/
class BaseComponent    : public Component
{
public:
    BaseComponent(Controller* controller, String componentId = "");
    ~BaseComponent();

protected:
    Controller* controller;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BaseComponent)
};


#endif  // BaseComponent_H_INCLUDED
