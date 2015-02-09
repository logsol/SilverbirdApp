/*
  ==============================================================================

    AppController.cpp
    Created: 9 Feb 2015 1:23:37pm
    Author:  Karl

  ==============================================================================
*/

#include "AppController.h"

AppController::AppController()
{
    bootstrap();
}

AppController::~AppController()
{
}

void AppController::bootstrap()
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
}
