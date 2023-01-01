#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setLookAndFeel (&lnf);

    setSize (300, 550);
    inspector.setVisible (true);

    addAndMakeVisible (display);
    addAndMakeVisible (keyboard);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    auto r = getLocalBounds().reduced (10);

    display.setBounds (r.removeFromTop (r.getHeight() * 0.3f)
                           .withTrimmedTop (r.getHeight() * 0.15f));

    keyboard.setBounds (r);
}
