#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "sliders/DirtyLookAndFeel1.h"

//==============================================================================
/*
*/
class Filter2    : public Component
{
public:
    Filter2(SynthFrameworkAudioProcessor&);
    ~Filter2();

    void paint (Graphics&) override;
    void resized() override;

private:

    Slider filterCutoff2;
    Slider filterRes2;
    
    ComboBox filterMenu2;
    
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeVal2;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterVal2;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> resVal2;

    //instance of look and feel with custom png: knob1
    DirtyLookAndFeel1 filterLookAndFeel;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Filter2)
};
