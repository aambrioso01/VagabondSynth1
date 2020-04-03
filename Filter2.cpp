#include <JuceHeader.h>
#include "Filter2.h"

//==============================================================================
Filter2::Filter2(SynthFrameworkAudioProcessor& p) : processor(p)
{
    setSize(200,200);
    
    // menu items and attachment
    filterMenu2.addItem("Low Pass", 1);
    filterMenu2.addItem("High Pass", 2);
    filterMenu2.addItem("Band Pass", 3);
    filterMenu2.setJustificationType(Justification::centred);
    addAndMakeVisible(&filterMenu2);
    
    filterTypeVal2 = new AudioProcessorValueTreeState::ComboBoxAttachment (processor.state, "filterType2", filterMenu2);
    

    // customs knobs and attachments
    addAndMakeVisible(&filterCutoff2);
    filterCutoff2.setLookAndFeel(&filterLookAndFeel);
    filterCutoff2.setSliderStyle(Slider::Rotary);
    filterCutoff2.setRange(20.0, 2000.0);
    filterCutoff2.setValue(400.0);
    filterCutoff2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    // defines logarithmic increment
    filterCutoff2.setSkewFactorFromMidPoint(800.0);
       
    addAndMakeVisible(&filterRes2);
    filterRes2.setLookAndFeel(&filterLookAndFeel);
    filterRes2.setSliderStyle(Slider::Rotary);
    filterRes2.setRange(1, 5);
    filterRes2.setValue(1);
    filterRes2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    
    filterVal2 = new AudioProcessorValueTreeState::SliderAttachment(processor.state, "filterCutoff2", filterCutoff2);
    resVal2 = new AudioProcessorValueTreeState::SliderAttachment(processor.state, "filterRes2", filterRes2);
}

Filter2::~Filter2()
{
}

void Filter2::paint (Graphics& g)
{   
    Rectangle <float> area (25, 25, 150, 150);
    
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Filter2::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);
    
    filterMenu2.setBounds(area.removeFromTop(20));
    filterCutoff2.setBounds(30, 100, 70, 70);
    filterRes2.setBounds(100, 100, 70, 70);
}
