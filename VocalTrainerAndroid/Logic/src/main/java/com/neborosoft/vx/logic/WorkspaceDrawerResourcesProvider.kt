package com.neborosoft.vx.logic

import android.R.attr
import com.neborosoft.annotations.CppAccessibleInterface
import android.R.attr.textSize
import android.R.attr.textStyle
import android.content.Context
import android.graphics.*
import com.neborosoft.androidutils.DimensionUtils
import com.neborosoft.annotations.CppMethod
import com.neborosoft.annotations.CppParam


@CppAccessibleInterface(cppClassName = "AndroidWorkspaceDrawerResourcesProvider")
class WorkspaceDrawerResourcesProvider(private val context: Context) {
    enum class FontStyle {
        NORMAL, BOLD, SEMIBOLD
    }

    @CppMethod(cppType = "CppUtils::Bitmap")
    fun createImageForCharacter(
        @CppParam(cppType = "char")
        ch: Char,
        fontSize: Int,
        @CppParam(cppType = "Drawer::Color")
        colorRgba: Int,
        @CppParam(cppType = "Drawer::FontStyle")
        fontStyleIndex: Int,
        scaleFactor: Float
    ): Bitmap {
        val fontStyle = FontStyle.values()[fontStyleIndex]

        val paint = Paint().apply {
            textSize = DimensionUtils.getPixelTextSizeFromSp(context, sp = fontSize.toFloat())
            color = colorRgba
            textAlign = Paint.Align.CENTER
            isAntiAlias = true
            Typeface.SANS_SERIF
            typeface = Typeface.defaultFromStyle(if (fontStyle == FontStyle.BOLD) {
                Typeface.BOLD
            } else {
                Typeface.NORMAL
            })
        }

        val bounds = Rect()
        paint.getTextBounds(ch.toString(), 0, 1, bounds)

        val bitmap = Bitmap.createBitmap(bounds.width(), bounds.height(), Bitmap.Config.ARGB_8888)
        val canvas = Canvas(bitmap)
        canvas.drawText(ch.toString(), 0f, 0f, paint)
        return bitmap
    }

    @CppMethod(cppType = "CppUtils::Bitmap")
    fun getPlayheadImage(width: Int, height: Int, scaleFactor: Float): Bitmap {
        return Bitmap.createBitmap(10, 10, Bitmap.Config.ARGB_8888)
    }
}