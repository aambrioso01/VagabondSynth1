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
    oscMenu.addItem("Sine&Square", 4);
    oscMenu.addItem("Sine&Saw", 5);
    oscMenu.addItem("Saw&Square", 6);
    
    
    addAndMakeVisible(&oscMenu);
    oscMenu.addListener(this);
    
    oscMenu.setJustificationType(Justification::centred);
    
    waveSelection = new AudioProcessorValueTreeState::ComboBoxAttachment (processor.state, "wavetype", oscMenu);
    
    
    //volume knob
    midiVolume.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    midiVolume.setRange(0.0, 127.0, 1.0);
    midiVolume.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
    midiVolume.setPopupDisplayEnabled (true, false, this);
    midiVolume.setValue(1.0);
    addAndMakeVisible (&midiVolume);
    volVal = new AudioProcessorValueTreeState::SliderAttachment(processor.state, "volume", midiVolume);
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
    midiVolume.setBounds (area.removeFromTop(100));
}

void Oscillator::comboBoxChanged(ComboBox* box)
{
    
}