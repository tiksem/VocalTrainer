cmake_minimum_required(VERSION 3.12)
project(Logic)

set(sources
        CppUtils/Color.cpp
        CppUtils/AudioUtils.cpp
        CppUtils/Bitmap.cpp
        CppUtils/Executors.cpp
        CppUtils/FileUtils.cpp
        CppUtils/OperationCanceler.cpp
        CppUtils/StringEncodingUtils.cpp
        CppUtils/WAVFile.cpp
        CppUtils/TimeUtils.cpp
        CppUtils/android/AndroidExecutor.cpp
        CppUtils/jni/JniUTFString.cpp

        ApplicationModel.cpp

        BaseAudio/AudioStreamDescription.cpp
        BaseAudio/Android/AAudioUtils.cpp
        BaseAudio/Android/AndroidAudioDeviceProvider.cpp
        BaseAudio/Android/AAudioStreamWrapper.cpp

        Playback/Base/BaseAudioPlayer.cpp
        Playback/Base/AudioOperationFailedException.cpp
        Playback/Base/AudioPlayerWithDefaultSeekHandler.cpp
        Playback/Base/PlaybackBounds.cpp
        Playback/Base/VocalTrainerFile.cpp
        Playback/Base/Buffer/AudioDataBuffer.cpp
        Playback/Base/Android/AAudioOutputWriter.cpp

        Playback/Other/MetronomeAudioPlayer.cpp
        Playback/Mvx/VocalTrainerFilePlayer.cpp

        Playback/Vx/SfzPitchRenderer.cpp
        Playback/Vx/PitchDuration.cpp
        Playback/Vx/TimeSignature.cpp
        Playback/Vx/VocalPart.cpp
        Playback/Vx/VocalPartAudioDataGenerator.cpp
        Playback/Vx/VocalPartAudioPlayer.cpp
        Playback/Vx/VxFile.cpp

        Pitch/Pitch.cpp
        Pitch/SeekablePitchesList.cpp
        Pitch/Tonality.cpp
        Pitch/PitchesMutableList.cpp

        Controllers/ProjectController.cpp
        Controllers/RecordingsListController.cpp

        Drawers/Drawer.cpp
        Drawers/OpenGLNvgDrawer.cpp
        Drawers/NvgDrawer.cpp

        AudioInput/AudioAverageInputLevelMonitor.cpp
        AudioInput/AudioInputPitchesRecorder.cpp
        AudioInput/AudioInputRecorder.cpp
        AudioInput/PitchDetection/PitchInputReader.cpp
        AudioInput/Android/AAudioInputReader.cpp

        AudioInput/PitchDetection/SevaghPitchDetector.cpp
        AudioInput/PitchDetection/Sevagh/autocorrelation.cpp
        AudioInput/PitchDetection/Sevagh/hmm.cpp
        AudioInput/PitchDetection/Sevagh/mpm.cpp
        AudioInput/PitchDetection/Sevagh/parabolic_interpolation.cpp
        AudioInput/PitchDetection/Sevagh/yin.cpp
        AudioInput/PitchDetection/PitchDetectionSmoothingAudioBuffer.cpp
        AudioInput/Android/AAudioInputReader.cpp

        Manager/AudioInputManager.cpp

        FFT/FFT.cpp
        FFT/muFFT/fft.c
        FFT/muFFT/cpu.c
        FFT/muFFT/kernel.c
        FFT/muFFT/MuFFT.cpp

        nanovg/nanovg.cpp
        )

set(includes
        ../include
        ../include/nanovg

        CppUtils
        CppUtils/serialization
        CppUtils/jni

        BaseAudio
        BaseAudio/Android

        Playback/Base
        Playback/Base/Buffer
        Playback
        Playback/Mvx
        Playback/Vx
        Playback/Decoding
        Playback/Decoding/Decoder
        Playback/Other
        Playback/liquidsfz

        Pitch

        AudioInput
        AudioInput/Android
        AudioInput/PitchDetection
        AudioInput/PitchDetection/Sevagh

        Manager
        Workspace
        Drawers

        FFT
)

list(TRANSFORM sources PREPEND logic/)
list(TRANSFORM includes PREPEND logic/)

include_directories(${includes} logic/)

add_library(
        Logic
        SHARED
        AndroidApplicationModel.cpp
        setup.cpp
        JavaObject.h
        ${sources}
)

target_compile_features(Logic PRIVATE cxx_std_17)

target_link_libraries(Logic
        ${CMAKE_SOURCE_DIR}/logic/libs/android/arm64-v8a/libmlpack.a
        android
        log
        EGL
        GLESv3
        )
