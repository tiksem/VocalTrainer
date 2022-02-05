//
// Created by Semyon Tikhonenko on 12/3/21.
//

#ifndef JNIBRIDGEGENERATOR_AndroidWorkspaceDrawerResourcesProvider_H
#define JNIBRIDGEGENERATOR_AndroidWorkspaceDrawerResourcesProvider_H

#include <jni.h>
#include <string>
#include <vector>
#include "JObject.h"
#include "Converters.h"
// headers
// headers

class AndroidWorkspaceDrawerResourcesProvider : public JObject {
public:
    static void init(JNIEnv* env);

    AndroidWorkspaceDrawerResourcesProvider() = default;
    AndroidWorkspaceDrawerResourcesProvider(JNIEnv *env, jobject obj);

    // Java method wrappers
    CppUtils::Bitmap createImageForCharacter(char ch, int32_t fontSize, const Drawer::Color& colorRgba, const Drawer::FontStyle& fontStyleIndex, float scaleFactor);
    CppUtils::Bitmap getPlayheadImage(int32_t width, int32_t height, float scaleFactor);
    // Java method wrappers
};

#endif //JNIBRIDGEGENERATOR_JOBJECTTEMPLATE_H
