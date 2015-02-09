/*
  ==============================================================================

    AppController.h
    Created: 9 Feb 2015 1:23:37pm
    Author:  Karl

  ==============================================================================
*/

#ifndef APPCONTROLLER_H_INCLUDED
#define APPCONTROLLER_H_INCLUDED

#include "JuceHeader.h"
#include "Controller.h"


class AppController : public Controller  {
public:
    AppController();
    ~AppController();
    
protected:
    void bootstrap();
    AudioSourcePlayer audioSourcePlayer;
    AudioDeviceManager audioDeviceManager;
};



#endif  // APPCONTROLLER_H_INCLUDED
