/*
  ==============================================================================

    Controller.cpp
    Created: 9 Mar 2014 3:22:47pm
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Controller.h"


Controller::Controller()
{
    bootstrap();
}

Controller::~Controller()
{
}

void Controller::bootstrap()
{
    audioDeviceManager.initialise (2, 2, 0, true, String::empty, 0);
    audioSourcePlayer.setSource(&mixer);
    audioDeviceManager.addAudioCallback(&audioSourcePlayer);
    
    audioDeviceManager.addMidiInputCallback (String::empty, &(mixer.midiCollector));
}

int Controller::getSelectedTrack() {
    return 0;
}

void Controller::setSelectedTrack(int trackId) {
}
