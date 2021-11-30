//
// Created by Semyon Tikhonenko on 11/26/21.
//

#ifndef VOCALTRAINERANDROID_JAVAOBJECT_H
#define VOCALTRAINERANDROID_JAVAOBJECT_H

#include <jni.h>

class JavaObject {
protected:
    JNIEnv* env;
    jobject self;
public:
    template<typename Class>
    static void initClass(JNIEnv *env, const char* javaClassName) {
        Class::javaClass = env->FindClass(javaClassName);
    }

    inline JavaObject(JNIEnv *env, const char* className) : env(env) {

    }
};


#endif //VOCALTRAINERANDROID_JAVAOBJECT_H
