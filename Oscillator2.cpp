#include <JuceHeader.h>
#include "Oscillator2.h"

Oscillator2::Oscillator2(SynthFrameworkAudioProcessor& p) : processor(p)
{
    setSize(200, 200);
    
    // waveform menu
    oscMenu2.addItem("Sine", 1);
    oscMenu2.addItem("Saw", 2);
    oscMenu2.addItem("Square", 3);
    oscMenu2.addItem("Sine&Square", 4);
    oscMenu2.addItem("Sine&Saw", 5);
    oscMenu2.addItem("Saw&Square", 6);
    
    
    addAndMakeVisible(&oscMenu2);
    oscMenu2.addListener(this);
    
    oscMenu2.setJustificationType(Justification::centred);
    
    waveSelection2 = new AudioProcessorValueTreeState::ComboBoxAttachment (processor.state, "wavetype2", oscMenu2);
    
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

    
    // custom knobs and attachment
    addAndMakeVisible(midiVolume2);
    midiVolume2.setLookAndFeel(&oscLookAndFeel2);
    midiVolume2.setSliderStyle(Slider::Rotary);
    midiVolume2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    volVal2 = new AudioProcessorValueTreeState::SliderAttachment(processor.state, "volume2", midiVolume2);
    
    
    /* harmonizer on/off button
    addAndMakeVisible(&harmonButton);
    harmonButton.setButtonText("Harmonzier");

    addAndMakeVisible(&harmonLabel);
    harmonLabel.setColour(Label::backgroundColourId, Colours::darkred);
    harmonLabel.setColour(Label::textColourId, Colours::white);
    harmonLabel.setJustificationType(Justification::centred);
    */
}

Oscillator2::~Oscillator2()
{
    
}

void Oscillator2::paint (Graphics& g)
{
    Rectangle <float> area(25, 25, 150, 150);

    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Oscillator2::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);
    
    oscMenu2.setBounds(area.removeFromTop(20));
    
    int sKnobSize = 64;

    //midiVolume.setBounds (area.removeFromTop(100));
    //midiVolume->setBounds(50 - sKnobSize / 2, 300, sKnobSize, sKnobSize);
    midiVolume2.setBounds(75, 75, sKnobSize, sKnobSize);
}

void Oscillator2::comboBoxChanged(ComboBox* box)
{
    
}