#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Oscillator.h"
#include "Oscillator2.h"
#include "Envelope.h"
#include "Filter.h"
#include "Filter2.h"
#include "resources/pngBinaries.h"

//==============================================================================
/**
*/
class SynthFrameworkAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor&);
    ~SynthFrameworkAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& processor;

    Oscillator oscGui;
    Envelope envGui;
    Filter filterGui;

    Oscillator2 oscGui2;
    Envelope envGui2;
    Filter2 filterGui2;

    // images
    Image image_background1_png;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthFrameworkAudioProcessorEditor)
};
