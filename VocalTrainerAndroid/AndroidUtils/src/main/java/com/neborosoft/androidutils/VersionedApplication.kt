package com.neborosoft.androidutils

import android.app.Application
import android.content.SharedPreferences

private const val SHARED_PREFS_KEY = "app"
private const val VERSION_CODE_KEY = "versionCode"

open class VersionedApplication : Application() {
    val sharedPreferences: SharedPreferences by lazy {
        getSharedPreferences(SHARED_PREFS_KEY, MODE_PRIVATE)
    }

    final override fun onCreate() {
        super.onCreate()
        onCreate(
            currentAppVersion = AppUtils.getVersionCode(this),
            previousAppVersion = sharedPreferences.getLong(VERSION_CODE_KEY, -1)
        )
    }

    open fun onCreate(currentAppVersion: Long, previousAppVersion: Long) {
    }
}