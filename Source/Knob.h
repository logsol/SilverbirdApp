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
#include "Parameter.h"

class Knob
: public Slider
{
public:
    //==============================================================================
    Knob(const String &name);
    ~Knob();
    
    //void paint(Graphics& g) override;
    void setBaseCenter(bool isCentered);
    void setStepSize(float stepSize);
    bool getIsCentered();
    void setParameter(Parameter* p);
    Parameter* getParameter();
    
protected:
    //==============================================================================
    Parameter* parameter = nullptr;
    Image* image;
    int singleImageWidth;
    int singleImageHeight;
    bool useCenteredImage = false;
    bool isCentered = false;
};


#endif  // KNOB_H_INCLUDED
