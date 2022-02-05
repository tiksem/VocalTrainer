//
// Created by Semyon Tikhonenko on 12/3/21.
//

#ifndef JNIBRIDGEGENERATOR_ProjectControllerBridgeDelegate_H
#define JNIBRIDGEGENERATOR_ProjectControllerBridgeDelegate_H

#include <jni.h>
#include <string>
#include <vector>
#include "JObject.h"
#include "Converters.h"
// headers
#include "SingingCompletionFlowBridge.h"
// headers

class ProjectControllerBridgeDelegate : public JObject {
public:
    static void init(JNIEnv* env);

    ProjectControllerBridgeDelegate() = default;
    ProjectControllerBridgeDelegate(JNIEnv *env, jobject obj);

    // Java method wrappers
    void hideSingingCompletionFlow();
    void playbackDidStart();
    void playbackDidStop();
    void showSingingCompletionFlow(SingingCompletionFlowBridge* flow, const std::function<void(SingingCompletionFlowBridge*)>& flowDeleter);
    void startListeningToRecording(int64_t recordingPtr);
    void updateAudioLevel(double value);
    void updateCurrentLyricsLines(const LyricsDisplayedLinesProvider* lines);
    void updateEndSeek(double value);
    void updateInstrumentalVolume(float value);
    void updateLyricsSelection(int32_t selectedCharactersCount, double lastCharacterSelectionPosition, int32_t lineIndex);
    void updateMetronomeEnabled(bool enabled);
    void updateSeek(double value);
    void updateTempo(double factor);
    void updateTonality(int32_t pitchShift);
    void updateVocalPianoVolume(float value);
    void updateVocalVolume(float value);
    void updateZoom(float zoom);
    // Java method wrappers
};

#endif //JNIBRIDGEGENERATOR_JOBJECTTEMPLATE_H
