package com.neborosoft.androidutils

import android.content.Context

object DimensionUtils {
    fun getPixelTextSizeFromSp(context: Context, sp: Float): Float {
        return sp * context.resources.displayMetrics.scaledDensity;
    }
}