
#include <jni.h>
#include "Converters.h"
#include "SingingCompletionFlowBridge.h"
#include "FunctionCallsBridge.h"
        
extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_SingingCompletionFlowBridgeNative_release(JNIEnv *env, jobject thiz, jlong ptr, jlong deleter) {
    if (deleter == 0) { 
        delete reinterpret_cast<SingingCompletionFlowBridge*&>(ptr);
    } else {
        auto* d = reinterpret_cast<std::function<void(SingingCompletionFlowBridge*)>*&>(deleter);
        (*d)(reinterpret_cast<SingingCompletionFlowBridge*&>(ptr));
        delete d;
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_SingingCompletionFlowBridgeNative_listen(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<SingingCompletionFlowBridge*&>(ptr);
    self->listen();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_SingingCompletionFlowBridgeNative_save(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<SingingCompletionFlowBridge*&>(ptr);
    self->save();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_SingingCompletionFlowBridgeNative_tryAgain(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<SingingCompletionFlowBridge*&>(ptr);
    self->tryAgain();
}
            