//
// Created by Semyon Tikhonenko on 11/4/21.
//

#ifndef VOCALTRAINERANDROID_AAUDIOINPUTREADER_H
#define VOCALTRAINERANDROID_AAUDIOINPUTREADER_H

#include "AudioInputReader.h"
#include "AAudioStreamWrapper.h"

class AAudioInputReader : public AudioInputReader {
    AAudioStreamWrapper* stream;

    static aaudio_data_callback_result_t callback(
            AAudioStream *stream,
            void *userData,
            void *audioData,
            int32_t numFrames);
public:
    AAudioInputReader(int maximumBufferSize);
    ~AAudioInputReader();

    void start() override;
    void stop() override;
    bool isRunning() override;
    int getSampleRate() const override;
    int getSampleSizeInBytes() const override;
    int getMaximumBufferSize() const override;
    int getNumberOfChannels() const override;
    WavConfig generateWavConfig() const override;
};


#endif //VOCALTRAINERANDROID_AAUDIOINPUTREADER_H
