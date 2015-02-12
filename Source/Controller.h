/*
  ==============================================================================

    Controller.h
    Created: 9 Mar 2014 3:22:47pm
    Author:  Pannek Karl

  ==============================================================================
*/

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "JuceHeader.h"
#include "Processor.h"
#include "Source.h"
#include "Mixer.h"
#include "Clock.h"
#include "ClockListener.h"
#include "Sequencer.h"
#include "Knob.h"
#include "Gui.h"

class Controller : public SilverbirdAudioProcessor,
                   public Slider::Listener,
                   public Button::Listener
{
public:
    Controller();
    virtual ~Controller();
    
    void addClockListener(ClockListener* listener);
    void removeClockListener(ClockListener* listener);
    void togglePlayPause();
    void setPlayPause(bool play);
    
    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    
    AudioProcessorEditor* createEditor() ;
    void setParameter (int index, float newValue) override;
    
    //int getNumParameters() override;
    //float getParameter (int index) override;
    
    const String getParameterName (int index) override;
    const String getParameterText (int index) override;
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    static int getParameterId(int paramNameId, int trackId = -1, int cellId = -1);
    Parameter* getParameterByAttrs(int paramNameId, int trackId = -1, int cellId = -1);
    
    void sliderValueChanged (Slider* slider) override;
    void buttonClicked (Button* button) override;
    void onGuiParameterChange (Value& value);


    OwnedArray<Parameter> parameters;
    
    Mixer mixer;
    Clock clock;
    Sequencer sequencer;
    
    struct params {
        enum {
            shuffle,
            level,
            mute,
            sample,
            pitch,
            attack,
            decay,
            distort,
            cutoff,
            max
        };
    };
    
protected:
    AudioPlayHead::CurrentPositionInfo positionInfo;
};

#endif  // CONTROLLER_H_INCLUDED
