/*
  ==============================================================================

    SynthSound.h
    Created: 14 Mar 2020 1:31:50pm
    Author:  AMBRIOSO

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public SynthesiserSound
{
    public:
    
    bool appliesToNote (int /*midiNoteNumber*/)
    {
        return true;
    }
    
    bool appliesToChannel (int /*midiChannel*/)
    {
        return true;
    }
    
};