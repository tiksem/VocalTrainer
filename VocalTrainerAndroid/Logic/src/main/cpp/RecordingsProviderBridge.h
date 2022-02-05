//
// Created by Semyon Tikhonenko on 12/17/21.
//

#ifndef JNIBRIDGEGENERATOR_JOBJECTSINGLETONTEMPLATE_H
#define JNIBRIDGEGENERATOR_JOBJECTSINGLETONTEMPLATE_H


#include <jni.h>
#include <string>
#include <vector>
#include "JObject.h"

class RecordingsProviderBridge : public JObject {
public:
    RecordingsProviderBridge(JNIEnv *env, jobject obj);

    static RecordingsProviderBridge& instance();

    // Java method wrappers
    void init();
    std::string newRecordingFileName();
    // Java method wrappers
};


#endif //JNIBRIDGEGENERATOR_JOBJECTSINGLETONTEMPLATE_H
