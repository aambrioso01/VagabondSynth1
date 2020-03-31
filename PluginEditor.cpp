#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthFrameworkAudioProcessorEditor::SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), oscGui(p), envGui(p), filterGui(p), oscGui1(p), envGui1(p), filterGui1(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 570);
    
    //images
    image_background1_png = ImageCache::getFromMemory(pngBinaries::background1_png, pngBinaries::background1_pngSize);

    addAndMakeVisible(&oscGui);
    addAndMakeVisible(&envGui);
    addAndMakeVisible(&filterGui);

    addAndMakeVisible(&oscGui1);
    addAndMakeVisible(&envGui1);
    addAndMakeVisible(&filterGui1);
    
}

SynthFrameworkAudioProcessorEditor::~SynthFrameworkAudioProcessorEditor()
{
}

//==============================================================================
void SynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    g.drawImage(image_background1_png, 0, 0, 800, 570, 0, 0, 2500, 1668);
}

void SynthFrameworkAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    Rectangle<int> area = getLocalBounds();
    Rectangle<int> synth = area.removeFromTop(area.getHeight() / 3);

    const int componentWidth = 200;
    const int componentHeight = 200;
    
    oscGui.setBounds(synth.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    filterGui.setBounds(synth.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    envGui.setBounds(synth.removeFromLeft(componentWidth).removeFromTop(componentHeight));

    oscGui1.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    filterGui1.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    envGui1.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
}