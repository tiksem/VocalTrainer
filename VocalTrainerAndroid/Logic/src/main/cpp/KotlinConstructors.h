//
// Created by Semyon Tikhonenko on 12/23/21.
//

#ifndef JNIBRIDGEGENERATOR_KOTLINCONSTRUCTORS_H
#define JNIBRIDGEGENERATOR_KOTLINCONSTRUCTORS_H

#include <jni.h>
#include <string>
#include <vector>
// headers
#include "SingingCompletionFlowBridge.h"
// headers

void InitKotlinConstructors(JNIEnv* env);

jobjectArray CreateStringArray(JNIEnv* env, jint length);

template<typename Factory>
jobjectArray CreateStringArray(JNIEnv* env, jint length, const Factory& factory) {
    jobjectArray array = CreateStringArray(env, length);
    for (int i = 0; i < length; ++i) {
        env->SetObjectArrayElement(array, i, factory(i));
    }

    return array;
}

// Constructors
jobject CreateSingingCompletionFlowBridge(JNIEnv* env, SingingCompletionFlowBridge* ptr, const std::function<void(SingingCompletionFlowBridge*)>& deleter);
jobjectArray CreateSingingCompletionFlowBridgeArray(JNIEnv* env, jint length);

template<typename Container, typename Factory>
jobjectArray CreateSingingCompletionFlowBridgeArray(JNIEnv* env, const Container& container, const Factory& factory) {
    int size = container.size();
    auto result = CreateSingingCompletionFlowBridgeArray(env, size);
    for (int i = 0; i < size; ++i) {
        jobject jo = factory(container[i]);
        env->SetObjectArrayElement(result, i, jo);
    }

    return result;
}


jobject CreateSongTonality(JNIEnv* env, int32_t pitchInOctaveIndex, bool isMajor);
jobjectArray CreateSongTonalityArray(JNIEnv* env, jint length);

template<typename Container, typename Factory>
jobjectArray CreateSongTonalityArray(JNIEnv* env, const Container& container, const Factory& factory) {
    int size = container.size();
    auto result = CreateSongTonalityArray(env, size);
    for (int i = 0; i < size; ++i) {
        jobject jo = factory(container[i]);
        env->SetObjectArrayElement(result, i, jo);
    }

    return result;
}


jobject CreateLyricsSection(JNIEnv* env, int32_t type, int32_t number, double seek, int32_t firstLineIndex, int32_t linesCount);
jobjectArray CreateLyricsSectionArray(JNIEnv* env, jint length);

template<typename Container, typename Factory>
jobjectArray CreateLyricsSectionArray(JNIEnv* env, const Container& container, const Factory& factory) {
    int size = container.size();
    auto result = CreateLyricsSectionArray(env, size);
    for (int i = 0; i < size; ++i) {
        jobject jo = factory(container[i]);
        env->SetObjectArrayElement(result, i, jo);
    }

    return result;
}

// Constructors

#endif //JNIBRIDGEGENERATOR_KOTLINCONSTRUCTORS_H
