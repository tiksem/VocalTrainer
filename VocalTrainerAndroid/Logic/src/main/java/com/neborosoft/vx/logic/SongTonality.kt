package com.neborosoft.vx.logic

import com.neborosoft.annotations.KotlinCppConstructor

@KotlinCppConstructor
class SongTonality(
    val pitchInOctaveIndex: Int,
    val isMajor: Boolean
)