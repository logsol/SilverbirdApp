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
class Ui;


class Controller : public SilverbirdAudioProcessor,
                   public Slider::Listener,
                   public Button::Listener
                   //,public ValueTree::Listener
{
public:
    Controller();
    ~Controller();
    
    void addClockListener(ClockListener* listener);
    void removeClockListener(ClockListener* listener);
    bool togglePlayPause();
    void setPlayPause(bool play);
    void setBpm(float bpm);
    float getBpm();
    
    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    
    AudioProcessorEditor* createEditor() override;
    float getParameter (int index) override;
    void setParameter (int index, float newValue) override;
    
    const String getParameterName (int index) override;
    const String getParameterText (int index) override;
    int getNumParameters() override;
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    static int getParameterId(int paramNameId, int trackId = -1, int cellId = -1);
    Parameter* getParameterByAttrs(int paramNameId, int trackId = -1, int cellId = -1);
    
    void sliderValueChanged (Slider* slider) override;
    void buttonClicked (Button* button) override;
    void onGuiParameterChange (Value& value);
    void setTrackFocus(int trackId);
    
    Sequencer* getMidiSequencerByTrackId(int trackId);
    Sequencer* getModulationSequencerByTrackId(int trackId);

    
    void saveDocument();
    void loadDocument();
    void createDocument();
    
    float getParameterValue(int paramNameId, int trackId = -1);
    float getParameterValueScaled(int paramNameId, int trackId = -1);
    
    void resetStepModulations();
    void addStepModulationValue(int paramId, float value, int trackId);
    
    //void valueTreePropertyChanged (ValueTree& treeWhosePropertyHasChanged, const Identifier& property) override;
    //void valueTreeChildAdded (ValueTree& parentTree, ValueTree& childWhichHasBeenAdded) override {
    //    std::cout << "child added" << std::endl;
    //};
    //void valueTreeChildRemoved (ValueTree& parentTree, ValueTree& childWhichHasBeenRemoved, int indexFromWhichChildWasRemoved) override {};
    //void valueTreeChildOrderChanged (ValueTree& parentTreeWhoseChildrenHaveMoved, int oldIndex, int newIndex) override {};
    //void valueTreeParentChanged (ValueTree& treeWhoseParentHasChanged) override {};

    OwnedArray<Parameter> parameters;
    
    Mixer mixer;
    
    Clock clock;
    Ui* ui;
    
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
    
    ValueTree document;
    UndoManager undoManager;
};

#endif  // CONTROLLER_H_INCLUDED
