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
    clock.setGlobalParams(&mixer.globalParams);
    clock.addListener(&sequencer);
}

Controller::~Controller()
{
}

void Controller::addClockListener(ClockListener* listener)
{
    clock.addListener(listener);
}

void Controller::removeClockListener(ClockListener* listener)
{
    clock.removeListener(listener);
}

void Controller::togglePlayPause()
{
    clock.togglePlayPause();
}

void Controller::setPlayPause(bool play)
{
    clock.setPlayPause(play);
}

void Controller::setParameter(int parameterIndex, float value)
{
}

const String getName()
{
    return "SilverBird";
}

/*
int Controller::getParamId(int paramId, bool isGlobal, int trackId, int cellId)
{
    if (isGlobal) {
        return paramId;
    }
    
    if (trackId > 0) {
        
        if (cellId > 0) {
        }
        
        //return Controller::Param::max * trackId;
    }
    
    */
    
    /*
    i=0;
    
    while (globalParams as globalParam) {
        ++i
    }
    
    while (tracks as track) {
        while (trackParams as trackParam) {
            ++i;
        }
    }
    
     */
/*
    return 0;
}
*/