/*
  ==============================================================================

    SynthVoice.h
    Created: 14 Mar 2020 1:32:05pm
    Author:  AMBRIOSO

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"
#include "src\maximilian.h"

class SynthVoice : public SynthesiserVoice
{
    public:
    
    bool canPlaySound (SynthesiserSound* sound)
    {
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    
    void getParam (float* attack)
    {
        env1.setAttack(double(*attack));
    }
    
    /* What happens when a note is pressed */
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
    {
        env1.trigger = 1;
        level = velocity;
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    }
    
    /* What happens when a note stops being pressed */
    void stopNote (float velocity, bool allowTailOff)
    {
        env1.trigger = 0;
        allowTailOff = true;
        
        if (velocity == 0)
            clearCurrentNote();
    }
    
    /* What happens when the pitch wheel changes position */
    void pitchWheelMoved (int newPitchWheelValue)
    {
        
    }
    
    void controllerMoved (int controllerNumber, int newControllerValue)
    {
        
    }
    
    void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
    {
        
        env1.setDecay(500);
        env1.setSustain(0.8);
        env1.setRelease(500);
       
        for (int sample = 0; sample < numSamples; ++ sample)
        {
            double theWave = osc1.sinewave(frequency);
            double theSound = env1.adsr(theWave, env1.trigger) * level;
            
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                    outputBuffer.addSample(channel, startSample, theSound);
            }
            
            ++startSample;
        }   
    }
    
    //=============================================
    
    private:
        
        double level;
        double frequency;
        
        maxiOsc osc1;
        maxiEnv env1;

};