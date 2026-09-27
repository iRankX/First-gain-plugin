cmake_minimum_required(VERSION 3.15)
project(MyFirstGain VERSION 1.0.0)

add_subdirectory(JUCE)

juce_add_plugin(MyFirstGain
    COMPANY_NAME "MyCompany"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_INPUT FALSE
    COPY_PLUGIN_AFTER_BUILD FALSE
    PLUGIN_MANUFACTURER_CODE Juce
    PLUGIN_CODE Gain
    FORMATS VST3
)

target_sources(MyFirstGain
    PRIVATE
        PluginProcessor.cpp
)

target_compile_definitions(MyFirstGain
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
)

target_link_libraries(MyFirstGain
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)