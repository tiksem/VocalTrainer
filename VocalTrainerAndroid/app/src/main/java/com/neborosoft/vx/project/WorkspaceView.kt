package com.neborosoft.vx.project

import android.content.Context
import android.opengl.GLSurfaceView
import android.util.AttributeSet
import com.neborosoft.vx.logic.WorkspaceDrawerResourcesProvider
import com.neborosoft.vx.logic.WorkspaceRendererNative
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

class WorkspaceView(context: Context) : GLSurfaceView(context) {
    private class Renderer(context: Context) : GLSurfaceView.Renderer {
        private val cpp = WorkspaceRendererNative()
        private val resourcesProvider = WorkspaceDrawerResourcesProvider(context)

        override fun onSurfaceCreated(gl: GL10?, config: EGLConfig?) {
            cpp.onCreate(resourcesProvider)
        }

        override fun onSurfaceChanged(gl: GL10?, width: Int, height: Int) {
            cpp.onResize(width, height)
        }

        override fun onDrawFrame(gl: GL10?) {
            cpp.onDrawFrame()
        }
    }

    init {
        setEGLContextClientVersion(3)
        setRenderer(Renderer(context))
    }
}