package com.neborosoft.vx.logic

import com.neborosoft.annotations.KotlinCppConstructor

enum class LyricsSectionType {
    CHORUS, VERSE, BRIDGE
}

@KotlinCppConstructor
class LyricsSection(
    type: Int,
    val number: Int,
    val seek: Double,
    val firstLineIndex: Int,
    val linesCount: Int
) {
   val type = LyricsSectionType.values().getOrNull(type)
       ?: throw IllegalArgumentException("invalid LyricsSectionType index $type")
}