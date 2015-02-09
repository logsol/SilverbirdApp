/*
  ==============================================================================

    Knob.cpp
    Created: 4 Feb 2014 2:40:35am
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Knob.h"
#include "BinaryData.h"


Knob::Knob(const String &name)
: Slider(name)
{
    singleImageWidth = 45;
    singleImageHeight = 40;
    setSliderStyle (Slider::RotaryVerticalDrag);
    setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    setSize(singleImageWidth, singleImageHeight);
    setRange (0.0, 100.0, 0.1);
    setScrollWheelEnabled(false);
    setPopupMenuEnabled (false);
}

Knob::~Knob()
{
    deleteAllChildren();
}

//==============================================================================
void Knob::paint(Graphics& g)
{
    double range = getMaximum() - getMinimum();
    
    if (getMinimum() < 0) {
        singleImageWidth = 37;
        singleImageHeight = 32;
    }
    
    Image knobImage = ImageCache::getFromMemory (BinaryData::Knob_png, BinaryData::Knob_pngSize);
    int numImagePics = knobImage.getWidth() / singleImageWidth;
    int imageOffset = singleImageWidth * (int)((numImagePics-1) * getValue()/range);
    
    if (getMinimum() < 0) {
        knobImage = ImageCache::getFromMemory (BinaryData::Knob_Centered_png, BinaryData::Knob_Centered_pngSize);
        numImagePics = knobImage.getWidth() / singleImageWidth;
        imageOffset = singleImageWidth * (int)((numImagePics) * (getValue() - getMinimum())/range);
    }

    g.drawImage(knobImage,
                0, 0, singleImageWidth, singleImageHeight,
                imageOffset, 0, singleImageWidth, singleImageHeight,
                false);
    
}

//==============================================================================
