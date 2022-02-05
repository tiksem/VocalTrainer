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
        CppUtils/Timer.cpp
        CppUtils/android/AndroidExecutor.cpp
        CppUtils/jni/JniUTFString.cpp

        ApplicationModel.cpp

        BaseAudio/AudioStreamDescription.cpp
        BaseAudio/Android/AAudioUtils.cpp
        BaseAudio/Android/AAudioStreamWrapper.cpp
        BaseAudio/Android/AudioDeviceProvider.cpp

        Playback/Base/PlaybackData.cpp
        Playback/Base/BaseAudioPlayer.cpp
        Playback/Base/AudioOperationFailedException.cpp
        Playback/Base/AudioPlayerWithDefaultSeekHandler.cpp
        Playback/Base/PlaybackBounds.cpp
        Playback/Base/VocalTrainerFile.cpp
        Playback/Base/Buffer/AudioDataBuffer.cpp
        Playback/Base/Android/AAudioOutputWriter.cpp

        Playback/Other/MetronomeAudioPlayer.cpp
        Playback/Other/BaseRawPcmAudioDataPlayer.cpp
        Playback/Other/WavAudioPlayer.cpp

        Playback/Mvx/VocalTrainerFilePlayer.cpp
        Playback/Mvx/LyricsPlayer.cpp
        Playback/Mvx/Lyrics.cpp
        Playback/Mvx/MvxFile.cpp
        Playback/Mvx/VocalTrainerPlayerPrepareException.cpp
        Playback/Mvx/Rewinder.cpp

        Playback/Decoding/AudioFilePlayer.cpp
        Playback/Decoding/Decoder/AudioDecoder.cpp
        Playback/Decoding/Decoder/AndroidAudioDecoder.cpp

        Playback/Vx/SfzPitchRenderer.cpp
        Playback/Vx/PitchDuration.cpp
        Playback/Vx/TimeSignature.cpp
        Playback/Vx/VocalPart.cpp
        Playback/Vx/VocalPartAudioDataGenerator.cpp
        Playback/Vx/VocalPartAudioPlayer.cpp
        Playback/Vx/VxFile.cpp
        
        Playback/liquidsfz/hydrogenimport.cc
        Playback/liquidsfz/liquidsfz.cc
        Playback/liquidsfz/loader.cc
        Playback/liquidsfz/log.cc
        Playback/liquidsfz/pugixml.cc
        Playback/liquidsfz/synth.cc
        Playback/liquidsfz/utils.cc
        Playback/liquidsfz/voice.cc

        Pitch/Pitch.cpp
        Pitch/SeekablePitchesList.cpp
        Pitch/Tonality.cpp
        Pitch/PitchesMutableList.cpp

        Controllers/ProjectController.cpp
        Controllers/RecordingsListController.cpp

        Drawers/Drawer.cpp
        Drawers/OpenGLNvgDrawer.cpp
        Drawers/NvgDrawer.cpp

        Workspace/WorkspaceColorScheme.cpp
        Workspace/WorkspaceDrawer.cpp

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

        Events/BaseMouseEventsReceiver.cpp

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
        Events

        Controllers

        FFT
)

list(TRANSFORM sources PREPEND logic/)
list(TRANSFORM includes PREPEND logic/)

include_directories(${includes} logic/ ../cpp)

add_library(
        Logic
        SHARED
        AndroidApplicationModelFunctions.jni.cpp
        AndroidApplicationModelFunctions.cpp
        FunctionCallsBridge.cpp
        JArray.cpp
        JObject.cpp
        JString.cpp
        KotlinConstructors.cpp
        setup.cpp
        Converters.cpp
        CustomConverters.cpp

        WorkspaceRenderer.jni.cpp
        WorkspaceRenderer.cpp
        AndroidWorkspaceDrawerResourcesProvider.cpp
        ProjectControllerBridge.cpp
        ProjectControllerBridge.jni.cpp
        ProjectControllerBridgeDelegate.cpp
        AndroidProjectControllerDelegate.cpp
        SingingCompletionFlowBridge.cpp
        RecordingsProviderBridge.cpp

        ${sources}
)

target_compile_features(Logic PRIVATE cxx_std_17)

target_link_libraries(Logic
        ${CMAKE_SOURCE_DIR}/logic/libs/android/${ANDROID_ABI}/libSoundTouch.a
        ${CMAKE_SOURCE_DIR}/logic/libs/android/${ANDROID_ABI}/libsndfile.a
        android
        mediandk
        aaudio
        log
        EGL
        GLESv3
        )
