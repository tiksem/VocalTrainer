package com.neborosoft.vx.logic

import android.os.Environment
import com.neborosoft.annotations.CppAccessibleInterface

@CppAccessibleInterface(isSingleton = true, cppClassName = "RecordingsProviderBridge")
object RecordingsProvider {
    fun newRecordingFileName(): String {
        return "${Environment.getDataDirectory().absolutePath}/${System.currentTimeMillis()}.rvx"
    }

    fun init() {
        nativeInit()
    }

    private external fun nativeInit()
}