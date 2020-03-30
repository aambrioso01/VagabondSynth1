#include <JuceHeader.h>
#include "Oscillator.h"

Oscillator::Oscillator(SynthFrameworkAudioProcessor& p) : processor(p)
{
    setSize(200, 200);
    
    // waveform menu
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
    
    /*
    // default volume knob
    midiVolume.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    midiVolume.setRange(0.0, 127.0, 1.0);
    midiVolume.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
    midiVolume.setPopupDisplayEnabled (true, false, this);
    //midiVolume.setValue(1.0);
    addAndMakeVisible (&midiVolume);
    volVal = new AudioProcessorValueTreeState::SliderAttachment(processor.state, "volume", midiVolume);
    midiVolume.setSkewFactorFromMidPoint(80);
    */

    
    // custom knobs JARVIS
    addAndMakeVisible(midiVolume);
    midiVolume.setLookAndFeel(&dirtyLookAndFeel1);
    midiVolume.setSliderStyle(Slider::Rotary);
    midiVolume.setTextBoxStyle(Slider::TextBoxBelow, false, 45, 16);
    volVal = new AudioProcessorValueTreeState::SliderAttachment(processor.state, "volume", midiVolume);
    
    
    /* harmonizer on/off button
    addAndMakeVisible(&harmonButton);
    harmonButton.setButtonText("Harmonzier");

    addAndMakeVisible(&harmonLabel);
    harmonLabel.setColour(Label::backgroundColourId, Colours::darkred);
    harmonLabel.setColour(Label::textColourId, Colours::white);
    harmonLabel.setJustificationType(Justification::centred);
    */
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
    
    int sKnobSize = 64;

    //midiVolume.setBounds (area.removeFromTop(100));
    //midiVolume->setBounds(50 - sKnobSize / 2, 300, sKnobSize, sKnobSize);
    midiVolume.setBounds(75, 75, sKnobSize, sKnobSize);
}

void Oscillator::comboBoxChanged(ComboBox* box)
{
    
}