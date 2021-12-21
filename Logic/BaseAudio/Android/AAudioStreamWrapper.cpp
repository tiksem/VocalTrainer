//
// Created by Semyon Tikhonenko on 11/25/21.
//

#include "AAudioStreamWrapper.h"
#include "AAudioUtils.h"
#include "AudioDeviceProvider.h"
#include "AudioOperationFailedException.h"
#include "StringUtils.h"
#include "Executors.h"
#include <cassert>

constexpr int BUFFER_CAPACITY_MULTIPLIER = 4;
using namespace CppUtils;

AAudioStreamWrapper::AAudioStreamWrapper(const AAudioStreamDescription &description) {
    this->description = description;
}

void AAudioStreamWrapper::setup() {
    auto& audioDeviceProvider = AudioDeviceProvider::instance();
    int deviceId = description.input ? audioDeviceProvider.getInputDeviceId() :
            audioDeviceProvider.getOutputDeviceId();
    if (deviceId < 0) {
        throw AudioOperationFailedException(
                Strings::ToString(
                        "required ",
                        description.input ? "input" : "output",
                        " device is not available"));
    }

    AAudioStreamBuilder *builder;
    aaudio_result_t result = AAudio_createStreamBuilder(&builder);
    AAudioUtils::CheckError(result);

    AAudioStreamBuilder_setDeviceId(builder, deviceId);
    AAudioStreamBuilder_setDirection(builder,
                                     description.input ? AAUDIO_DIRECTION_INPUT :
                                     AAUDIO_DIRECTION_OUTPUT);
    AAudioStreamBuilder_setSharingMode(builder, AAUDIO_SHARING_MODE_EXCLUSIVE);
    AAudioStreamBuilder_setSampleRate(builder, description.sampleRate);
    AAudioStreamBuilder_setChannelCount(builder, description.channelsCount);
    AAudioStreamBuilder_setFormat(builder, AAUDIO_FORMAT_PCM_I16);
    AAudioStreamBuilder_setFramesPerDataCallback(builder, description.framesPerDataCallback);
    AAudioStreamBuilder_setBufferCapacityInFrames(builder,description.framesPerDataCallback * BUFFER_CAPACITY_MULTIPLIER);
    AAudioStreamBuilder_setPerformanceMode(builder, AAUDIO_PERFORMANCE_MODE_LOW_LATENCY);
    AAudioStreamBuilder_setDataCallback(builder, description.callback, description.callbackUserData);
    AAudioStreamBuilder_setErrorCallback(builder, errorCallback, this);

    result = AAudioStreamBuilder_openStream(builder, &stream);
    AAudioUtils::CheckError(result);
    result = AAudioStreamBuilder_delete(builder);
    AAudioUtils::CheckError(result);
}

void
AAudioStreamWrapper::errorCallback(AAudioStream *stream, void *userData, aaudio_result_t error) {
    auto* self = static_cast<AAudioStreamWrapper*>(userData);
    self->stream = nullptr;
    Executors::ExecuteOnMainThread([=] {
        self->onStreamError();
        AAudioStream_close(stream);
        self->stream = nullptr;
        self->setup();
        self->onStreamErrorFixed();
    });
}

AAudioStreamWrapper::~AAudioStreamWrapper() {
    if (stream) {
        AAudioStream_close(stream);
    }
}

void AAudioStreamWrapper::start() {
    if (stream) {
        AAudioStream_requestStart(stream);
    }
}

void AAudioStreamWrapper::pause() {
    if (!stream) {
        return;
    }

    if (description.input) {
        AAudioStream_requestStop(stream);
    } else {
        AAudioStream_requestPause(stream);
    }
}

aaudio_stream_state_t AAudioStreamWrapper::getState() const {
    return AAudioStream_getState(stream);
}

const AAudioStreamDescription &AAudioStreamWrapper::getDescription() const {
    return description;
}
