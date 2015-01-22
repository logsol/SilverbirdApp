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

    const String input ((MidiInput::getDevices())[0]);
    
    if (! audioDeviceManager.isMidiInputEnabled (input)) {
        audioDeviceManager.setMidiInputEnabled (input, true);
    }
    std::cout << "Midi Device: " << input << std::endl;
    
    
    // not using automatic contructors here for readability
    // and because clock's owned array breaks on shutdown.
    
    sequencer = new Sequencer(mixer.midiCollector);
    clock = new Clock();
    
    clock->addListener(sequencer);
}

int Controller::getSelectedTrack() {
    return 0;
}

void Controller::setSelectedTrack(int trackId) {
}

void Controller::addClockListener(ClockListener* listener)
{
    clock->addListener(listener);
}

void Controller::removeClockListener(ClockListener* listener)
{
    clock->removeListener(listener);
}
