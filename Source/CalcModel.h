//
// Created by home on 1/1/23.
//

#pragma once

#include "juce_data_structures/juce_data_structures.h"

enum class Operator{
    ADD, SUBSTRUCT, DIV, MULT, PERC, RESET, EQUALS
};

static juce::Identifier displayedString = "displayedString";

struct CalculatorModel{

    CalculatorModel(){
        displayString.referTo(state, displayedString, nullptr, "");
    }

    void inputNewDigit(int digit){
        auto newDisplayString = displayString.get() + juce::String(digit);
        displayString.setValue(newDisplayString, nullptr);
    }

    void inputOperator(Operator anOperator){

    }

    juce::ValueTree state{"CalculatorModel"};

    juce::CachedValue<juce::String> displayString;

    void resetInput()
    {
        displayString.setValue("", nullptr);
    }
};

