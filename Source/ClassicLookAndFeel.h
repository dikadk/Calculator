//
// Created by home on 1/1/23.
//
#pragma once

namespace colors_classic{
    const juce::Colour lightGrey = juce::Colour::fromString("FF979397");
    const juce::Colour green = juce::Colour::fromString("FF9CAD5F");
    const juce::Colour pink = juce::Colour::fromString("FFB6637C");
    const juce::Colour darkgrey = juce::Colour::fromString("FF414141");
    const juce::Colour blue = juce::Colour::fromString("FF729797");
    const juce::Colour bg_light = juce::Colour::fromString("FFDFDED8");
}

struct ClassicLookAndFeel : juce::LookAndFeel_V4
{
    ClassicLookAndFeel()
    {
        setColour (juce::ResizableWindow::backgroundColourId, colors_classic::bg_light);
    }

    void drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
                               bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
    {
        auto bounds = button.getLocalBounds().toFloat();
        auto roundRadius = bounds.getHeight() * 0.5f;

        if (shouldDrawButtonAsDown)
        {
            g.setColour (backgroundColour.darker());
            g.fillRoundedRectangle (bounds, roundRadius);
        }
        else if (shouldDrawButtonAsHighlighted)
        {
            g.setColour (backgroundColour.brighter());
            g.fillRoundedRectangle (bounds, roundRadius);
        }
        else
        {
            g.setColour (backgroundColour);
            g.fillRoundedRectangle (bounds, roundRadius);
        }
    }
};
