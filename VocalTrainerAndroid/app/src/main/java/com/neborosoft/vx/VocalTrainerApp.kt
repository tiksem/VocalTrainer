package com.neborosoft.vx

import com.neborosoft.androidutils.VersionedApplication
import com.neborosoft.vx.logic.AndroidApplicationModel

class VocalTrainerApp : VersionedApplication() {

    override fun onCreate(currentAppVersion: Long, previousAppVersion: Long) {
        AndroidApplicationModel.init(
            this,
            currentAppVersion = currentAppVersion,
            previousAppVersion = previousAppVersion,
        )
    }
}