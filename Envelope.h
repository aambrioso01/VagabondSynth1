#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "sliders/DirtyLookAndFeel1.h"

//==============================================================================
/*
*/
class Envelope    : public Component
{
public:
    Envelope(SynthFrameworkAudioProcessor&);
    ~Envelope();

    void paint (Graphics&) override;
    void resized() override;

private:
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> attackVal;
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> decayVal;
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> sustainVal;
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> releaseVal;
    
    Slider attackSlider;
    Slider decaySlider;
    Slider sustainSlider;
    Slider releaseSlider;

    //instance of look and feel with custom png: knob1
    DirtyLookAndFeel1 envLookAndFeel;


    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};
