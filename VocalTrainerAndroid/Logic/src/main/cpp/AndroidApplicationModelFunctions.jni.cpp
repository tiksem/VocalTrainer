
#include <jni.h>
#include "Converters.h"
#include "AndroidApplicationModelFunctions.h"
#include "FunctionCallsBridge.h"
        
extern "C"
JNIEXPORT void JNICALL
Java_com_neborosoft_vx_logic_AndroidApplicationModel_nativeInit(JNIEnv *env, jobject thiz, jstring sfzPath, jstring metronomeDataPath) {
    JString _sfzPath = ConvertToCppType<JString>(env, sfzPath);   
    JString _metronomeDataPath = ConvertToCppType<JString>(env, metronomeDataPath);   
    
    AndroidApplicationModelFunctions::nativeInit(_sfzPath, _metronomeDataPath);
}
            