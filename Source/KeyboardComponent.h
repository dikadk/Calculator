//
// Created by home on 1/1/23.
//

#pragma once

class KeyboardComponent : public juce::Component
{
public:
    KeyboardComponent (CalculatorModel& m) : model (m)
    {
        for (int i = 0; i < 10; ++i)
        {
            auto button = new juce::TextButton (juce::String (i));
            button->onClick = [this, i]() {
                model.inputNewDigit (i);
            };
            buttons.add (button);
            addAndMakeVisible (button);

            button->setColour (juce::TextButton::buttonColourId, colors_classic::lightGrey);
        }

        for (auto* btn : getComps())
        {
            if (btn == &resetBtn)
            {
                btn->setColour (juce::TextButton::buttonColourId, colors_classic::pink);
                btn->onClick = [this]() {
                    model.inputOperator (Operator::RESET);
                };
            }
            else if (btn == &equalsBtn)
            {
                btn->setColour (juce::TextButton::buttonColourId, colors_classic::blue);
                btn->onClick = [this]() {
                    model.inputOperator (Operator::EQUALS);
                };
            }
            else
            {
                btn->setColour (juce::TextButton::buttonColourId, colors_classic::darkgrey);
                btn->onClick = [this, btn]() {
                    model.inputOperator (getOperatorFromButton (btn));
                };
            }

            addAndMakeVisible (btn);
        }
    }

    void resized() override
    {
        auto bounds = getLocalBounds().reduced (10);

        using namespace juce;

        Grid grid;

        using Track = Grid::TrackInfo;
        using Fr = Grid::Fr;

        grid.templateRows = { Track (Fr (1)), Track (Fr (1)), Track (Fr (1)), Track (Fr (1)), Track (Fr (1)) };
        grid.templateColumns = { Track (Fr (1)), Track (Fr (1)), Track (Fr (1)), Track (Fr (1)) };

        grid.items = {
            GridItem (resetBtn).withArea (1, 1, 1, 2).withMargin (2),
            GridItem (buttons[7]).withArea (2, 1).withMargin (2),
            GridItem (buttons[8]).withArea (2, 2).withMargin (2),
            GridItem (buttons[9]).withArea (2, 3).withMargin (2),
            GridItem (buttons[4]).withArea (3, 1).withMargin (2),
            GridItem (buttons[5]).withArea (3, 2).withMargin (2),
            GridItem (buttons[6]).withArea (3, 3).withMargin (2),
            GridItem (buttons[1]).withArea (4, 1).withMargin (2),
            GridItem (buttons[2]).withArea (4, 2).withMargin (2),
            GridItem (buttons[3]).withArea (4, 3).withMargin (2),
            GridItem (buttons[0]).withArea (5, GridItem::Span (2)).withMargin (2),
            GridItem (plusBtn).withArea (4, 4).withMargin (2),
            GridItem (minusBtn).withArea (3, 4).withMargin (2),
            GridItem (multiplyBtn).withArea (2, 4).withMargin (2),
            GridItem (divideBtn).withArea (1, 4).withMargin (2),
            GridItem (equalsBtn).withArea (5, 4).withMargin (2)
        };

        grid.performLayout (bounds);
    }

private:
    CalculatorModel& model;

    juce::OwnedArray<juce::TextButton> buttons;
    juce::TextButton resetBtn { "AC" },
        plusBtn { "+" },
        minusBtn { "-" },
        multiplyBtn { "*" },
        divideBtn { "/" },
        equalsBtn { "=" };

    std::vector<juce::TextButton*> getComps()
    {
        return { &resetBtn, &plusBtn, &minusBtn, &multiplyBtn, &divideBtn, &equalsBtn };
    }

    Operator getOperatorFromButton (juce::TextButton* pButton)
    {
        if (pButton == &plusBtn)
            return Operator::ADD;
        else if (pButton == &minusBtn)
            return Operator::SUBSTRUCT;
        else if (pButton == &multiplyBtn)
            return Operator::MULT;
        else if (pButton == &divideBtn)
            return Operator::DIV;
        else if (pButton == &resetBtn)
            return Operator::RESET;
        else if (pButton == &equalsBtn)
            return Operator::EQUALS;
        else
            return Operator::EQUALS;
    }
};
