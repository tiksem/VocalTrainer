#include "ProjectControllerBridgeDelegate.h"
#include <jni.h>
#include "Converters.h"
#include "ProjectControllerBridge.h"
#include "FunctionCallsBridge.h"
        
extern "C"
JNIEXPORT jlong JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_newInstance(JNIEnv *env, jobject thiz) {
    return reinterpret_cast<jlong>(new ProjectControllerBridge());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_release(JNIEnv *env, jobject thiz, jlong ptr) {
    delete reinterpret_cast<ProjectControllerBridge*&>(ptr);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_addDelegate(JNIEnv *env, jobject thiz, jlong ptr, jobject delegate) {
    ProjectControllerBridgeDelegate _delegate(env, delegate);   
    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    self->addDelegate(_delegate);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_clearPlaybackBounds(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    self->clearPlaybackBounds();
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_convertSeekToPlaybackProgress(JNIEnv *env, jobject thiz, jlong ptr, jdouble seek) {
    double _seek = ConvertToCppType<double>(env, seek);   
    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->convertSeekToPlaybackProgress(_seek);
    return ConvertFromCppType<jdouble>(env, _result);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_getArtistName(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->getArtistName();
    return ConvertFromCppType<jstring>(env, _result);
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_getBeatsPerMinute(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->getBeatsPerMinute();
    return ConvertFromCppType<jdouble>(env, _result);
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_getEndSeek(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->getEndSeek();
    return ConvertFromCppType<jdouble>(env, _result);
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_getLinesCount(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->getLinesCount();
    return ConvertFromCppType<jint>(env, _result);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_getLyricsLine(JNIEnv *env, jobject thiz, jlong ptr, jint index) {
    int32_t _index = ConvertToCppType<int32_t>(env, index);   
    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->getLyricsLine(_index);
    return ConvertFromCppType<jstring>(env, _result);
}

extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_getLyricsSections(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->getLyricsSections();
    return ConvertFromCppType<jobjectArray>(env, _result);
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_getMaxZoom(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->getMaxZoom();
    return ConvertFromCppType<jfloat>(env, _result);
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_getMinZoom(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->getMinZoom();
    return ConvertFromCppType<jfloat>(env, _result);
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_getOriginalBeatsPerMinute(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->getOriginalBeatsPerMinute();
    return ConvertFromCppType<jdouble>(env, _result);
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_getOriginalTonality(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->getOriginalTonality();
    return ConvertFromCppType<jobject>(env, _result);
}

extern "C"
JNIEXPORT jfloatArray JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_getRecordingPreviewSamples(JNIEnv *env, jobject thiz, jlong ptr, jint numberOfSamples) {
    int32_t _numberOfSamples = ConvertToCppType<int32_t>(env, numberOfSamples);   
    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->getRecordingPreviewSamples(_numberOfSamples);
    return ConvertFromCppType<jfloatArray>(env, _result);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_getSongTitle(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->getSongTitle();
    return ConvertFromCppType<jstring>(env, _result);
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_getVerticalScrollPosition(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->getVerticalScrollPosition();
    return ConvertFromCppType<jfloat>(env, _result);
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_getZoom(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->getZoom();
    return ConvertFromCppType<jfloat>(env, _result);
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_hasPlaybackBounds(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->hasPlaybackBounds();
    return ConvertFromCppType<jboolean>(env, _result);
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_hasPlaybackSource(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->hasPlaybackSource();
    return ConvertFromCppType<jboolean>(env, _result);
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_isMetronomeEnabled(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->isMetronomeEnabled();
    return ConvertFromCppType<jboolean>(env, _result);
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_isPlaying(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->isPlaying();
    return ConvertFromCppType<jboolean>(env, _result);
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_isRecording(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    auto _result = self->isRecording();
    return ConvertFromCppType<jboolean>(env, _result);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_removeDelegate(JNIEnv *env, jobject thiz, jlong ptr, jobject delegate) {
    ProjectControllerBridgeDelegate _delegate(env, delegate);   
    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    self->removeDelegate(_delegate);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_setInstrumentalVolume(JNIEnv *env, jobject thiz, jlong ptr, jfloat value) {
    float _value = ConvertToCppType<float>(env, value);   
    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    self->setInstrumentalVolume(_value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_setPitchShift(JNIEnv *env, jobject thiz, jlong ptr, jint shift) {
    int32_t _shift = ConvertToCppType<int32_t>(env, shift);   
    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    self->setPitchShift(_shift);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_setPlaybackBounds(JNIEnv *env, jobject thiz, jlong ptr, jint firstLineIndex, jint lastLineIndex) {
    int32_t _firstLineIndex = ConvertToCppType<int32_t>(env, firstLineIndex);   
    int32_t _lastLineIndex = ConvertToCppType<int32_t>(env, lastLineIndex);   
    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    self->setPlaybackBounds(_firstLineIndex, _lastLineIndex);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_setPlaybackProgress(JNIEnv *env, jobject thiz, jlong ptr, jdouble progress) {
    double _progress = ConvertToCppType<double>(env, progress);   
    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    self->setPlaybackProgress(_progress);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_setPlaybackSourceFilePath(JNIEnv *env, jobject thiz, jlong ptr, jstring filePath) {
    JString _filePath = ConvertToCppType<JString>(env, filePath);   
    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    self->setPlaybackSourceFilePath(_filePath);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_setPlaybackSourcePtr(JNIEnv *env, jobject thiz, jlong ptr, jlong playbackSourcePtr) {
    int64_t _playbackSourcePtr = ConvertToCppType<int64_t>(env, playbackSourcePtr);   
    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    self->setPlaybackSourcePtr(_playbackSourcePtr);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_setTempoFactor(JNIEnv *env, jobject thiz, jlong ptr, jdouble factor) {
    double _factor = ConvertToCppType<double>(env, factor);   
    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    self->setTempoFactor(_factor);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_setVocalPianoVolume(JNIEnv *env, jobject thiz, jlong ptr, jfloat value) {
    float _value = ConvertToCppType<float>(env, value);   
    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    self->setVocalPianoVolume(_value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_setVocalVolume(JNIEnv *env, jobject thiz, jlong ptr, jfloat value) {
    float _value = ConvertToCppType<float>(env, value);   
    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    self->setVocalVolume(_value);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_setZoomIntoPoint(JNIEnv *env, jobject thiz, jlong ptr, jfloat zoom, jfloatArray point) {
    float _zoom = ConvertToCppType<float>(env, zoom);   
    CppUtils::PointF _point = ConvertToCppType<CppUtils::PointF>(env, point);   
    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    self->setZoomIntoPoint(_zoom, _point);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_stop(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    self->stop();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_toggleMetronomeEnabled(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    self->toggleMetronomeEnabled();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_ProjectControllerBridgeNative_togglePlay(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<ProjectControllerBridge*&>(ptr);
    self->togglePlay();
}
            