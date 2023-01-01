#pragma once

// CMake builds don't use an AppConfig.h, so it's safe to include juce module headers
// directly. If you need to remain compatible with Projucer-generated builds, and
// have called `juce_generate_juce_header(<thisTarget>)` in your CMakeLists.txt,
// you could `#include <JuceHeader.h>` here instead, to make all your module headers visible.
#include "JUCE/modules/juce_gui_extra/juce_gui_extra.h"
#include "melatonin_inspector/melatonin_inspector.h"

#include "PaddedComponent.h"
#include "CalcModel.h"
#include "ClassicLookAndFeel.h"
#include "DisplayComponent.h"
#include "KeyboardComponent.h"

class MainComponent : public juce::Component
{
public:
    //==============================================================================
    MainComponent();

    //==============================================================================
    void paint (juce::Graphics&) override;

    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    melatonin::Inspector inspector { *this, true};

    

    ClassicLookAndFeel lnf;

    CalculatorModel model;

    DisplayComponent display{ model };
    KeyboardComponent keyboard{ model};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
