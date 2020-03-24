/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthFrameworkAudioProcessorEditor::SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 200);
    
    addAndMakeVisible(&oscGui);
    
    
    //AMBRIOSO
    attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1f, 5000.0f);
    attackSlider.setValue(0.1f);
    attackSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20.0, 10.0);
    attackSlider.addListener(this);
    addAndMakeVisible(&attackSlider);
    
    sliderTree = new AudioProcessorValueTreeState::SliderAttachment (processor.state, "attack", attackSlider);
    
}

SynthFrameworkAudioProcessorEditor::~SynthFrameworkAudioProcessorEditor()
{
}

//==============================================================================
void SynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Ragtag Records", getLocalBounds(), Justification::centred, 1);
}

void SynthFrameworkAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    Rectangle<int> area = getLocalBounds();
    const int componentWidth = 200;
    const int componentHeight = 200;
    
    oscGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    
    //AMBRIOSO
    attackSlider.setBounds(10, 10, 40, 100);
}

void SynthFrameworkAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (slider == &attackSlider)
    {
        processor.attackTime = attackSlider.getValue();
    }
}