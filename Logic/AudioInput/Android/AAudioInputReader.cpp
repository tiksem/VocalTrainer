//
// Created by Semyon Tikhonenko on 11/4/21.
//

#include "AAudioInputReader.h"
#include "AAudioUtils.h"
//#include "AndroidAudioDeviceProvider.h"

constexpr int SAMPLE_RATE = 441000;

AAudioInputReader::AAudioInputReader(int maximumBufferSize) {
    AAudioStreamDescription d;
    d.channelsCount = 1;
    d.framesPerDataCallback = maximumBufferSize;
    d.sampleRate = SAMPLE_RATE;
    d.callback = callback;
    d.callbackUserData = this;
    d.input = true;

    stream = new AAudioStreamWrapper(d);
    stream->setup();
}

void AAudioInputReader::start() {
    stream->start();
}

void AAudioInputReader::stop() {
    stream->pause();
}

bool AAudioInputReader::isRunning() {
    return stream->getState() == AAUDIO_STREAM_STATE_STARTED;
}

int AAudioInputReader::getSampleRate() const {
    return SAMPLE_RATE;
}

int AAudioInputReader::getSampleSizeInBytes() const {
    return 2;
}

int AAudioInputReader::getMaximumBufferSize() const {
    return stream->getDescription().framesPerDataCallback;
}

int AAudioInputReader::getNumberOfChannels() const {
    return stream->getDescription().channelsCount;
}

WavConfig AAudioInputReader::generateWavConfig() const {
    WavConfig wavConfig;
    wavConfig.bitsPerChannel = 16;
    wavConfig.numberOfChannels = getNumberOfChannels();
    wavConfig.sampleRate = SAMPLE_RATE;
    return wavConfig;
}

AAudioInputReader::~AAudioInputReader() {
    delete stream;
}

aaudio_data_callback_result_t
AAudioInputReader::callback(AAudioStream *stream, void *userData, void *audioData, int32_t numFrames) {
    auto* self = static_cast<AudioInputReader*>(userData);
    self->callbacks.executeAll(static_cast<const int16_t*>(audioData), numFrames);

    return AAUDIO_CALLBACK_RESULT_CONTINUE;
}
