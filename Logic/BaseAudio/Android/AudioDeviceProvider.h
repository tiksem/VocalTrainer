//
// Created by Semyon Tikhonenko on 12/17/21.
//

#ifndef JNIBRIDGEGENERATOR_JOBJECTSINGLETONTEMPLATE_H
#define JNIBRIDGEGENERATOR_JOBJECTSINGLETONTEMPLATE_H


#include <jni.h>
#include <string>
#include <vector>
#include "JObject.h"

class AudioDeviceProvider : public JObject {
public:
    AudioDeviceProvider(JNIEnv *env, jobject obj);

    static AudioDeviceProvider& instance();

    // Java method wrappers
    int32_t getInputDeviceId();
    int32_t getOutputDeviceId();
    // Java method wrappers
};


#endif //JNIBRIDGEGENERATOR_JOBJECTSINGLETONTEMPLATE_H
