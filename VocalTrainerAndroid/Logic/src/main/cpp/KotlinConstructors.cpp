//
// Created by Semyon Tikhonenko on 12/23/21.
//

#include "KotlinConstructors.h"
#include "Converters.h"

static jmethodID constructorString = nullptr;
static jclass classString = nullptr;

// id
static jmethodID constructorSingingCompletionFlowBridge = nullptr;

static jmethodID constructorSongTonality = nullptr;

static jmethodID constructorLyricsSection = nullptr;
// id

// class
static jclass classSingingCompletionFlowBridge = nullptr;

static jclass classSongTonality = nullptr;

static jclass classLyricsSection = nullptr;
// class

static jclass stringClass = nullptr;

jobjectArray CreateStringArray(JNIEnv* env, jint length) {
    return env->NewObjectArray(length, stringClass, nullptr);
}

void InitKotlinConstructors(JNIEnv* env) {
    stringClass = env->FindClass("java/lang/String");
    // Init constructor
    classSingingCompletionFlowBridge = env->FindClass("com/neborosoft/vx/logic/SingingCompletionFlowBridgeNative");
    constructorSingingCompletionFlowBridge = env->GetMethodID(classSingingCompletionFlowBridge, "<init>", "(JJ)V");
    
    classSongTonality = env->FindClass("com/neborosoft/vx/logic/SongTonality");
    constructorSongTonality = env->GetMethodID(classSongTonality, "<init>", "(IZ)V");
    
    classLyricsSection = env->FindClass("com/neborosoft/vx/logic/LyricsSection");
    constructorLyricsSection = env->GetMethodID(classLyricsSection, "<init>", "(IIDII)V");
    // Init constructor
}

// Constructors
jobject CreateSingingCompletionFlowBridge(JNIEnv* env, SingingCompletionFlowBridge* ptr, const std::function<void(SingingCompletionFlowBridge*)>& deleter) {
    auto _ptr = ConvertFromCppType<jlong>(env, ptr);
    auto _deleter = ConvertFromCppType<jlong>(env, deleter ? new std::function<void(SingingCompletionFlowBridge*)>(deleter) : nullptr);
    return env->NewObject(classSingingCompletionFlowBridge, constructorSingingCompletionFlowBridge, _ptr, _deleter);
}

jobjectArray CreateSingingCompletionFlowBridgeArray(JNIEnv* env, jint length) {
    return env->NewObjectArray(length, classSingingCompletionFlowBridge, nullptr);
}

jobject CreateSongTonality(JNIEnv* env, int32_t pitchInOctaveIndex, bool isMajor) {
    auto _pitchInOctaveIndex = ConvertFromCppType<jint>(env, pitchInOctaveIndex);
    auto _isMajor = ConvertFromCppType<jboolean>(env, isMajor);
    return env->NewObject(classSongTonality, constructorSongTonality, _pitchInOctaveIndex, _isMajor);
}

jobjectArray CreateSongTonalityArray(JNIEnv* env, jint length) {
    return env->NewObjectArray(length, classSongTonality, nullptr);
}

jobject CreateLyricsSection(JNIEnv* env, int32_t type, int32_t number, double seek, int32_t firstLineIndex, int32_t linesCount) {
    auto _type = ConvertFromCppType<jint>(env, type);
    auto _number = ConvertFromCppType<jint>(env, number);
    auto _seek = ConvertFromCppType<jdouble>(env, seek);
    auto _firstLineIndex = ConvertFromCppType<jint>(env, firstLineIndex);
    auto _linesCount = ConvertFromCppType<jint>(env, linesCount);
    return env->NewObject(classLyricsSection, constructorLyricsSection, _type, _number, _seek, _firstLineIndex, _linesCount);
}

jobjectArray CreateLyricsSectionArray(JNIEnv* env, jint length) {
    return env->NewObjectArray(length, classLyricsSection, nullptr);
}
// Constructors
