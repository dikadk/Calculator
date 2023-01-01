//
// Created by home on 1/1/23.
//

#pragma once

#include "juce_data_structures/juce_data_structures.h"

enum class Operator {
    ADD,
    SUBSTRUCT,
    DIV,
    MULT,
    PERC,
    RESET,
    EQUALS,
    NONE
};

static juce::Identifier displayedString = "displayedString";
static juce::Identifier currentOperatorString = "currentOperator";

struct CalculatorModel
{
    CalculatorModel()
    {
        displayString.referTo (state, displayedString, nullptr, "");
        currentOperator.referTo (state, currentOperatorString, nullptr, static_cast<int> (Operator::NONE));
    }

    void inputNewDigit (int digit)
    {
        //compute the result of the current operation
        juce::String newString = "";
        if (inputFirst)
        {
            if (x.startsWith ("0"))
            {
                x = juce::String (digit);
            }
            else
            {
                x = x + juce::String (digit);
            }
            newString = x;
        }
        else
        {
            if (y.startsWith ("0"))
            {
                y = juce::String (digit);
            }
            else
            {
                y = y + juce::String (digit);
            }
            newString = y;
        }
        displayString.setValue (newString, nullptr);
    }

    void inputOperator (Operator anOperator)
    {
        if (anOperator == Operator::ADD || anOperator == Operator::MULT || anOperator == Operator::DIV || anOperator == Operator::SUBSTRUCT)
        {
            inputFirst = false;
            x = displayString.get();
        }

        if (anOperator == Operator::RESET)
        {
            displayString.setValue ("", nullptr);

            inputFirst = true;
            x = "";
            y = "";
            currentOperator.setValue (static_cast<int> (Operator::NONE), nullptr);
        }
        if (anOperator == Operator::EQUALS)
        {
            y = displayString.get();

            auto newResult = calculateResult();

            displayString.setValue (juce::String (newResult), nullptr);
            currentOperator.setValue (static_cast<int> (Operator::NONE), nullptr);

            inputFirst = true;
            x = "";
            y = "";
        }

        currentOperator.setValue (static_cast<int> (anOperator), nullptr);
    }

    juce::ValueTree state { "CalculatorModel" };

    juce::CachedValue<juce::String> displayString;
    juce::CachedValue<int> currentOperator;

private:
    juce::String x { "" };
    juce::String y { "" };

    bool inputFirst { true };

    int calculateResult()
    {
        auto operator_ = static_cast<Operator> (currentOperator.get());

        if (operator_ == Operator::ADD)
            return x.getIntValue() + y.getIntValue();
        else if (operator_ == Operator::SUBSTRUCT)
            return x.getIntValue() - y.getIntValue();
        else if (operator_ == Operator::DIV)
            return x.getIntValue() / y.getIntValue();
        else if (operator_ == Operator::MULT)
            return x.getIntValue() * y.getIntValue();
        else
            return 0;
    }
};
