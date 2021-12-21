//
// Created by Semyon Tikhonenko on 12/17/21.
//

#include "AudioDeviceProvider.h"
#include "Converters.h"
#include <cassert>

// Method ides declaration
static jmethodID getInputDeviceIdId = nullptr;

static jmethodID getOutputDeviceIdId = nullptr;
// Method ides declaration

static AudioDeviceProvider* _instance = nullptr;

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_AudioDeviceProvider_nativeInit(JNIEnv *env, jobject thiz) {
    jclass clazz = env->GetObjectClass(thiz);
    // Method ides generation
    getInputDeviceIdId = env->GetMethodID(clazz, "getInputDeviceId", "()I");
    
    getOutputDeviceIdId = env->GetMethodID(clazz, "getOutputDeviceId", "()I");
    // Method ides generation
    _instance = new AudioDeviceProvider(env, thiz);
}

AudioDeviceProvider::AudioDeviceProvider(JNIEnv *env, jobject obj) : JObject(env, obj) {
}

AudioDeviceProvider& AudioDeviceProvider::instance() {
    assert(_instance && "AudioDeviceProvider has not been initialized, call nativeInit from kotlin side");
    return *_instance;
}

// Java method wrappers
int32_t AudioDeviceProvider::getInputDeviceId() {
    
    auto res = static_cast<jint>(env->CallIntMethod(obj, getInputDeviceIdId));
    return ConvertToCppType<int32_t>(env, res);
}


int32_t AudioDeviceProvider::getOutputDeviceId() {
    
    auto res = static_cast<jint>(env->CallIntMethod(obj, getOutputDeviceIdId));
    return ConvertToCppType<int32_t>(env, res);
}
// Java method wrappers
