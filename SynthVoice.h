/*
  ==============================================================================

    SynthVoice.h
    Created: 14 Mar 2020 1:32:05pm
    Author:  Windows

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
    
    void getParam (std::atomic<float>* attack, std::atomic<float>* decay, std::atomic<float>* sustain, std::atomic<float>* release)
    {
        env1.setAttack(double(*attack));
        env1.setDecay(double(*decay));
        env1.setSustain(double(*sustain));
        env1.setRelease(double(*release));
    }

    void getOscType (std::atomic<float>* selection)
    {
        theWave = *selection;
    }
    
    double setOscType ()
    {
        if (theWave == 0)
        {
            return osc1.sinewave(frequency);
        }
        
        if (theWave == 1)
        {
            return osc1.saw(frequency);
        }
        
        if (theWave == 2)
        {
            return osc1.square(frequency);
        }
        
        else
        {
            return osc1.sinewave(frequency);
        }
            
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
       
        for (int sample = 0; sample < numSamples; ++ sample)
        {
            //double theWave = osc1.sinewave(frequency);
            double theSound = env1.adsr(setOscType(), env1.trigger) * level;
            
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
        int theWave;
        
        maxiOsc osc1;
        maxiEnv env1;

};