//
// Created by Semyon Tikhonenko on 12/20/21.
//

#include "AndroidAudioDecoder.h"
#include "AudioDecoder.h"
#include <media/NdkMediaExtractor.h>
#include <media/NdkMediaDataSource.h>
#include "Core.h"
#include "AudioOperationFailedException.h"
#include "StringUtils.h"
#include "AudioUtils.h"

using namespace CppUtils;

static constexpr int TIMEOUT = 10000;

static void checkAMediaError(media_status_t s, const char* operationName) {
    if (s != AMEDIA_OK) {
        std::string message = Strings::ToString(operationName, " failed with ", s, " errorCode");
        throw AudioOperationFailedException(message);
    }
}

static ssize_t getSize(void* userData) {
    auto* self = static_cast<AudioDataBufferConstPtr*>(userData)->get();
    return self->getNumberOfBytes();
}

ssize_t readAt(void *userData, off64_t offset, void * buffer, size_t size) {
    auto* self = static_cast<AudioDataBufferConstPtr*>(userData)->get();
    auto res = self->read(buffer, offset, size);
    if (res == 0) {
        return -1;
    } else {
        return res;
    }
}

void AndroidAudioDecoder::open(AudioDataBufferConstPtr data) {
    AMediaDataSource_setUserdata(dataSource, &data);
    AMediaDataSource_setGetSize(dataSource, getSize);
    AMediaDataSource_setReadAt(dataSource, readAt);

    auto status = AMediaExtractor_setDataSourceCustom(extractor, dataSource);
    checkAMediaError(status, "AMediaExtractor_setDataSourceCustom");

    auto* format = AMediaExtractor_getFileFormat(extractor);
    const char* mime;
    if (!AMediaFormat_getString(format, AMEDIAFORMAT_KEY_MIME, &mime)) {
        throw AudioOperationFailedException("Unable to get format mime");
    }

    //AMediaCodec_dequeueInputBuffer()

    codec = AMediaCodec_createDecoderByType(mime);
}

AndroidAudioDecoder::~AndroidAudioDecoder() {
    AMediaCodec_delete(codec);
    AMediaExtractor_delete(extractor);
    AMediaDataSource_delete(dataSource);
}

void AndroidAudioDecoder::seek(int samplePosition) {
    auto seekTime = AudioUtils::GetSampleTimeInMicroseconds(samplePosition / channels(), sampleRate());
    auto status = AMediaExtractor_seekTo(extractor, seekTime, AMEDIAEXTRACTOR_SEEK_PREVIOUS_SYNC);
    checkAMediaError(status, "AMediaExtractor_seekTo");

    int inputBufferIndex = AMediaCodec_dequeueInputBuffer(codec, TIMEOUT);
    currentInputBuffer = AMediaCodec_getInputBuffer(codec, inputBufferIndex, &currentInputBufferSize);

    //AMediaExtractor_getSampleTime()
}

int AndroidAudioDecoder::read(int samplesCount, SAMPLE *buffer) {
    return 0;
}

std::vector<std::string> AndroidAudioDecoder::supportedFileExtensions() {
    return std::vector<std::string>();
}
