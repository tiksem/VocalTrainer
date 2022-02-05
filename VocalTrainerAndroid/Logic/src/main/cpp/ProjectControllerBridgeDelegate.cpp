//
// Created by Semyon Tikhonenko on 12/3/21.
//

#include "ProjectControllerBridgeDelegate.h"
#include "Converters.h"
#include "KotlinConstructors.h"

// Method ides declaration
static jmethodID hideSingingCompletionFlowId = nullptr;

static jmethodID playbackDidStartId = nullptr;

static jmethodID playbackDidStopId = nullptr;

static jmethodID showSingingCompletionFlowId = nullptr;

static jmethodID startListeningToRecordingId = nullptr;

static jmethodID updateAudioLevelId = nullptr;

static jmethodID updateCurrentLyricsLinesId = nullptr;

static jmethodID updateEndSeekId = nullptr;

static jmethodID updateInstrumentalVolumeId = nullptr;

static jmethodID updateLyricsSelectionId = nullptr;

static jmethodID updateMetronomeEnabledId = nullptr;

static jmethodID updateSeekId = nullptr;

static jmethodID updateTempoId = nullptr;

static jmethodID updateTonalityId = nullptr;

static jmethodID updateVocalPianoVolumeId = nullptr;

static jmethodID updateVocalVolumeId = nullptr;

static jmethodID updateZoomId = nullptr;
// Method ides declaration

void ProjectControllerBridgeDelegate::init(JNIEnv* env) {
    jclass clazz = env->FindClass("com/neborosoft/vx/logic/ProjectControllerBridgeDelegate");
    // Method ides generation
    hideSingingCompletionFlowId = env->GetMethodID(clazz, "hideSingingCompletionFlow", "()V");
    
    playbackDidStartId = env->GetMethodID(clazz, "playbackDidStart", "()V");
    
    playbackDidStopId = env->GetMethodID(clazz, "playbackDidStop", "()V");
    
    showSingingCompletionFlowId = env->GetMethodID(clazz, "showSingingCompletionFlow", "(Lcom/neborosoft/vx/logic/SingingCompletionFlowBridge;)V");
    
    startListeningToRecordingId = env->GetMethodID(clazz, "startListeningToRecording", "(J)V");
    
    updateAudioLevelId = env->GetMethodID(clazz, "updateAudioLevel", "(D)V");
    
    updateCurrentLyricsLinesId = env->GetMethodID(clazz, "updateCurrentLyricsLines", "([Ljava/lang/String;)V");
    
    updateEndSeekId = env->GetMethodID(clazz, "updateEndSeek", "(D)V");
    
    updateInstrumentalVolumeId = env->GetMethodID(clazz, "updateInstrumentalVolume", "(F)V");
    
    updateLyricsSelectionId = env->GetMethodID(clazz, "updateLyricsSelection", "(IDI)V");
    
    updateMetronomeEnabledId = env->GetMethodID(clazz, "updateMetronomeEnabled", "(Z)V");
    
    updateSeekId = env->GetMethodID(clazz, "updateSeek", "(D)V");
    
    updateTempoId = env->GetMethodID(clazz, "updateTempo", "(D)V");
    
    updateTonalityId = env->GetMethodID(clazz, "updateTonality", "(I)V");
    
    updateVocalPianoVolumeId = env->GetMethodID(clazz, "updateVocalPianoVolume", "(F)V");
    
    updateVocalVolumeId = env->GetMethodID(clazz, "updateVocalVolume", "(F)V");
    
    updateZoomId = env->GetMethodID(clazz, "updateZoom", "(F)V");
    // Method ides generation
}

ProjectControllerBridgeDelegate::ProjectControllerBridgeDelegate(JNIEnv *env, jobject obj) : JObject(env, obj) {
}

// Java method wrappers
void ProjectControllerBridgeDelegate::hideSingingCompletionFlow() {
    
    env->CallVoidMethod(obj, hideSingingCompletionFlowId);
}


void ProjectControllerBridgeDelegate::playbackDidStart() {
    
    env->CallVoidMethod(obj, playbackDidStartId);
}


void ProjectControllerBridgeDelegate::playbackDidStop() {
    
    env->CallVoidMethod(obj, playbackDidStopId);
}


void ProjectControllerBridgeDelegate::showSingingCompletionFlow(SingingCompletionFlowBridge* flow, const std::function<void(SingingCompletionFlowBridge*)>& flowDeleter) {
    jobject _flow = CreateSingingCompletionFlowBridge(env, flow, flowDeleter);   
    env->CallVoidMethod(obj, showSingingCompletionFlowId, _flow);
}


void ProjectControllerBridgeDelegate::startListeningToRecording(int64_t recordingPtr) {
    jlong _recordingPtr = ConvertFromCppType<jlong>(env, recordingPtr);   
    env->CallVoidMethod(obj, startListeningToRecordingId, _recordingPtr);
}


void ProjectControllerBridgeDelegate::updateAudioLevel(double value) {
    jdouble _value = ConvertFromCppType<jdouble>(env, value);   
    env->CallVoidMethod(obj, updateAudioLevelId, _value);
}


void ProjectControllerBridgeDelegate::updateCurrentLyricsLines(const LyricsDisplayedLinesProvider* lines) {
    jobjectArray _lines = ConvertFromCppType<jobjectArray>(env, lines);   
    env->CallVoidMethod(obj, updateCurrentLyricsLinesId, _lines);
}


void ProjectControllerBridgeDelegate::updateEndSeek(double value) {
    jdouble _value = ConvertFromCppType<jdouble>(env, value);   
    env->CallVoidMethod(obj, updateEndSeekId, _value);
}


void ProjectControllerBridgeDelegate::updateInstrumentalVolume(float value) {
    jfloat _value = ConvertFromCppType<jfloat>(env, value);   
    env->CallVoidMethod(obj, updateInstrumentalVolumeId, _value);
}


void ProjectControllerBridgeDelegate::updateLyricsSelection(int32_t selectedCharactersCount, double lastCharacterSelectionPosition, int32_t lineIndex) {
    jint _selectedCharactersCount = ConvertFromCppType<jint>(env, selectedCharactersCount);   
jdouble _lastCharacterSelectionPosition = ConvertFromCppType<jdouble>(env, lastCharacterSelectionPosition);   
jint _lineIndex = ConvertFromCppType<jint>(env, lineIndex);   
    env->CallVoidMethod(obj, updateLyricsSelectionId, _selectedCharactersCount, _lastCharacterSelectionPosition, _lineIndex);
}


void ProjectControllerBridgeDelegate::updateMetronomeEnabled(bool enabled) {
    jboolean _enabled = ConvertFromCppType<jboolean>(env, enabled);   
    env->CallVoidMethod(obj, updateMetronomeEnabledId, _enabled);
}


void ProjectControllerBridgeDelegate::updateSeek(double value) {
    jdouble _value = ConvertFromCppType<jdouble>(env, value);   
    env->CallVoidMethod(obj, updateSeekId, _value);
}


void ProjectControllerBridgeDelegate::updateTempo(double factor) {
    jdouble _factor = ConvertFromCppType<jdouble>(env, factor);   
    env->CallVoidMethod(obj, updateTempoId, _factor);
}


void ProjectControllerBridgeDelegate::updateTonality(int32_t pitchShift) {
    jint _pitchShift = ConvertFromCppType<jint>(env, pitchShift);   
    env->CallVoidMethod(obj, updateTonalityId, _pitchShift);
}


void ProjectControllerBridgeDelegate::updateVocalPianoVolume(float value) {
    jfloat _value = ConvertFromCppType<jfloat>(env, value);   
    env->CallVoidMethod(obj, updateVocalPianoVolumeId, _value);
}


void ProjectControllerBridgeDelegate::updateVocalVolume(float value) {
    jfloat _value = ConvertFromCppType<jfloat>(env, value);   
    env->CallVoidMethod(obj, updateVocalVolumeId, _value);
}


void ProjectControllerBridgeDelegate::updateZoom(float zoom) {
    jfloat _zoom = ConvertFromCppType<jfloat>(env, zoom);   
    env->CallVoidMethod(obj, updateZoomId, _zoom);
}
// Java method wrappers

