/*
  ==============================================================================

    Knob.h
    Created: 4 Feb 2014 2:40:35am
    Author:  Pannek Karl

  ==============================================================================
*/

#ifndef KNOB_H_INCLUDED
#define KNOB_H_INCLUDED


#include "JuceHeader.h"

class Knob
: public Slider
{
public:
    //==============================================================================
    Knob(const String &name);
    ~Knob();
    
    void paint(Graphics& g) override;
    void setBaseCenter(bool isCentered);
    void setStepSize(float stepSize);
    
protected:
    //==============================================================================
    Image* image;
    int singleImageWidth;
    int singleImageHeight;
    bool useCenteredImage = false;
};


#endif  // KNOB_H_INCLUDED
