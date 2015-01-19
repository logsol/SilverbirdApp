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
#include "Mixer.h"

class Controller  {
public:
    Controller();
    ~Controller();
    
    int getSelectedTrack();
    void setSelectedTrack(int trackId);
    
    Mixer mixer;

protected:
    void bootstrap();
    AudioSourcePlayer audioSourcePlayer;
    AudioDeviceManager audioDeviceManager;
    
    int selectedTrack = 0;
};



#endif  // CONTROLLER_H_INCLUDED
