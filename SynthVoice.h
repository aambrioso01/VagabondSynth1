#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"
#include "src/maximilian.h"

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
        return env1.adsr((setOscType()), env1.trigger);
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

    
    void getOscVolume (std::atomic<float>* volume)
    {
        newVol = double(*volume);
    }
    /*
        cout << (newVol);

        processedBuffer.clear();

        MidiBuffer::Iterator it(midiMessages);
        MidiMessage currentMessage;
        int samplePos;
        
        while(it.getNextEvent(currentMessage, samplePos))
		{
			if (currentMessage.isNoteOn())
			{
				//currentMessage = MidiMessage::noteOn(currentMessage.getChannel(), currentMessage.getNoteNumber(), newVol);
                currentMessage.setVelocity(newVol);
            }
			else if (currentMessage.isNoteOff())
			{
			}
			else if (currentMessage.isAftertouch())
			{
			}
			else if (currentMessage.isPitchWheel())
			{
			}

			processedBuffer.addEvent(currentMessage, samplePos);
		}

       midiMessages.swapWith(processedBuffer);

        
        /* append our modified MIDI signals to this new buffer before swapping it with the original
        MidiBuffer processedMidi;
        int time;
        MidiMessage m;
 
        for (MidiBuffer::Iterator i (midiMessages); i.getNextEvent (m, time);)
        {
            if (m.isNoteOn())
            {
                uint8 newVel = (uint8)noteOnVel;
                m = MidiMessage::noteOn(m.getChannel(), m.getNoteNumber(), newVel);
            }
            else if (m.isNoteOff())
            {
            }
            else if (m.isAftertouch())
            {
            }
            else if (m.isPitchWheel())
            {
            }
    
            processedMidi.addEvent (m, time);
        }
 
        midiMessages.swapWith (processedMidi);
        
    }
    */
    
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
        
        // combo oscillators need work
        // sinSquare does avg and others do nothing
        if (theWave == 3)
        {
            return osc1.sinSquare(frequency);
        }
        
        if (theWave == 4)
        {
            return osc1.sinSaw(frequency);
        }
        
        if (theWave == 5)
        {
            return osc1.sawSquare(frequency);
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
        // bad math
        frequency = frequency + 50.0;
    }
    
    void controllerMoved (int controllerNumber, int newControllerValue)
    {
        
    }
    

    //void renderNextBlock(AudioBuffer<float>&, int, int, std::atomic<float>*) override;
    /*
    void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
    {
        for (int channel = 0; channel < totalNumInputChannels; ++channel)
        {
            float* channelData = outputBuffer.getWritePointer(channel);

            //JARVIS AUDIO PROCESSING
            for (int sample = 0; sample < outputBuffer.getNumSamples(); sample++)
            {
                float cleanSig = *channelData;

                *channelData *= drive * input;

                *channelData = ((((2.f / float_Pi) * atan(*channelData) * blend) + (cleanSig * (1.f - blend))) / 2.f) * output;

                ++channelData;
            }
        }
    }
    */

    // OLD NEXT BLOCK
    void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
    {

        for (int sample = 0; sample < numSamples; ++ sample)
        {
            
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                    outputBuffer.addSample(channel, startSample, setEnvelope());
            }
   
            ++startSample;
        }

        for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
        {
            float* channelData = outputBuffer.getWritePointer(channel);

            //JARVIS AUDIO PROCESSING
            for (int sample = 0; sample < outputBuffer.getNumSamples(); sample++)
            {
                *channelData *= newVol;

                ++channelData;
            }
        }
    }
    
    
    
    //=============================================
    
    private:
        
        double newVol;
        MidiBuffer processedBuffer;
    
        double level;
        double frequency;
        int theWave;
        
        int filterChoice;
        float cutoff;
        float resonance;
        
        maxiOsc osc1;
        maxiOsc osc2;
        maxiEnv env1;
        //maxiFilter filter1;

};