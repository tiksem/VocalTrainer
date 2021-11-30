//
// Created by Semyon Tikhonenko on 11/21/21.
//

#include "AudioOutputWriter.h"
#include <aaudio/AAudio.h>
#include "AAudioStreamWrapper.h"

class AAudioOutputWriter : public AudioOutputWriter {
    AAudioStreamWrapper* stream;

    aaudio_data_callback_result_t
    static aAudioCallback(AAudioStream *stream, void *userData, void *audioData, int32_t numFrames) {
        auto* self = static_cast<AAudioOutputWriter*>(userData);
        self->delegate->audioOutputWriterCallback(audioData, numFrames);

        return AAUDIO_CALLBACK_RESULT_CONTINUE;
    }
public:
    explicit AAudioOutputWriter(const AudioStreamDescription& data) {
        AAudioStreamDescription d;
        d.sampleRate = data.sampleRate;
        d.framesPerDataCallback = data.samplesPerBuffer;
        d.channelsCount = data.numberOfChannels;
        d.callback = aAudioCallback;
        d.callbackUserData = this;
        stream = new AAudioStreamWrapper(d);
        stream->onStreamError = [=] {
            delegate->onStreamCrashed();
        };
        stream->onStreamErrorFixed = [=] {
            delegate->onStreamRecreated();
        };
        stream->setup();
    }

    ~AAudioOutputWriter() override {
        delete stream;
    }

    void start() override {
        stream->start();
    }

    void stop() override {
        stream->pause();
    }
};

AudioOutputWriter* AudioOutputWriter::create(const AudioStreamDescription& data) {
    return new AAudioOutputWriter(data);
}


