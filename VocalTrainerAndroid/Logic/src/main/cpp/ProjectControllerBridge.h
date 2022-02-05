//
// Created by Semyon Tikhonenko on 11/29/21.
//

#ifndef JNIBRIDGEGENERATOR_ProjectControllerBridge_H
#define JNIBRIDGEGENERATOR_ProjectControllerBridge_H

#include "JArray.h"
#include "JString.h"
#include <string>
#include <vector>
#include "AndroidProjectControllerDelegate.h"
#include "Point.h"
// headers
#include "ProjectControllerBridgeDelegate.h"
// headers

class ProjectControllerBridge {
    AndroidProjectControllerDelegate delegates;
    ProjectController* cpp;
public:
    ProjectControllerBridge();
    ~ProjectControllerBridge();
    // Public Jni Interface
        void addDelegate(ProjectControllerBridgeDelegate delegate);
        void clearPlaybackBounds();
        double convertSeekToPlaybackProgress(double seek);
        std::string getArtistName();
        double getBeatsPerMinute();
        double getEndSeek();
        int32_t getLinesCount();
        std::string getLyricsLine(int32_t index);
        std::vector<Lyrics::Section> getLyricsSections();
        float getMaxZoom();
        float getMinZoom();
        double getOriginalBeatsPerMinute();
        Tonality getOriginalTonality();
        std::vector<float> getRecordingPreviewSamples(int32_t numberOfSamples);
        std::string getSongTitle();
        float getVerticalScrollPosition();
        float getZoom();
        bool hasPlaybackBounds();
        bool hasPlaybackSource();
        bool isMetronomeEnabled();
        bool isPlaying();
        bool isRecording();
        void removeDelegate(ProjectControllerBridgeDelegate delegate);
        void setInstrumentalVolume(float value);
        void setPitchShift(int32_t shift);
        void setPlaybackBounds(int32_t firstLineIndex, int32_t lastLineIndex);
        void setPlaybackProgress(double progress);
        void setPlaybackSourceFilePath(const JString& filePath);
        void setPlaybackSourcePtr(int64_t playbackSourcePtr);
        void setTempoFactor(double factor);
        void setVocalPianoVolume(float value);
        void setVocalVolume(float value);
        void setZoomIntoPoint(float zoom, const CppUtils::PointF& point);
        void stop();
        void toggleMetronomeEnabled();
        void togglePlay();
    // Public Jni Interface
};


#endif //JNIBRIDGEGENERATOR_ProjectControllerBridge_H
