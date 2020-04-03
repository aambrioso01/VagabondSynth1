#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthFrameworkAudioProcessorEditor::SynthFrameworkAudioProcessorEditor (SynthFrameworkAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), oscGui(p), envGui(p), filterGui(p), oscGui2(p), envGui2(p), filterGui2(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 570);
    
    //images
    image_background1_png = ImageCache::getFromMemory(pngBinaries::background1_png, pngBinaries::background1_pngSize);

    addAndMakeVisible(&oscGui);
    addAndMakeVisible(&envGui);
    addAndMakeVisible(&filterGui);

    addAndMakeVisible(&oscGui2);
    addAndMakeVisible(&envGui2);
    addAndMakeVisible(&filterGui2);
    
}

SynthFrameworkAudioProcessorEditor::~SynthFrameworkAudioProcessorEditor()
{
}

//==============================================================================
void SynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    g.drawImage(image_background1_png, 0, 0, 800, 570, 0, 0, 801, 571);
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

    oscGui2.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    filterGui2.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    envGui2.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
}