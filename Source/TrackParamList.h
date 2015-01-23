/*
  ==============================================================================

    TrackParamList.h
    Created: 21 Jan 2015 2:10:57pm
    Author:  Karl

  ==============================================================================
*/

#ifndef TRACKPARAMLIST_H_INCLUDED
#define TRACKPARAMLIST_H_INCLUDED


struct trackParamList {
    float level = 1;
    bool mute = 0;
    int sample = 3;
    float attack = 0;
    float decay = 1;
    float pitch = 0;
    float distort = 0;
    float cutoff = 1;
};


#endif  // TRACKPARAMLIST_H_INCLUDED
