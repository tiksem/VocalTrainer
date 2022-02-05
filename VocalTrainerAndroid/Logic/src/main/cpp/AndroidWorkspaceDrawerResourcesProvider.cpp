//
// Created by Semyon Tikhonenko on 12/3/21.
//

#include "AndroidWorkspaceDrawerResourcesProvider.h"
#include "Converters.h"
#include "KotlinConstructors.h"

// Method ides declaration
static jmethodID createImageForCharacterId = nullptr;

static jmethodID getPlayheadImageId = nullptr;
// Method ides declaration

void AndroidWorkspaceDrawerResourcesProvider::init(JNIEnv* env) {
    jclass clazz = env->FindClass("com/neborosoft/vx/logic/WorkspaceDrawerResourcesProvider");
    // Method ides generation
    createImageForCharacterId = env->GetMethodID(clazz, "createImageForCharacter", "(CIIIF)Landroid/graphics/Bitmap;");
    
    getPlayheadImageId = env->GetMethodID(clazz, "getPlayheadImage", "(IIF)Landroid/graphics/Bitmap;");
    // Method ides generation
}

AndroidWorkspaceDrawerResourcesProvider::AndroidWorkspaceDrawerResourcesProvider(JNIEnv *env, jobject obj) : JObject(env, obj) {
}

// Java method wrappers
CppUtils::Bitmap AndroidWorkspaceDrawerResourcesProvider::createImageForCharacter(char ch, int32_t fontSize, const Drawer::Color& colorRgba, const Drawer::FontStyle& fontStyleIndex, float scaleFactor) {
    char16_t _ch = ConvertFromCppType<char16_t>(env, ch);   
jint _fontSize = ConvertFromCppType<jint>(env, fontSize);   
jint _colorRgba = ConvertFromCppType<jint>(env, colorRgba);   
jint _fontStyleIndex = ConvertFromCppType<jint>(env, fontStyleIndex);   
jfloat _scaleFactor = ConvertFromCppType<jfloat>(env, scaleFactor);   
    auto res = (jobject)env->CallObjectMethod(obj, createImageForCharacterId, _ch, _fontSize, _colorRgba, _fontStyleIndex, _scaleFactor);
    return ConvertToCppType<CppUtils::Bitmap>(env, res);
}


CppUtils::Bitmap AndroidWorkspaceDrawerResourcesProvider::getPlayheadImage(int32_t width, int32_t height, float scaleFactor) {
    jint _width = ConvertFromCppType<jint>(env, width);   
jint _height = ConvertFromCppType<jint>(env, height);   
jfloat _scaleFactor = ConvertFromCppType<jfloat>(env, scaleFactor);   
    auto res = (jobject)env->CallObjectMethod(obj, getPlayheadImageId, _width, _height, _scaleFactor);
    return ConvertToCppType<CppUtils::Bitmap>(env, res);
}
// Java method wrappers

