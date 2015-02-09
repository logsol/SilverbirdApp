/*
  ==============================================================================

    PluginController.h
    Created: 9 Feb 2015 11:37:00am
    Author:  Karl

  ==============================================================================
*/

#ifndef PLUGINCONTROLLER_H_INCLUDED
#define PLUGINCONTROLLER_H_INCLUDED

#include "Controller.h"
#include "Gui.h"
#include "PluginProcessor.h"

class PluginController : public Controller
{
public:
    PluginController();
    ~PluginController();
    
    Gui* gui;
    SilverbirdAudioProcessor& processor;
protected:
};


#endif  // PLUGINCONTROLLER_H_INCLUDED
