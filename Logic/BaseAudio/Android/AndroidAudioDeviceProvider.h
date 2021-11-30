//
// Created by Semyon Tikhonenko on 11/21/21.
//

#ifndef VOCALTRAINERANDROID_ANDROIDAUDIODEVICEPROVIDER_H
#define VOCALTRAINERANDROID_ANDROIDAUDIODEVICEPROVIDER_H

#include <jni.h>
#include "AudioDeviceProviderProxy.h"

class AndroidAudioDeviceProvider {
    AudioDeviceProviderProxy proxy;
    AndroidAudioDeviceProvider(JNIEnv* env, jobject context);
public:

    int getOutputDeviceId();
    int getInputDeviceId();

    static void init(JNIEnv* env, jobject context);
    static AndroidAudioDeviceProvider* instance();
};


#endif //VOCALTRAINERANDROID_ANDROIDAUDIODEVICEPROVIDER_H
