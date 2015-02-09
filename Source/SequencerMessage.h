/*
  ==============================================================================

    SequencerMessage.h
    Created: 23 Jan 2015 12:46:41pm
    Author:  Karl

  ==============================================================================
*/

#ifndef SEQUENCERMESSAGE_H_INCLUDED
#define SEQUENCERMESSAGE_H_INCLUDED

#include "JuceHeader.h"

class SequencerMessage : public Message
{
public:
    
    int type;
    int trackId;
    int cellId;
    int value;
    
    enum types {
        type_note,
        type_modulation
    };
    
    
};



#endif  // SEQUENCERMESSAGE_H_INCLUDED
