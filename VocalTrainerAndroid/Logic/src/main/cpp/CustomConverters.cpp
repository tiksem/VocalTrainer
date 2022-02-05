#include "Converters.h"
#include "CustomConverters.h"

template<>
CppUtils::Bitmap ConvertToCppType(JNIEnv *env, jobject javaType) {
    return CppUtils::Bitmap::fromAndroidBitmap(env, javaType);
}

template<>
jint ConvertFromCppType(JNIEnv *env, const Drawer::FontStyle& fontStyle) {
    return fontStyle;
}

template<>
jint ConvertFromCppType(JNIEnv *env, const Drawer::Color& color) {
    return color.toRgbaUint32();
}

template<>
jobjectArray ConvertFromCppType(JNIEnv *env, const std::vector<Lyrics::Section>& sections) {
    return CreateLyricsSectionArray(env, sections, [=] (const auto& s) {
        return CreateLyricsSection(
                env, s.sectionType, s.number, s.seek, s.firstLineIndex, s.linesCount);
    });
}

template<>
jobject ConvertFromCppType(JNIEnv *env, const Tonality& tonality) {
    return CreateSongTonality(env, tonality.getPitchInOctaveIndex(), tonality.isMajor());
}

jobjectArray ConvertFromCppType(JNIEnv *env, const LyricsDisplayedLinesProvider* linesProvider) {
    CreateStringArray(env, linesProvider->getDisplayLinesCount(), [=] (int index) {
        auto utf8 = UtfUtils::ToUtf8(linesProvider->getDisplayedLineAt(index));
        return env->NewStringUTF(utf8.data());
    });
}

CppUtils::PointF ConvertToCppType(JNIEnv *env, const JFloatArray& floatArray) {
    assert(floatArray.length() == 2);
    const float *data = floatArray.getData();
    return PointF(data[0], data[1]);
}


