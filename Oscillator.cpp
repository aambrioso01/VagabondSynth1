/*
  ==============================================================================

    Oscillator.cpp
    Created: 16 Mar 2020 3:58:37pm
    Author:  Windows

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Oscillator.h"

Oscillator::Oscillator(SynthFrameworkAudioProcessor& p) : processor(p)
{
    setSize(200, 200);
    
    oscMenu.addItem("Sine", 1);
    oscMenu.addItem("Saw", 2);
    oscMenu.addItem("Square", 3);
    
    addAndMakeVisible(&oscMenu);
    oscMenu.addListener(this);
    
    oscMenu.setJustificationType(Justification::centred);
    
    waveSelection = new AudioProcessorValueTreeState::ComboBoxAttachment (processor.state, "wavetype", oscMenu);
}

Oscillator::~Oscillator()
{
    
}

void Oscillator::paint (Graphics& g)
{
    
}

void Oscillator::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);
    
    oscMenu.setBounds(area.removeFromTop(20));
}

void Oscillator::comboBoxChanged(ComboBox* box)
{
    
}