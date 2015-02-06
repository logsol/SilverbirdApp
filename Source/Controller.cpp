/*
  ==============================================================================

    Controller.cpp
    Created: 9 Mar 2014 3:22:47pm
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Controller.h"


Controller::Controller() : sequencer(mixer)
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
    std::cout << "Audio Device: " << audioDeviceManager.getCurrentAudioDevice()->getName() << std::endl;
    std::cout << "Midi Device: " << input << std::endl;
    
    clock.addListener(&sequencer);
}

void Controller::addClockListener(ClockListener* listener)
{
    clock.addListener(listener);
}

void Controller::removeClockListener(ClockListener* listener)
{
    clock.removeListener(listener);
}
