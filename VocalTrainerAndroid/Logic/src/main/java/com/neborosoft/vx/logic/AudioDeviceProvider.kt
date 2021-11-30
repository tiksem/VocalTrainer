package com.neborosoft.vx.logic

import android.content.Context
import io.github.landerlyoung.jenny.NativeProxy

@NativeProxy(allMethods = true)
class AudioDeviceProvider(private val context: Context) {
    fun getOutputDeviceId(): Int {
        return 0;
    }

    fun getInputDeviceId(): Int {
        return 0;
    }
}