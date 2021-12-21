package com.neborosoft.vx.logic

import android.content.Context
import com.neborosoft.androidutils.AssetUtils
import com.neborosoft.annotations.CppAccessibleInterface
import com.neborosoft.annotations.CppFunction
import com.neborosoft.annotations.CppFunctionsContainer
import com.neborosoft.annotations.SkipMethod

private const val SFZ_ASSET = "Sfz"
private const val SFZ_FILE_NAME = "piano.sfz"
private const val METRONOME_DATA_ASSET = "metronome.wav"

@CppFunctionsContainer
object AndroidApplicationModel {
    private external fun nativeInit(sfzPath: String,
                                    metronomeDataPath: String)

    fun init(context: Context, previousAppVersion: Long, currentAppVersion: Long) {
        AudioDeviceProvider

        val sfzPath = AssetUtils.extractAssetsToAppDirectory(
            context,
            assetName = SFZ_ASSET,
            forceCopyAssets = false
        )

        nativeInit(
            sfzPath = "$sfzPath/$SFZ_FILE_NAME",
            metronomeDataPath = AssetUtils.extractAssetsToAppDirectory(
                context,
                assetName = METRONOME_DATA_ASSET,
                forceCopyAssets = false
            )
        )
    }
}