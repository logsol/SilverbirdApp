/*
  ==============================================================================

    PluginController.cpp
    Created: 9 Feb 2015 11:37:00am
    Author:  Karl

  ==============================================================================
*/

#include "PluginController.h"

PluginController::PluginController()
{
    gui = new Gui(this);
}

PluginController::~PluginController()
{
    delete gui;
}