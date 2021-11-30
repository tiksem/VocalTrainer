//
// Created by Semyon Tikhonenko on 11/21/21.
//

#include "AndroidAudioDeviceProvider.h"
#include "AudioDeviceProviderProxy.h"

static AndroidAudioDeviceProvider* _instance = nullptr;

int AndroidAudioDeviceProvider::getOutputDeviceId() {
    return proxy.getOutputDeviceId();
}

int AndroidAudioDeviceProvider::getInputDeviceId() {
    return proxy.getInputDeviceId();
}

AndroidAudioDeviceProvider *AndroidAudioDeviceProvider::instance() {
    return _instance;
}

AndroidAudioDeviceProvider::AndroidAudioDeviceProvider(JNIEnv* env, jobject context)
: proxy(AudioDeviceProviderProxy::newInstance(env, context)) {
}

void AndroidAudioDeviceProvider::init(JNIEnv* env, jobject context) {
    _instance = new AndroidAudioDeviceProvider(env, context);
}
