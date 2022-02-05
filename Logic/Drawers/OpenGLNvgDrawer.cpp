//
// Created by Semyon Tikhonenko on 10/25/18.
//

#include "OpenGLNvgDrawer.h"

#if (defined(_WIN32) or defined(__linux__)) && !defined(__ANDROID__)
#define WIN_OR_LINUX
#endif

#ifdef WIN_OR_LINUX
#define NANOVG_GL3_IMPLEMENTATION
#include <GLEW/GL/glew.h>
#endif

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#define NANOVG_GL2_IMPLEMENTATION
#endif

#ifdef __ANDROID__
#define NANOVG_GLES3_IMPLEMENTATION
#include <GLES3/gl3.h>
#endif

#include <nanovg/nanovg_gl.h>
#include <nanovg/fontstash.h>
#include <NotImplementedAssert.h>

OpenGLNvgDrawer::OpenGLNvgDrawer() {
#ifdef WIN_OR_LINUX
    GLint GlewInitResult = glewInit();
    if (GLEW_OK != GlewInitResult) {
        const GLubyte *er = glewGetErrorString(GlewInitResult);
        //qDebug() << "ERROR: " << reinterpret_cast<const char *>(er);
    }
    ctx = nvgCreateGL3(NVG_ANTIALIAS | NVG_STENCIL_STROKES);

#endif

#ifdef __APPLE__
    ctx = nvgCreateGL2(NVG_ANTIALIAS | NVG_STENCIL_STROKES);
#endif

#ifdef __ANDROID__
    ctx = nvgCreateGLES3(NVG_ANTIALIAS | NVG_STENCIL_STROKES);
#endif

    setupBase();
}

void OpenGLNvgDrawer::clear() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}

OpenGLNvgDrawer::~OpenGLNvgDrawer() {
#ifdef WIN_OR_LINUX
    nvgDeleteGL3(ctx);
#endif

#ifdef __APPLE__
    nvgDeleteGL2(ctx);
#endif

#ifdef __ANDROID__
    nvgDeleteGLES3(ctx);
#endif
}

int OpenGLNvgDrawer::getImageHandleFromFrameBuffer(void *frameBuffer) {
    NOT_IMPLEMENTED_ASSERT
}

void *OpenGLNvgDrawer::createFrameBuffer(int w, int h) {
    NOT_IMPLEMENTED_ASSERT
}

void OpenGLNvgDrawer::bindFrameBuffer(void *frameBuffer) {
    NOT_IMPLEMENTED_ASSERT
}

void OpenGLNvgDrawer::deleteFrameBuffer(void *frameBuffer) {
    NOT_IMPLEMENTED_ASSERT
}
