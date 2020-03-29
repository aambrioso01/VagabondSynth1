#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "resources/pngBinaries.h"
#include "sliders/DirtyLookAndFeel1.h"

class Oscillator : public Component, private ComboBox::Listener//, private Button::Listener
{
public:

    Oscillator(SynthFrameworkAudioProcessor&);
    ~Oscillator();

    void paint(Graphics&) override;
    void resized() override;

    void comboBoxChanged(ComboBox*) override;

private:
    ComboBox oscMenu;
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;
    
    // default slider
    Slider midiVolume;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> volVal;
    
    /*
    TextButton harmonButton;
    Label harmonLabel;
    */
    /*
    // custom slider JARVIS
    ScopedPointer<Slider> midiVolume;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> volVal;
    */
    // images
    Image image_background1_png;
    /*
    //instance of look and feel with custom png: knob1
    DirtyLookAndFeel1 dirtyLookAndFeel1;
    */
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& processor;

};