/*
  ==============================================================================

    Controller.h
    Created: 9 Mar 2014 3:22:47pm
    Author:  Pannek Karl

  ==============================================================================
*/

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Source.h"

class Controller  {
public:
    Controller();
    ~Controller();
    
    //int getSelectedTrack();
    void playNote(int note);
    void setTrackSample(int selection);
    void setMaster(float value);

        AudioDeviceManager audioDeviceManager;
    
protected:
    void bootstrap();
    
    Source source;
    MidiKeyboardState keyboardState;
    AudioSourcePlayer audioSourcePlayer;
    
    int selectedTrack = 0;
};



#endif  // CONTROLLER_H_INCLUDED
