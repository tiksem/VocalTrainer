package com.neborosoft.vx.logic

import android.content.Context
import android.media.MediaCodec
import android.media.MediaCodecList
import android.media.MediaExtractor
import android.media.MediaFormat
import com.neborosoft.annotations.CppAccessibleInterface
import com.neborosoft.annotations.SkipMethod

@CppAccessibleInterface(customPath = "logic/BaseAudio/Android", isSingleton = true)
internal object AudioDeviceProvider {
    @SkipMethod
    fun init(context: Context) {
        nativeInit()
    }

    fun getOutputDeviceId(): Int {
        return 0
    }

    fun getInputDeviceId(): Int {
        return 0
    }

    private external fun nativeInit()
}