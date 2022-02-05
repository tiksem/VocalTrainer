package com.neborosoft.vx.logic

import com.neborosoft.annotations.CppClass
import com.neborosoft.annotations.Releasable

@CppClass
interface WorkspaceRenderer : Releasable {
    fun onCreate(resourcesProvider: WorkspaceDrawerResourcesProvider)
    fun onResize(width: Int, height: Int)
    fun onDrawFrame()
}