#include <assert.h>
#include "VxFile.h"
#define TSF_IMPLEMENTATION
#include "tsf.h"
#include "GetSf2FilePath.h"
#include "WAVFile.h"
#include "Algorithms.h"

static const char *const SILENCE_MARK = "*";

VxFile::VxFile(std::vector<VxPitch> &&pitches, int distanceInTicksBetweenLastPitchEndAndTrackEnd, int bitsPerMinute)
        : pitches(pitches), ticksPerMinute(bitsPerMinute),
          distanceInTicksBetweenLastPitchEndAndTrackEnd(distanceInTicksBetweenLastPitchEndAndTrackEnd) {
    postInit();
}

VxFile::VxFile(std::istream &is) {
    is >> ticksPerMinute;

    std::string pitchName;
    while (!is.eof()) {
        is >> pitchName;
        if (pitchName == SILENCE_MARK) {
            is >> distanceInTicksBetweenLastPitchEndAndTrackEnd;
            break;
        }
        
        VxPitch vxPitch;
        vxPitch.pitch = Pitch(pitchName.data());
        if (!vxPitch.pitch.hasPerfectFrequency()) {
            throw std::runtime_error("Error while parsing pitch with " + pitchName + " name");
        }

        is >> vxPitch.startTickNumber;
        is >> vxPitch.ticksCount;

        pitches.push_back(vxPitch);
    }

    postInit();
}

static inline size_t addSilence(std::vector<char>& pcmData, double duration, int sampleRate) {
    size_t size = static_cast<size_t>((int)round(duration * sampleRate) * sizeof(short));
    pcmData.resize(pcmData.size() + size);
    return size;
}

// make sure tsf is properly destroyed
struct TsfHolder {
    tsf* t;

    TsfHolder(int sampleRate) {
        t = tsf_load_filename(GetSf2FilePath().data());
        tsf_set_output(t, TSF_MONO, sampleRate, 0);
    }

    ~TsfHolder() {
        tsf_close(t);
    }
};

std::vector<char> VxFile::generateRawPcmAudioData(int sampleRate) const {
    double bitDuration = getBitDuration();

    TsfHolder tsfHolder(sampleRate);
    tsf* t = tsfHolder.t;

    int size = static_cast<int>(getDurationInSeconds() * sampleRate);
    
    std::vector<char> pcmData;
    // make sure there is no buffer overflow
    pcmData.reserve(size + 10u);

    auto iter = pitches.begin();
    auto end = pitches.end();
    if (iter == end) {
        return pcmData;
    }

    int silenceStart = 0;
    while (iter != end) {
        // add silence between pitches
        addSilence(pcmData, (iter->startTickNumber - silenceStart) * bitDuration, sampleRate);
        tsf_note_on(t, 0, iter->pitch.getSoundFont2Index(), 0.5f);
        silenceStart = iter->startTickNumber + iter->ticksCount;

        // add pitch itself
        size_t currentSize = pcmData.size();
        double duration = bitDuration * iter->ticksCount;
        // resize pcmData to append pitch data
        size_t sizeInBytes = addSilence(pcmData, duration, sampleRate);
        tsf_render_short(t, (short*)(pcmData.data() + currentSize), (int)sizeInBytes / 2, 0);
        
        iter++;
    }

    double endSilenceDuration = distanceInTicksBetweenLastPitchEndAndTrackEnd * bitDuration;
    addSilence(pcmData, endSilenceDuration, sampleRate);

    return pcmData;
}

std::vector<char> VxFile::generateWavAudioData() const {
    WavConfig wavConfig;
    std::vector<char> pcmData = generateRawPcmAudioData(wavConfig.sampleRate);
    return WAVFile::addWavHeaderToRawPcmData(pcmData.data(), (int)pcmData.size(), wavConfig);
}

double VxFile::getBitDuration() const {
    return 60.0 / (double) ticksPerMinute;
}

bool VxFile::validate() {
    if (!pitches.empty()) {
        if (pitches[0].startTickNumber < 0) {
            return false;
        }
        
        if (pitches[0].ticksCount < 1) {
            return false;
        }
    }
    
    for (int i = 1; i < pitches.size(); ++i) {
        const VxPitch &vxPitch = pitches[i];
        if (!vxPitch.pitch.hasPerfectFrequency()) {
            return false;
        }
        
        if (vxPitch.ticksCount < 1) {
            return false;
        }

        const VxPitch &prev = pitches[i - 1];
        if (vxPitch.startTickNumber < prev.startTickNumber + prev.ticksCount) {
            return false;
        }
    }

    return true;
}

void VxFile::postInit() {
    assert(distanceInTicksBetweenLastPitchEndAndTrackEnd >= 0);
    assert(validate());
    if (!pitches.empty()) {
        const VxPitch &lastPitch = pitches.back();
        durationInBits = lastPitch.startTickNumber + lastPitch.ticksCount + distanceInTicksBetweenLastPitchEndAndTrackEnd;
    }
}

double VxFile::getDurationInSeconds() const {
    return getBitDuration() * durationInBits;
}

const std::vector<VxPitch> &VxFile::getPitches() const {
    return pitches;
}

int VxFile::getTicksPerMinute() const {
    return ticksPerMinute;
}

int VxFile::getDurationInTicks() const {
    return durationInBits;
}

int VxFile::getDistanceInTicksBetweenLastPitchEndAndTrackEnd() const {
    return distanceInTicksBetweenLastPitchEndAndTrackEnd;
}

void VxFile::writeToStream(std::ostream &os) const {
    os<<ticksPerMinute<<" ";

    for (const VxPitch& vxPitch : pitches) {
        os<<vxPitch.pitch.getFullName()<<" "<<vxPitch.startTickNumber<<" "<<vxPitch.ticksCount<<" ";
    }

    os<<"* "<<distanceInTicksBetweenLastPitchEndAndTrackEnd;
}

VxFile VxFile::fromFilePath(const char *filePath) {
    std::ifstream is(filePath);
    return VxFile(is);
}

void VxFile::setLyrics(const std::string &lyrics, const std::vector<VxLyricsInterval> &lyricsInfo) {
    this->lyrics = lyrics;
    this->lyricsInfo = lyricsInfo;
    assert(validateLyrics());
}

bool VxFile::validateLyrics() {
    if (!lyricsInfo.empty()) {
        const VxLyricsInterval &first = lyricsInfo[0];
        if (first.startTickNumber < 0) {
            return false;
        }

        if (first.ticksCount < 1) {
            return false;
        }

        if (first.startTickNumber < 0) {
            return false;
        }

        if (first.ticksCount < 1) {
            return false;
        }

        if (!validateSingleLyricsInterval(first)) {
            return false;
        }
    }

    for (int i = 1; i < lyricsInfo.size(); ++i) {
        const VxLyricsInterval &interval = lyricsInfo[i];
        if (interval.ticksCount < 1) {
            return false;
        }

        if (interval.letterStartIndex >= interval.letterEndIndex) {
            return false;
        }

        const VxLyricsInterval &prev = lyricsInfo[i - 1];
        if (prev.letterStartIndex != interval.letterEndIndex) {
            return false;
        }

        if (interval.startTickNumber < prev.startTickNumber + prev.ticksCount) {
            return false;
        }

        if (!validateSingleLyricsInterval(interval)) {
            return false;
        }
    }

    return true;
}

bool VxFile::validateSingleLyricsInterval(const VxLyricsInterval &interval) {
    VxPitch pitchHolder;
    pitchHolder.startTickNumber = interval.startTickNumber;
    auto iter = CppUtils::FindLessOrEqualInSortedCollection(pitches, pitchHolder,
            [](const VxPitch& a, const VxPitch& b) {
                return a.startTickNumber < b.startTickNumber;
            });

    if (iter == pitches.end()) {
        return false;
    }

    int pitchTickEndPosition = iter->startTickNumber + iter->ticksCount;
    if (pitchTickEndPosition <= interval.startTickNumber) {
        return false;
    }

    if (pitchTickEndPosition < interval.startTickNumber + interval.ticksCount) {
        return false;
    }

    return true;
}
