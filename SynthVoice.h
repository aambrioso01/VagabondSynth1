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
    
    void getEnvelopeParams (std::atomic<float>* attack, std::atomic<float>* decay, std::atomic<float>* sustain, std::atomic<float>* release)
    {
        env1.setAttack(double(*attack));
        env1.setDecay(double(*decay));
        env1.setSustain(double(*sustain));
        env1.setRelease(double(*release));
    }
    
    double setEnvelope ()
    {
        return env1.adsr(setOscType(), env1.trigger);
    }

    void getOscType (std::atomic<float>* selection)
    {
        theWave = *selection;
    }
    
    void getFilterParams (std::atomic<float>* filterType, std::atomic<float>* filterCutoff, std::atomic<float>* filterRes)
    {
        filterChoice = *filterType;
        cutoff = *filterCutoff;
        resonance = *filterRes;
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
        
        // combo oscillators need work, sounds bad
        if (theWave == 3)
        {
            double sinSquare;
            sinSquare = (osc1.sinewave(frequency) + osc1.square(frequency)) / 2;
            return sinSquare;
        }
        
        if (theWave == 4)
        {
            double sinSaw;
            sinSaw = (osc1.sinewave(frequency) + osc1.saw(frequency)) / 2;
            return sinSaw;
        }
        
        if (theWave == 5)
        {
            double sawSquare;
            sawSquare = (osc1.saw(frequency) + osc1.square(frequency)) / 2;
            return sawSquare;
        }
            
        else
        {
            return osc1.sinewave(frequency);
        }
            
    }
    /* Maximilian filters, not stable
    
    double setFilter ()
    {
        if (filterChoice == 0)
        {
            return filter1.lores(setEnvelope(), cutoff, resonance);
        }
        
        if (filterChoice == 1)
        {
            return filter1.hires(setEnvelope(), cutoff, resonance);
        }
        
        maxilimain band pass needs work
        if (filterChoice == 2)
        {
            return filter1.bandpass(setEnvelope(), cutoff, resonance);
        }
        
        
        else
        {
            return filter1.lores(setEnvelope(), cutoff, resonance);
        }
    }
    */
    
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
        frequency = frequency + 50.0;
    }
    
    void controllerMoved (int controllerNumber, int newControllerValue)
    {
        
    }
    
    void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
    {
       
        for (int sample = 0; sample < numSamples; ++ sample)
        {
            
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                    outputBuffer.addSample(channel, startSample, setEnvelope() * 0.3f);
            }
            
            ++startSample;
        }   
    }
    
    //=============================================
    
    private:
        
        double level;
        double frequency;
        int theWave;
        
        int filterChoice;
        float cutoff;
        float resonance;
        
        maxiOsc osc1;
        maxiEnv env1;
        //maxiFilter filter1;

};