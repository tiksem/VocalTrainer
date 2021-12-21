#include <jni.h>
#include "JNIBridgeInit.h"

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    JNIBridgeInit(env);

    return JNI_VERSION_1_6;
}