/*
  ==============================================================================

    Controller.cpp
    Created: 9 Mar 2014 3:22:47pm
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Controller.h"



Controller::Controller() : source(keyboardState)
{
    bootstrap();
    
    std::cout << "setting up midi device: " << MidiInput::getDevices()[0];
    audioDeviceManager.setMidiInputEnabled (MidiInput::getDevices()[0], true);
}

Controller::~Controller()
{

}

void Controller::bootstrap()
{
    audioDeviceManager.initialise (2, 2, 0, true, String::empty, 0);
    audioSourcePlayer.setSource(&source);
    audioDeviceManager.addAudioCallback(&audioSourcePlayer);
    audioDeviceManager.addMidiInputCallback (String::empty, &(source.midiCollector));
}

int Controller::getSelectedTrack() {
    return selectedTrack;
}

void Controller::setSelectedTrack(int trackId) {
    selectedTrack = trackId;
}

void Controller::playNote(int note) {
    // params: channel, note, velocity 0-1
    keyboardState.noteOn(1, note, 1);
}

void Controller::editTrack(int sampleId){
    
    int trackId = getSelectedTrack();
    
    Track* track;
    track = source.getTrackByIndex(trackId);
    track->setSelection(sampleId);
}

void Controller::setMaster(float value) {
	source.setMaster(value);
}

void Controller::setTrackVolume(float value, int trackIndex) {
    source.setTrackVolume(value, trackIndex);
}

