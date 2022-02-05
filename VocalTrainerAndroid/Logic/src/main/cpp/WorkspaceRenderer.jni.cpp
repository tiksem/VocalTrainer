#include "AndroidWorkspaceDrawerResourcesProvider.h"
#include <jni.h>
#include "Converters.h"
#include "WorkspaceRenderer.h"
#include "FunctionCallsBridge.h"
        
extern "C"
JNIEXPORT jlong JNICALL
Java_com_neborosoft_vx_logic_WorkspaceRendererNative_newInstance(JNIEnv *env, jobject thiz) {
    return reinterpret_cast<jlong>(new WorkspaceRenderer());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_WorkspaceRendererNative_release(JNIEnv *env, jobject thiz, jlong ptr) {
    delete reinterpret_cast<WorkspaceRenderer*&>(ptr);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_WorkspaceRendererNative_onCreate(JNIEnv *env, jobject thiz, jlong ptr, jobject resourcesProvider) {
    AndroidWorkspaceDrawerResourcesProvider _resourcesProvider(env, resourcesProvider);   
    auto* self = reinterpret_cast<WorkspaceRenderer*&>(ptr);
    self->onCreate(_resourcesProvider);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_WorkspaceRendererNative_onDrawFrame(JNIEnv *env, jobject thiz, jlong ptr) {

    auto* self = reinterpret_cast<WorkspaceRenderer*&>(ptr);
    self->onDrawFrame();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_WorkspaceRendererNative_onResize(JNIEnv *env, jobject thiz, jlong ptr, jint width, jint height) {
    int32_t _width = ConvertToCppType<int32_t>(env, width);   
    int32_t _height = ConvertToCppType<int32_t>(env, height);   
    auto* self = reinterpret_cast<WorkspaceRenderer*&>(ptr);
    self->onResize(_width, _height);
}
            