//
// Created by Semyon Tikhonenko on 12/21/21.
//

#include "WorkspaceRenderer.h"
#include "OpenGLNvgDrawer.h"
#include "BaseMouseEventsReceiver.h"

#include <memory>

using namespace CppUtils;



void WorkspaceRenderer::onCreate(AndroidWorkspaceDrawerResourcesProvider resourcesProvider) {
    this->resourcesProvider = resourcesProvider;
    auto* drawer = new OpenGLNvgDrawer();
    workspaceDrawer = std::make_unique<WorkspaceDrawer>(
            drawer, new BaseMouseEventsReceiver(),
            /* resourcesProvider */ this,
            /* drawScrollbars */ false,
            /* onUpdateRequested */ [] {},
            /* deleteResourcesProviderOnDestructor */ false);
}

void WorkspaceRenderer::onDrawFrame() {
    workspaceDrawer->draw();
}

void WorkspaceRenderer::onResize(int32_t width, int32_t height) {
    workspaceDrawer->resize(width, height, 1.0);
}

CppUtils::Bitmap
WorkspaceRenderer::createImageForCharacter(char ch, int fontSize, CppUtils::Color color,
                                           Drawer::FontStyle fontStyle, float scaleFactor) const {
    return resourcesProvider.createImageForCharacter(
            ch, fontSize, color, fontStyle, scaleFactor);
}

CppUtils::Bitmap
WorkspaceRenderer::createImageForName(WorkspaceDrawerResourcesProvider::Image image,
                                      int widthInPoints, int heightInPoints,
                                      float scaleFactor) const {
    return resourcesProvider.getPlayheadImage(
            widthInPoints, heightInPoints, scaleFactor);
}
