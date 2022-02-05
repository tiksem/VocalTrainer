package com.neborosoft.vx.logic

import com.neborosoft.annotations.*

@CppAccessibleInterface
interface ProjectControllerBridgeDelegate {
    fun updateAudioLevel(value: Double)
    fun updateSeek(value: Double)
    fun playbackDidStart()
    fun playbackDidStop()
    fun updateLyricsSelection(
        selectedCharactersCount: Int,
        lastCharacterSelectionPosition: Double,
        lineIndex: Int
    )
    fun updateCurrentLyricsLines(@CppParam(cppType = "const LyricsDisplayedLinesProvider*") lines: Array<String>)
    fun updateMetronomeEnabled(enabled: Boolean)
    fun updateVocalPianoVolume(value: Float)
    fun updateInstrumentalVolume(value: Float)
    fun updateVocalVolume(value: Float)
    fun updateZoom(zoom: Float)
    fun updateTonality(pitchShift: Int)
    fun updateTempo(factor: Double)
    fun updateEndSeek(value: Double)
    fun showSingingCompletionFlow(flow: SingingCompletionFlowBridge)
    fun hideSingingCompletionFlow()
    fun startListeningToRecording(recordingPtr: Long)
}

@CppClass
interface ProjectControllerBridge : Releasable {
    fun addDelegate(delegate: ProjectControllerBridgeDelegate)
    fun removeDelegate(delegate: ProjectControllerBridgeDelegate)

    fun getArtistName(): String
    fun getSongTitle(): String

    fun getMaxZoom(): Float
    fun getMinZoom(): Float
    fun getZoom(): Float
    fun setZoomIntoPoint(zoom: Float, @CppParam(cppType = "CppUtils::PointF") point: FloatArray)

    fun getVerticalScrollPosition(): Float

    fun isMetronomeEnabled(): Boolean
    fun isPlaying(): Boolean
    fun isRecording(): Boolean

    @CppMethod(cppType = "std::vector<Lyrics::Section>")
    fun getLyricsSections(): Array<LyricsSection>
    @CppMethod(cppType = "Tonality")
    fun getOriginalTonality(): SongTonality
    fun getBeatsPerMinute(): Double
    fun getOriginalBeatsPerMinute(): Double
    fun getEndSeek(): Double
    fun getLinesCount(): Int
    fun hasPlaybackSource(): Boolean
    fun setPlaybackSourceFilePath(filePath: String)
    fun setPlaybackSourcePtr(playbackSourcePtr: Long)

    fun toggleMetronomeEnabled()
    fun togglePlay()
    fun stop()

    fun setPlaybackProgress(progress: Double)
    fun convertSeekToPlaybackProgress(seek: Double): Double

    fun setVocalVolume(value: Float)
    fun setVocalPianoVolume(value: Float)
    fun setInstrumentalVolume(value: Float)

    fun setTempoFactor(factor: Double)
    fun setPitchShift(shift: Int)

    fun getLyricsLine(index: Int): String
    fun setPlaybackBounds(firstLineIndex: Int, lastLineIndex: Int)
    fun clearPlaybackBounds()
    fun hasPlaybackBounds(): Boolean

    fun getRecordingPreviewSamples(numberOfSamples: Int): FloatArray
}