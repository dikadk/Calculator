//
// Created by home on 1/1/23.
//

#pragma once

struct DigitalDisplayLookAndFeel: juce::LookAndFeel_V4{
    DigitalDisplayLookAndFeel()= default;

    juce::Font getLabelFont (juce::Label& label) override
    {
        return { "Digital-7 Mono", label.getHeight() * 1.f, juce::Font::plain };
    }
};

class DisplayComponent: public juce::Component{
public:
    DisplayComponent(CalculatorModel& m): model(m){
        display.setJustificationType(juce::Justification::centredRight);

        display.setLookAndFeel(&lnf);

        display.getTextValue().referTo(model.displayString.getPropertyAsValue());
        addAndMakeVisible(display);
    }

    void paint(juce::Graphics& g) override{
        g.setColour(colors_classic::green);
        g.fillRoundedRectangle(getLocalBounds().toFloat().reduced(2), 4.f);

        g.setColour(colors_classic::darkgrey);
        g.drawRoundedRectangle(getLocalBounds().toFloat().reduced(2), 4.f, 2.f);
    }

    void resized() override{
        display.setBounds(getLocalBounds().reduced(10));
    }

private:
    CalculatorModel& model;

    DigitalDisplayLookAndFeel lnf;
    juce::Label display;

};
