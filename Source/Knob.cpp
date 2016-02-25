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

    setColour(ColourIds::rotarySliderFillColourId, Colour(0xff, 0xeb, 0x86));
    setColour(ColourIds::rotarySliderOutlineColourId, Colour(0x00, 0x00, 0x00).withAlpha(0.3f));

    // linear style
    setColour(ColourIds::thumbColourId, Colour(0xff, 0xeb, 0x86));
    setColour(ColourIds::backgroundColourId, Colour(0x45, 0x45, 0x45).withAlpha(0.5f));

    
    //findColour(ColourIds::rotarySliderOutlineColourId));
}

Knob::~Knob()
{
    deleteAllChildren();
}

/*
void Knob::paint(Graphics& g)
{
    double range = getMaximum() - getMinimum();
    
    Image knobImage = ImageCache::getFromMemory (BinaryData::Knob_png, BinaryData::Knob_pngSize);
    int numImagePics = knobImage.getWidth() / singleImageWidth;
    int imageOffset = singleImageWidth * (int)((numImagePics-1) * getValue()/range);
    
    if (useCenteredImage) {
        knobImage = ImageCache::getFromMemory (BinaryData::Knob_Centered_png, BinaryData::Knob_Centered_pngSize);
        numImagePics = knobImage.getWidth() / singleImageWidth;
        imageOffset = singleImageWidth * (int)((numImagePics) * (getValue() - getMinimum())/range);
    }

    g.drawImage(knobImage,
                (getWidth()-singleImageWidth), 0, singleImageWidth, singleImageHeight,
                imageOffset, 0, singleImageWidth, singleImageHeight,
                false);
    
}
 */

void Knob::setBaseCenter(bool isCentered) {
    
    this->isCentered = isCentered;
    return;
    
    if (isCentered) {
        singleImageWidth = 37;
        singleImageHeight = 32;
        
        useCenteredImage = true;
    }
}

bool Knob::getIsCentered()
{
    return isCentered;
}

void Knob::setStepSize(float stepSize)
{
    setRange(getMinimum(), getMaximum(), stepSize);
}