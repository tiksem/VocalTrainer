package com.neborosoft.vx.logic

import android.content.Context
import android.media.AudioDeviceInfo
import android.media.AudioManager
import com.neborosoft.androidutils.AssetUtils
import io.github.landerlyoung.jenny.NativeClass
import io.github.landerlyoung.jenny.NativeMethodProxy
import io.github.landerlyoung.jenny.NativeProxy
import java.lang.IllegalStateException

private const val SFZ_ASSET = "Sfz"
private const val SFZ_FILE_NAME = "piano.sfz"
private const val METRONOME_DATA_ASSET = "metronome.wav"

@NativeClass
object AndroidApplicationModel {
    private external fun initNative(context: Context,
                                    sfzPath: String,
                                    metronomeDataPath: String)

    fun init(context: Context, previousAppVersion: Long, currentAppVersion: Long) {
        val sfzPath = AssetUtils.extractAssetsToAppDirectory(
            context,
            assetName = SFZ_ASSET,
            forceCopyAssets = false
        )

        val audioManager = context.getSystemService(Context.AUDIO_SERVICE) as AudioManager
        val devices = audioManager.getDevices(AudioManager.GET_DEVICES_INPUTS)
        val microphone = devices.find {
            it.type == AudioDeviceInfo.TYPE_BUILTIN_MIC
        } ?: throw IllegalStateException("Built in microphone not found")

        initNative(
            sfzPath = "$sfzPath/$SFZ_FILE_NAME",
            metronomeDataPath = AssetUtils.extractAssetsToAppDirectory(
                context,
                assetName = METRONOME_DATA_ASSET,
                forceCopyAssets = false
            )
        )
    }
}