//
// Created by Semyon Tikhonenko on 11/29/21.
//

#ifndef JNIBRIDGEGENERATOR_WorkspaceRenderer_H
#define JNIBRIDGEGENERATOR_WorkspaceRenderer_H

#include "JArray.h"
#include "JString.h"
#include "WorkspaceDrawer.h"
#include <string>
#include "WorkspaceDrawerResourcesProvider.h"
// headers
#include "AndroidWorkspaceDrawerResourcesProvider.h"
// headers

class WorkspaceRenderer : public WorkspaceDrawerResourcesProvider {
    std::unique_ptr<WorkspaceDrawer> workspaceDrawer = nullptr;
    mutable AndroidWorkspaceDrawerResourcesProvider resourcesProvider;
public:
    // Public Jni Interface
        void onCreate(AndroidWorkspaceDrawerResourcesProvider resourcesProvider);
        void onDrawFrame();
        void onResize(int32_t width, int32_t height);
    // Public Jni Interface

    CppUtils::Bitmap createImageForCharacter(char ch, int fontSize, CppUtils::Color color,
                                             Drawer::FontStyle fontStyle,
                                             float scaleFactor) const override;

    CppUtils::Bitmap createImageForName(Image image, int widthInPoints, int heightInPoints,
                                        float scaleFactor) const override;
};


#endif //JNIBRIDGEGENERATOR_WorkspaceRenderer_H
