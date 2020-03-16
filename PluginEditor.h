/*
  ==============================================================================
    This file was auto-generated!
    It contains the basic framework code for a JUCE plugin editor.
  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "resources/pngBinaries.h"

//==============================================================================
/**
*/
class DirtyDistortionAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    DirtyDistortionAudioProcessorEditor (DirtyDistortionAudioProcessor&);
    ~DirtyDistortionAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    //JARVIS
    //SLIDERS
    ScopedPointer<Slider> driveKnob;
    ScopedPointer<Slider> rangeKnob;
    ScopedPointer<Slider> blendKnob;
    ScopedPointer<Slider> volumeKnob;

    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> driveAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> rangeAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> blendAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> volumeAttachment;
    
    //COLTON
    //BUTTONS
    ScopedPointer<TextButton> buttonSine1;
    ScopedPointer<TextButton> buttonSquare1;
    ScopedPointer<TextButton> buttonTriangle1;
    
    //Image Button Testing
    ScopedPointer<ImageButton> imageTest;
    ScopedPointer<ImageButton> test2;
    ScopedPointer<ImageButton> test3;
    
    //Image Buttons for OSC
    ScopedPointer<ImageButton> sine1
    ScopedPointer<ImageButton> sine2
    ScopedPointer<ImageButton> sine3
    ScopedPointer<ImageButton> sine4
    ScopedPointer<ImageButton> square1
    ScopedPointer<ImageButton> square2
    ScopedPointer<ImageButton> square3
    ScopedPointer<ImageButton> square4
    ScopedPointer<ImageButton> triangle1
    ScopedPointer<ImageButton> triangle2
    ScopedPointer<ImageButton> triangle3
    ScopedPointer<ImageButton> triangle4
    
    Image cachedImage_greencircle_png;
    Image cachedImage_redcircle_jpg;
    Image cachedImage_yellowcircle_png;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DirtyDistortionAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DirtyDistortionAudioProcessorEditor)
};