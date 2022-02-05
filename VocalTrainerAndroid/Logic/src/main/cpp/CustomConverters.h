//
// Created by Semyon Tikhonenko on 12/21/21.
//

#ifndef JNIBRIDGEGENERATOR_CUSTOMCONVERTERS_H
#define JNIBRIDGEGENERATOR_CUSTOMCONVERTERS_H

#include <jni.h>
#include "Bitmap.h"
#include "Drawer.h"
#include "Lyrics.h"
#include "KotlinConstructors.h"
#include "Tonality.h"
#include "LyricsDisplayedLinesProvider.h"
#include "StringEncodingUtils.h"
#include "Point.h"

using namespace CppUtils;

template<>
CppUtils::Bitmap ConvertToCppType(JNIEnv *env, jobject javaType);

template<>
jint ConvertFromCppType(JNIEnv *env, const Drawer::FontStyle& fontStyle);

template<>
jint ConvertFromCppType(JNIEnv *env, const Drawer::Color& color);

template<>
jobjectArray ConvertFromCppType(JNIEnv *env, const std::vector<Lyrics::Section>& sections);

template<>
jobject ConvertFromCppType(JNIEnv *env, const Tonality& tonality);

jobjectArray ConvertFromCppType(JNIEnv *env, const LyricsDisplayedLinesProvider* linesProvider);

CppUtils::PointF ConvertToCppType(JNIEnv *env, const JFloatArray& floatArray);

#endif //JNIBRIDGEGENERATOR_CUSTOMCONVERTERS_H
