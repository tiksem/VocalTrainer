
#ifndef __AUDIODECODERBASE_H__
#define __AUDIODECODERBASE_H__

#include <string>
#include <vector>
#include <functional>
#include <WAVFile.h>
#include "DecodedTrack.h"
#include "OperationCanceler.h"
#include "AudioDataBuffer.h"

typedef short SAMPLE;

class AudioDecoder {
public:
    virtual ~AudioDecoder() = default;

    /** Opens the file for decoding */
    virtual void open(AudioDataBufferConstPtr data) = 0;

    /** Seek to a sample in the file */
    virtual void seek(int filepos) = 0;

    /** Read a maximum `samplesCount` of audio into buffer.
        Samples are always returned as 16-bit integers, with stereo interlacing.
        Returns the number of samples read. */
    virtual int read(int samplesCount, SAMPLE *buffer) = 0;

    /** Get the number of audio samples in the file. This will be a good estimate of the
        number of samples you can get out of read(), though you should not rely on it
        being perfectly accurate always. (eg. it might be slightly inaccurate with VBR MP3s)*/
    int numSamples() const;

    /** Get the number of channels in the audio file */
    int channels() const;

    /** Get the sample rate of the audio file (samples per second) */
    int sampleRate() const;

    /** Get the duration of the audio file (seconds) */
    float duration() const;

    /** Get the current playback position in samples */
    int positionInSamples() const;

    /** Get a list of the filetypes supported by the decoder, by extension */
    virtual std::vector<std::string> supportedFileExtensions() = 0;

protected:
    int m_iNumSamples = -1;
    int m_iChannels = 0;
    int m_iSampleRate = 0;
    float m_fDuration = 0; // in seconds
    int m_iPositionInSamples = 0; // in samples;

public:
    static AudioDecoder* create();
    static DecodedTrack
    decodeAllIntoRawPcm(AudioDataBufferConstPtr data, const std::function<void(float)> &progressListener = nullptr,
                        CppUtils::OperationCancelerPtr operationCanceller = nullptr);

    WavConfig generateWavConfig() const;
};

#endif //__AUDIODECODERBASE_H__
