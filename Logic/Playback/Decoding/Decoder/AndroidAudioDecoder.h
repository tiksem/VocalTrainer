//
// Created by Semyon Tikhonenko on 12/20/21.
//

#ifndef VOCALTRAINERANDROID_ANDROIDAUDIODECODER_H
#define VOCALTRAINERANDROID_ANDROIDAUDIODECODER_H

#include "AudioDecoder.h"
#include "AndroidAudioDecoder.h"
#include <media/NdkMediaDataSource.h>
#include <media/NdkMediaCodec.h>
#include <media/NdkMediaExtractor.h>

class AndroidAudioDecoder : public AudioDecoder {
    AMediaExtractor* extractor = nullptr;
    AMediaCodec* codec = nullptr;
    AMediaDataSource* dataSource = nullptr;
    unsigned char* currentInputBuffer;
    size_t currentInputBufferSize;
    int currentInputBufferSeek;
public:
    virtual void open(AudioDataBufferConstPtr data);
    void seek(int filepos) override;
    int read(int samplesCount, SAMPLE *buffer) override;
    std::vector<std::string> supportedFileExtensions() override;
    virtual ~AndroidAudioDecoder();
};


#endif //VOCALTRAINERANDROID_ANDROIDAUDIODECODER_H
