#include <JuceHeader.h>
#include "Filter.h"

//==============================================================================
Filter::Filter(SynthFrameworkAudioProcessor& p) : processor(p)
{
    setSize(200,200);
    
    // menu items and attachment
    filterMenu.addItem("Low Pass", 1);
    filterMenu.addItem("High Pass", 2);
    filterMenu.addItem("Band Pass", 3);
    filterMenu.setJustificationType(Justification::centred);
    addAndMakeVisible(&filterMenu);
    
    filterTypeVal = new AudioProcessorValueTreeState::ComboBoxAttachment (processor.state, "filterType", filterMenu);
    

    // customs knobs and attachments
    addAndMakeVisible(&filterCutoff);
    filterCutoff.setLookAndFeel(&filterLookAndFeel);
    filterCutoff.setSliderStyle(Slider::Rotary);
    filterCutoff.setRange(20.0, 2000.0);
    filterCutoff.setValue(400.0);
    filterCutoff.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    // defines logarithmic increment
    filterCutoff.setSkewFactorFromMidPoint(800.0);
       
    addAndMakeVisible(&filterRes);
    filterRes.setLookAndFeel(&filterLookAndFeel);
    filterRes.setSliderStyle(Slider::Rotary);
    filterRes.setRange(1, 5);
    filterRes.setValue(1);
    filterRes.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    
    filterVal = new AudioProcessorValueTreeState::SliderAttachment(processor.state, "filterCutoff", filterCutoff);
    resVal = new AudioProcessorValueTreeState::SliderAttachment(processor.state, "filterRes", filterRes);
}

Filter::~Filter()
{
}

void Filter::paint (Graphics& g)
{
    Rectangle<int> titleArea (0, 10, getWidth(), 20);
    
    g.setColour(Colours::white);
    g.drawText("Filter", titleArea, Justification::centredTop);
    
    Rectangle <float> area (25, 25, 150, 150);
    
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Filter::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);
    
    filterMenu.setBounds(area.removeFromTop(20));
    filterCutoff.setBounds(30, 100, 70, 70);
    filterRes.setBounds(100, 100, 70, 70);
}
