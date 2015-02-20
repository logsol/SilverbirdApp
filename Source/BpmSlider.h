/*
  ==============================================================================

    BpmSlider.h
    Created: 17 Feb 2015 5:06:24pm
    Author:  Karl

  ==============================================================================
*/

#ifndef BPMSLIDER_H_INCLUDED
#define BPMSLIDER_H_INCLUDED

#include "JuceHeader.h"

//==============================================================================
/*
*/
class BpmSlider    : public Slider
{
public:
    BpmSlider(String name);
    ~BpmSlider();

    void paint (Graphics&);
    void resized();

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BpmSlider)
};


#endif  // BPMSLIDER_H_INCLUDED
