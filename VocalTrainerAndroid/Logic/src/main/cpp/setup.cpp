#include <jni.h>
#include "AndroidApplicationModel.h"
#include "AudioDeviceProviderProxy.h"
#include "JavaObject.h"

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    AndroidApplicationModel::registerNativeFunctions(env);
    AudioDeviceProviderProxy::initClazz(env);

    return JNI_VERSION_1_6;
}