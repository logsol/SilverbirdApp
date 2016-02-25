/*
  ==============================================================================

    CustomLook.h
    Created: 18 Feb 2015 4:09:42pm
    Author:  Karl

  ==============================================================================
*/

#ifndef CUSTOMLOOK_H_INCLUDED
#define CUSTOMLOOK_H_INCLUDED

#include "JuceHeader.h"

class CustomLook : public LookAndFeel_V3
{
public:
    CustomLook();
    ~CustomLook();
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                            const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override;
    
    void drawLinearSlider (Graphics&, int x, int y, int width, int height,
                           float sliderPos, float minSliderPos, float maxSliderPos,
                           const Slider::SliderStyle, Slider&) override;
    

protected:
    Colour primaryColour;
};


#endif  // CUSTOMLOOK_H_INCLUDED
