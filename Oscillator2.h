#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "sliders/DirtyLookAndFeel1.h"

class Oscillator2 : public Component, private ComboBox::Listener//, private Button::Listener
{
public:

    Oscillator2(SynthFrameworkAudioProcessor&);
    ~Oscillator2();

    void paint(Graphics&) override;
    void resized() override;

    void comboBoxChanged(ComboBox*) override;

private:
    ComboBox oscMenu2;
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection2;
    
    /*
    // default slider
    Slider midiVolume2;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> volVal2;
    */
    /*
    TextButton harmonButton;
    Label harmonLabel;
    */
    
    // custom slider JARVIS
    Slider midiVolume2;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> volVal2;
  
    //instance of look and feel with custom png: knob1
    DirtyLookAndFeel1 oscLookAndFeel2;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& processor;

};