#include "PluginProcessor.h"

MyFirstGainAudioProcessor::MyFirstGainAudioProcessor()
    : AudioProcessor (BusesProperties().withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true))
{}

MyFirstGainAudioProcessor::~MyFirstGainAudioProcessor() {}

void MyFirstGainAudioProcessor::prepareToPlay (double, int) {}
void MyFirstGainAudioProcessor::releaseResources() {}

void MyFirstGainAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer&)
{
    juce::ScopedNoDenormals noDenormals;

    // Halverer volumet (0.5f) på hele bufferen
    buffer.applyGain(0.5f);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MyFirstGainAudioProcessor();
}