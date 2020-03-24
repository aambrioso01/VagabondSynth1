/*
  ==============================================================================

    Envelope.cpp
    Created: 23 Mar 2020 11:00:59pm
    Author:  Windows

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Envelope.h"

//==============================================================================
Envelope::Envelope(SynthFrameworkAudioProcessor& p) : processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    setSize(200,200);
    
    //AMBRIOSO
    attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1f, 5000.0f);
    attackSlider.setValue(0.1f);
    attackSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    attackSlider.addListener(this);
    addAndMakeVisible(&attackSlider);
    
    decaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    decaySlider.setRange(1.0f, 2000.0f);
    decaySlider.setValue(1.0f);
    decaySlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    decaySlider.addListener(this);
    addAndMakeVisible(&decaySlider);
    
    sustainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    sustainSlider.setRange(0.1f, 1.0f);
    sustainSlider.setValue(0.8f);
    sustainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    sustainSlider.addListener(this);
    addAndMakeVisible(&sustainSlider);
    
    releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    releaseSlider.setRange(0.1f, 5000.0f);
    releaseSlider.setValue(0.8f);
    releaseSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    releaseSlider.addListener(this);
    addAndMakeVisible(&releaseSlider);
    
    
    attackVal = new AudioProcessorValueTreeState::SliderAttachment (processor.state, "attack", attackSlider);
    decayVal = new AudioProcessorValueTreeState::SliderAttachment (processor.state, "decay", decaySlider);
    sustainVal = new AudioProcessorValueTreeState::SliderAttachment (processor.state, "sustain", sustainSlider);
    releaseVal = new AudioProcessorValueTreeState::SliderAttachment (processor.state, "release", releaseSlider);

}

Envelope::~Envelope()
{
}

void Envelope::paint (Graphics& g)
{
    g.fillAll(Colours::white);
}

void Envelope::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    
    Rectangle<int> area = getLocalBounds().reduced(40);
    
    //AMBRIOSO
    attackSlider.setBounds(10, 10, 40, 100);
    decaySlider.setBounds(60, 10, 40, 100);
    sustainSlider.setBounds(110, 10, 40, 100);
    releaseSlider.setBounds(160, 10, 40, 100);

}


void Envelope::sliderValueChanged(Slider* slider)
{
    /*
    if (slider == &attackSlider)
    {
        processor.attackTime = attackSlider.getValue();
    }
    
    if (slider == &releaseSlider)
    {
        processor.releaseTime = releaseSlider.getValue();
    }
    */
}
