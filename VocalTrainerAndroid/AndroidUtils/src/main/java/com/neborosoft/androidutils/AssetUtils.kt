package com.neborosoft.androidutils

import android.content.Context
import java.io.File
import java.nio.file.Files
import kotlin.io.path.Path

object AssetUtils {
    fun extractAssetsToAppDirectory(
        context: Context,
        assetName: String,
        forceCopyAssets: Boolean
    ): String {
        val dataFolderPath = context.dataDir.absolutePath
        val resultPath = "$dataFolderPath/$assetName"

        if (forceCopyAssets) {
            File(resultPath).delete()
        } else if (File(resultPath).exists()) {
            return resultPath
        }

        val assets = context.assets

        fun handle(path: String) {
            assets.list(path)?.run {
                File("$dataFolderPath/$path").mkdirs()
                forEach {
                    handle(path = "$path/$it")
                }
            } ?: run {
                val asset = assets.open(path)
                Files.copy(asset, Path("$dataFolderPath/$path"))
            }
        }

        handle(path = assetName)

        return resultPath
    }
}