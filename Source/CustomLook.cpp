/*
  ==============================================================================

    CustomLook.cpp
    Created: 18 Feb 2015 4:09:42pm
    Author:  Karl

  ==============================================================================
*/

#include "CustomLook.h"
#include "Knob.h"

CustomLook::CustomLook()
{


}

CustomLook::~CustomLook()
{

}



void CustomLook::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                       const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
    const float radius = jmin (width / 2, height / 2) - 2.0f;
    const float centreX = x + width * 0.5f;
    const float centreY = y + height * 0.5f;
    const float rx = centreX - radius;
    const float ry = centreY - radius;
    const float rw = radius * 2.0f;
    const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    const bool isMouseOver = slider.isMouseOverOrDragging() && slider.isEnabled();
    
    if (true || radius > 12.0f) // added true
    {
        if (slider.isEnabled())
            g.setColour (slider.findColour (Slider::rotarySliderFillColourId).withAlpha (1.0f));
        else
            g.setColour (Colour (0x80808080));
        
        const float thickness = 0.75f;
        

        float rsa = rotaryStartAngle;
        
        if (Knob* knob = dynamic_cast<Knob*>(&slider)) {
            if(knob->getIsCentered()) {
                
                g.drawLine(centreX, centreY-radius*thickness-1.0f, centreX, centreY-radius+1.0f);
                
                rsa = rotaryStartAngle + (rotaryEndAngle - rotaryStartAngle ) / 2;
            }
        }


        {
            Path filledArc;
            filledArc.addPieSegment (rx, ry, rw, rw, rsa, angle, thickness);
            g.fillPath (filledArc);
        }
        
        /*
        {
            const float innerRadius = radius * 0.2f;
            Path p;
            p.addTriangle (-innerRadius, 0.0f,
                           0.0f, -radius * thickness * 1.1f,
                           innerRadius, 0.0f);
            
            p.addEllipse (-innerRadius, -innerRadius, innerRadius * 2.0f, innerRadius * 2.0f);
            
            g.fillPath (p, AffineTransform::rotation (angle).translated (centreX, centreY));
        }
        */
        
        if (slider.isEnabled())
            g.setColour (slider.findColour (Slider::rotarySliderOutlineColourId));
        else
            g.setColour (Colour (0x80808080));
        
        Path outlineArc;
        outlineArc.addPieSegment (rx, ry, rw, rw, rotaryStartAngle, rotaryEndAngle, thickness);
        outlineArc.closeSubPath();
        
        g.strokePath (outlineArc, PathStrokeType (slider.isEnabled() ? (1.0f) : 0.3f));
        
        
    }
    else
    {
        if (slider.isEnabled())
            g.setColour (slider.findColour (Slider::rotarySliderFillColourId).withAlpha (isMouseOver ? 1.0f : 0.7f));
        else
            g.setColour (Colour (0x80808080));
        
        Path p;
        p.addEllipse (-0.4f * rw, -0.4f * rw, rw * 0.8f, rw * 0.8f);
        PathStrokeType (rw * 0.1f).createStrokedPath (p, p);
        
        p.addLineSegment (Line<float> (0.0f, 0.0f, 0.0f, -radius), rw * 0.2f);
        
        g.fillPath (p, AffineTransform::rotation (angle).translated (centreX, centreY));
    }

    
    if (Knob* knob = dynamic_cast<Knob*>(&slider)) {
    
        g.setColour (slider.findColour (Slider::rotarySliderFillColourId).withAlpha (0.6f));
        g.setFont (11.0f);
        g.drawText((String) knob->getParameter()->getDisplayValue(), 0, 0, width, height, Justification::centred);
    }
}


void CustomLook::drawLinearSlider (Graphics& g, int x, int y, int width, int height,
                                       float sliderPos, float minSliderPos, float maxSliderPos,
                                       const Slider::SliderStyle style, Slider& slider)
{
    g.fillAll (slider.findColour (Slider::backgroundColourId));
    
    if (style == Slider::LinearBar || style == Slider::LinearBarVertical)
    {
        const float fx = (float) x, fy = (float) y, fw = (float) width, fh = (float) height;
        
        Path p;
        
        if (style == Slider::LinearBarVertical)
            p.addRectangle (fx, sliderPos, fw, 1.0f + fh - sliderPos);
        else
            p.addRectangle (fx, fy, sliderPos - fx, fh);
        
        Colour baseColour (slider.findColour (Slider::thumbColourId));
//                           .withMultipliedSaturation (slider.isEnabled() ? 1.0f : 0.5f)
//                           .withMultipliedAlpha (0.8f));
        
        g.setGradientFill (ColourGradient (baseColour.brighter (0.08f), 0.0f, 0.0f,
                                           baseColour.darker (0.08f), 0.0f, (float) height, false));
        g.fillPath (p);
        
//        g.setColour (baseColour.darker (0.2f));
        
        if (style == Slider::LinearBarVertical)
            g.fillRect (fx, sliderPos, fw, 1.0f);
        else
            g.fillRect (sliderPos, fy, 1.0f, fh);
    }
    else
    {
        drawLinearSliderBackground (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
        drawLinearSliderThumb (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
    }
}
