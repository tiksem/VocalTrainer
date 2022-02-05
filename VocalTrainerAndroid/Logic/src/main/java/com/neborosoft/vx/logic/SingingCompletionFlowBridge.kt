package com.neborosoft.vx.logic

import com.neborosoft.annotations.CppClass
import com.neborosoft.annotations.Releasable

@CppClass(withNativeConstructor = true)
interface SingingCompletionFlowBridge : Releasable {
    fun tryAgain()
    fun save()
    fun listen()
}