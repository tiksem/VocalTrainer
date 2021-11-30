//
// Created by Semyon Tikhonenko on 11/25/21.
//

#ifndef VOCALTRAINERANDROID_AAUDIOSTREAMWRAPPER_H
#define VOCALTRAINERANDROID_AAUDIOSTREAMWRAPPER_H

#include <aaudio/AAudio.h>
#include <functional>

struct AAudioStreamDescription {
    int sampleRate = 44100;
    int framesPerDataCallback = -1;
    int channelsCount = 2;
    bool input = false;
    AAudioStream_dataCallback callback;
    void* callbackUserData;
};

class AAudioStreamWrapper {
    AAudioStream* stream = nullptr;
    AAudioStreamDescription description;

    static void errorCallback(AAudioStream *stream, void *userData, aaudio_result_t error);
public:
    std::function<void()> onStreamError;
    std::function<void()> onStreamErrorFixed;

    aaudio_stream_state_t getState() const;

    AAudioStreamWrapper(const AAudioStreamDescription& description);
    ~AAudioStreamWrapper();
    void setup();
    void start();
    void pause();

    const AAudioStreamDescription &getDescription() const;
};


#endif //VOCALTRAINERANDROID_AAUDIOSTREAMWRAPPER_H
