//
// Created by Semyon Tikhonenko on 12/17/21.
//

#include "RecordingsProviderBridge.h"
#include "Converters.h"
#include <cassert>

// Method ides declaration
static jmethodID initId = nullptr;

static jmethodID newRecordingFileNameId = nullptr;
// Method ides declaration

static RecordingsProviderBridge* _instance = nullptr;

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_RecordingsProvider_nativeInit(JNIEnv *env, jobject thiz) {
    jclass clazz = env->GetObjectClass(thiz);
    // Method ides generation
    initId = env->GetMethodID(clazz, "init", "()V");
    
    newRecordingFileNameId = env->GetMethodID(clazz, "newRecordingFileName", "()Ljava/lang/String;");
    // Method ides generation
    _instance = new RecordingsProviderBridge(env, thiz);
}

RecordingsProviderBridge::RecordingsProviderBridge(JNIEnv *env, jobject obj) : JObject(env, obj) {
}

RecordingsProviderBridge& RecordingsProviderBridge::instance() {
    assert(_instance && "RecordingsProviderBridge has not been initialized, call nativeInit from kotlin side");
    return *_instance;
}

// Java method wrappers
void RecordingsProviderBridge::init() {
    
    static_cast<void>(env->CallVoidMethod(obj, initId));
}


std::string RecordingsProviderBridge::newRecordingFileName() {
    
    auto res = static_cast<jstring>(env->CallObjectMethod(obj, newRecordingFileNameId));
    return ConvertToCppType<std::string>(env, res);
}
// Java method wrappers
