/*
  ==============================================================================

    Parameter.cpp
    Created: 11 Feb 2015 9:54:27pm
    Author:  Karl

  ==============================================================================
*/

#include "Parameter.h"
#include "Controller.h"
#include "Mixer.h"

Parameter::Parameter(int parameterId, int paramNameId, int trackId, int cellId)
  : parameterId(parameterId),
    paramNameId(paramNameId),
    trackId(trackId),
    cellId(cellId)
{
    createName();
}

Parameter::~Parameter()
{
}

String Parameter::createName()
{
    String tempName;
    switch (paramNameId) {
            
        case Controller::params::shuffle:
            tempName = "Shuffle";
            break;
            
        case Controller::params::level:
            tempName = "Level";
            break;
            
        case Controller::params::mute:
            tempName = "Mute";
            break;
            
        case Controller::params::sample:
            tempName = "Sample";
            break;
            
        case Controller::params::pitch:
            tempName = "Pitch";
            break;
            
        case Controller::params::attack:
            tempName = "Attack";
            break;
            
        case Controller::params::decay:
            tempName = "Decay";
            break;
            
        case Controller::params::distort:
            tempName = "Distort";
            break;
            
        case Controller::params::cutoff:
            tempName = "Cutoff";
            break;
            
        default:
            tempName = "<Unknown>";
            break;
    }
    
    if (trackId < 0) {
        name = "Global " + tempName;
        return name;
    }
    
    name = Mixer::getNameByTrackId(trackId) + " " + tempName;
    return name;
}