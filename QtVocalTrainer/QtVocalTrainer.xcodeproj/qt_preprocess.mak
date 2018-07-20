#############################################################################
# Makefile for building: QtVocalTrainer.app/Contents/MacOS/QtVocalTrainer
# Generated by qmake (3.1) (Qt 5.11.0)
# Project:  QtVocalTrainer.pro
# Template: app
# Command: /Users/semyon/Qt/5.11.0/clang_64/bin/qmake -o QtVocalTrainer.xcodeproj/project.pbxproj QtVocalTrainer.pro -spec macx-xcode CONFIG+=debug CONFIG+=x86_64 CONFIG+=qml_debug
#############################################################################

MAKEFILE      = project.pbxproj

MOC       = /Users/semyon/Qt/5.11.0/clang_64/bin/moc
UIC       = /Users/semyon/Qt/5.11.0/clang_64/bin/uic
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = -DQT_DEPRECATED_WARNINGS -DQT_QML_DEBUG -DQT_QUICKWIDGETS_LIB -DQT_QUICK_LIB -DQT_SVG_LIB -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_QML_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB
INCPATH       = -I. -I../include -I../VocalTrainer/Drawers -I../VocalTrainer/Manager -I../VocalTrainer/Workspace -I../VocalTrainer/VxPlayer/AudioPlayback -I../VocalTrainer/VxPlayer -I../VocalTrainer/VxPlayer/CraigsappMidifile -I../VocalTrainer -I../PitchDetection/CppUtils -I../PitchDetection -I../include/nanovg -I../../../Qt/5.11.0/clang_64/lib/QtQuickWidgets.framework/Headers -I../../../Qt/5.11.0/clang_64/lib/QtQuick.framework/Headers -I../../../Qt/5.11.0/clang_64/lib/QtSvg.framework/Headers -I../../../Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers -I../../../Qt/5.11.0/clang_64/lib/QtGui.framework/Headers -I../../../Qt/5.11.0/clang_64/lib/QtQml.framework/Headers -I../../../Qt/5.11.0/clang_64/lib/QtNetwork.framework/Headers -I../../../Qt/5.11.0/clang_64/lib/QtCore.framework/Headers -I. -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/System/Library/Frameworks/OpenGL.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/System/Library/Frameworks/AGL.framework/Headers -I../../../Qt/5.11.0/clang_64/mkspecs/macx-clang -F/Users/semyon/Qt/5.11.0/clang_64/lib
DEL_FILE  = rm -f
MOVE      = mv -f

preprocess: compilers
clean preprocess_clean: compiler_clean

mocclean: compiler_moc_header_clean compiler_moc_objc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_objc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compilers: qrc_qml.cpp moc_predefs.h moc_QmlCppBridge.cpp moc_qmlopenglitem.cpp moc_qmlpitch.cpp\
	 moc_qmlpitchinputreader.cpp moc_qmlvxpitch.cpp moc_qmltimedpitch.cpp\
	 moc_mainwindow.cpp moc_qmlzoomcontroller.cpp moc_player.cpp\
	 moc_qopenglworkspacewidget.cpp
compiler_rcc_make_all: qrc_qml.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_qml.cpp
qrc_qml.cpp: qml.qrc \
		../../../Qt/5.11.0/clang_64/bin/rcc \
		qml/ButtonShadow.qml \
		qml/TrackButton.qml \
		qml/SvgImage.qml \
		qml/Yardstick.qml \
		qml/ImageButton.qml \
		qml/Main.qml \
		qml/HeaderWithSubHeader.qml \
		qml/SingingProcessManager.qml \
		qml/ToggleButton.qml \
		qml/AppWindow.qml \
		qml/Header.qml \
		qml/TonalityController.qml \
		qml/PlayerController.qml \
		qml/WorkspaceOld.qml \
		qml/HorizontalLine.qml \
		qml/HorizontalScrollBar.qml \
		qml/VerticalLine.qml \
		qml/Zoom.qml \
		qml/ZoomSlider.qml \
		qml/TrackVolumeSlider.qml \
		qml/Tempo.qml \
		qml/Piano.qml \
		qml/FeaturesToggleButton.qml \
		qml/Track.qml \
		qml/VerticalScrollBar.qml \
		qml/Circle.qml \
		qml/PlayHeadTime.qml \
		qml/TracksContainer.qml \
		qml/js/strings.js \
		qml/js/uiutils.js \
		qml/js/canvasutils.js \
		qml/js/mathutils.js \
		qml/js/zoom.js \
		qml/images/to_the_begining_hover.svg \
		qml/images/play_head_triangle.svg \
		qml/images/track_piece_small.png \
		qml/images/metronome_off.svg \
		qml/images/lyrics_show_button_on.svg \
		qml/images/to_the_begining.svg \
		qml/images/player_background.svg \
		qml/images/loop_off.svg \
		qml/images/lyrics_show_button_off.png \
		qml/images/tonality_up.svg \
		qml/images/loop_on.svg \
		qml/images/go_forward_hover.svg \
		qml/images/tonality_up_pressed.svg \
		qml/images/metronome_on.svg \
		qml/images/play_on.svg \
		qml/images/metronome_off.png \
		qml/images/tonality_controller_left.svg \
		qml/images/tonality_down_pressed.svg \
		qml/images/speaker.svg \
		qml/images/player_background.png \
		qml/images/play_off.svg \
		qml/images/tracks_show_button_off.svg \
		qml/images/go_forward.svg \
		qml/images/go_back_hover.svg \
		qml/images/tracks_show_button_on.svg \
		qml/images/tempo_background.svg \
		qml/images/tonality_down.svg \
		qml/images/go_back.svg \
		qml/images/lyrics_show_button_off.svg \
		qml/images/instrumental_track_button.svg \
		qml/images/zoom_slider_triangle.svg \
		qml/images/tracks_show_button_off.png \
		qml/images/track_piece.png \
		qml/sounds/sounds.sf2 \
		qml/fonts/Lato-Regular.ttf \
		qml/fonts/Lato-Bold.ttf
	/Users/semyon/Qt/5.11.0/clang_64/bin/rcc -name qml qml.qrc -o qrc_qml.cpp

compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: ../../../Qt/5.11.0/clang_64/mkspecs/features/data/dummy.cpp
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ -pipe -stdlib=libc++ -g -std=gnu++1y -Wall -W -dM -E -o moc_predefs.h ../../../Qt/5.11.0/clang_64/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_QmlCppBridge.cpp moc_qmlopenglitem.cpp moc_qmlpitch.cpp moc_qmlpitchinputreader.cpp moc_qmlvxpitch.cpp moc_qmltimedpitch.cpp moc_mainwindow.cpp moc_qmlzoomcontroller.cpp moc_player.cpp moc_qopenglworkspacewidget.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_QmlCppBridge.cpp moc_qmlopenglitem.cpp moc_qmlpitch.cpp moc_qmlpitchinputreader.cpp moc_qmlvxpitch.cpp moc_qmltimedpitch.cpp moc_mainwindow.cpp moc_qmlzoomcontroller.cpp moc_player.cpp moc_qopenglworkspacewidget.cpp
moc_QmlCppBridge.cpp: ../../../Qt/5.11.0/clang_64/lib/QtCore.framework/Headers/QObject \
		../../../Qt/5.11.0/clang_64/lib/QtCore.framework/Headers/QSize \
		../../../Qt/5.11.0/clang_64/lib/QtQuick.framework/Headers/QQuickView \
		qmlpitch.h \
		../PitchDetection/Pitch.h \
		mainwindow.h \
		../../../Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers/QMainWindow \
		../../../Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers/QOpenGLWidget \
		../../../Qt/5.11.0/clang_64/lib/QtQuickWidgets.framework/Headers/QQuickWidget \
		../../../Qt/5.11.0/clang_64/lib/QtSvg.framework/Headers/QSvgWidget \
		QtUtils/qtutils.h \
		../../../Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers/QFrame \
		qmlzoomcontroller.h \
		../VocalTrainer/Manager/ZoomController.h \
		../PitchDetection/CppUtils/ListenersSet.h \
		player.h \
		../VocalTrainer/VxPlayer/MvxPlayer.h \
		../VocalTrainer/VxPlayer/VxFile.h \
		../VocalTrainer/VxPlayer/VxPitch.h \
		../include/boost/serialization/serialization.hpp \
		../include/boost/serialization/split_member.hpp \
		../VocalTrainer/VxPlayer/AudioPlayback/AudioPlayer.h \
		../include/portaudio/portaudio.h \
		../VocalTrainer/VxPlayer/VxLyricsLine.h \
		../VocalTrainer/VxPlayer/VxLyricsInterval.h \
		../VocalTrainer/VxPlayer/PlaybackChunk.h \
		../include/boost/container/static_vector.hpp \
		../include/boost/serialization/vector.hpp \
		../PitchDetection/CppUtils/StlDebugUtils.h \
		../VocalTrainer/VxPlayer/MvxFile.h \
		../VocalTrainer/VxPlayer/AudioPlayback/VxFileAudioPlayer.h \
		../VocalTrainer/VxPlayer/ParallelVxFileAudioDataGenerator.h \
		../VocalTrainer/VxPlayer/tsf.h \
		../VocalTrainer/VxPlayer/PitchRenderer.h \
		../include/boost/icl/interval_set.hpp \
		../PitchDetection/CppUtils/PeriodicallySleepingBackgroundTask.h \
		../PitchDetection/CppUtils/SynchronizedCallbacksQueue.h \
		../include/boost/lockfree/queue.hpp \
		../include/boost/optional.hpp \
		../VocalTrainer/VxPlayer/PlayingPitchSequence.h \
		qmlvxpitch.h \
		../../../Qt/5.11.0/clang_64/lib/QtCore.framework/Headers/QJsonValue \
		qmlpitchinputreader.h \
		../PitchDetection/PitchInputReaderCollector.h \
		../PitchDetection/PitchInputReader.h \
		../PitchDetection/AudioInputReader.h \
		../PitchDetection/YinPitchDetector.h \
		../PitchDetection/PitchDetector.h \
		../PitchDetection/PitchDetectionSmoothingAudioBuffer.h \
		../PitchDetection/CppUtils/stlassert.h \
		../PitchDetection/CppUtils/CircularBuffer.h \
		../PitchDetection/PitchesCollector.h \
		../VocalTrainer/Manager/VxPitchInputReader.h \
		qmltimedpitch.h \
		QmlCppBridge.h \
		moc_predefs.h \
		../../../Qt/5.11.0/clang_64/bin/moc
	/Users/semyon/Qt/5.11.0/clang_64/bin/moc $(DEFINES) --include ./moc_predefs.h -I/Users/semyon/Qt/5.11.0/clang_64/mkspecs/macx-clang -I/Users/semyon/Projects/VocalTrainer/QtVocalTrainer -I/Users/semyon/Projects/VocalTrainer/include -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Drawers -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Manager -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Workspace -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/AudioPlayback -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/CraigsappMidifile -I/Users/semyon/Projects/VocalTrainer/VocalTrainer -I/Users/semyon/Projects/VocalTrainer/PitchDetection/CppUtils -I/Users/semyon/Projects/VocalTrainer/PitchDetection -I/Users/semyon/Projects/VocalTrainer/include/nanovg -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuickWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuick.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtSvg.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtGui.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQml.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtNetwork.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/include -F/Users/semyon/Qt/5.11.0/clang_64/lib QmlCppBridge.h -o moc_QmlCppBridge.cpp

moc_qmlopenglitem.cpp: ../../../Qt/5.11.0/clang_64/lib/QtQuick.framework/Headers/QQuickItem \
		qmlopenglitem.h \
		moc_predefs.h \
		../../../Qt/5.11.0/clang_64/bin/moc
	/Users/semyon/Qt/5.11.0/clang_64/bin/moc $(DEFINES) --include ./moc_predefs.h -I/Users/semyon/Qt/5.11.0/clang_64/mkspecs/macx-clang -I/Users/semyon/Projects/VocalTrainer/QtVocalTrainer -I/Users/semyon/Projects/VocalTrainer/include -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Drawers -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Manager -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Workspace -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/AudioPlayback -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/CraigsappMidifile -I/Users/semyon/Projects/VocalTrainer/VocalTrainer -I/Users/semyon/Projects/VocalTrainer/PitchDetection/CppUtils -I/Users/semyon/Projects/VocalTrainer/PitchDetection -I/Users/semyon/Projects/VocalTrainer/include/nanovg -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuickWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuick.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtSvg.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtGui.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQml.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtNetwork.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/include -F/Users/semyon/Qt/5.11.0/clang_64/lib qmlopenglitem.h -o moc_qmlopenglitem.cpp

moc_qmlpitch.cpp: ../../../Qt/5.11.0/clang_64/lib/QtCore.framework/Headers/QObject \
		../PitchDetection/Pitch.h \
		qmlpitch.h \
		moc_predefs.h \
		../../../Qt/5.11.0/clang_64/bin/moc
	/Users/semyon/Qt/5.11.0/clang_64/bin/moc $(DEFINES) --include ./moc_predefs.h -I/Users/semyon/Qt/5.11.0/clang_64/mkspecs/macx-clang -I/Users/semyon/Projects/VocalTrainer/QtVocalTrainer -I/Users/semyon/Projects/VocalTrainer/include -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Drawers -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Manager -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Workspace -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/AudioPlayback -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/CraigsappMidifile -I/Users/semyon/Projects/VocalTrainer/VocalTrainer -I/Users/semyon/Projects/VocalTrainer/PitchDetection/CppUtils -I/Users/semyon/Projects/VocalTrainer/PitchDetection -I/Users/semyon/Projects/VocalTrainer/include/nanovg -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuickWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuick.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtSvg.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtGui.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQml.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtNetwork.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/include -F/Users/semyon/Qt/5.11.0/clang_64/lib qmlpitch.h -o moc_qmlpitch.cpp

moc_qmlpitchinputreader.cpp: ../../../Qt/5.11.0/clang_64/lib/QtCore.framework/Headers/QObject \
		../PitchDetection/PitchInputReaderCollector.h \
		../PitchDetection/Pitch.h \
		../PitchDetection/PitchInputReader.h \
		../PitchDetection/AudioInputReader.h \
		../PitchDetection/YinPitchDetector.h \
		../PitchDetection/PitchDetector.h \
		../PitchDetection/PitchDetectionSmoothingAudioBuffer.h \
		../PitchDetection/CppUtils/stlassert.h \
		../PitchDetection/CppUtils/CircularBuffer.h \
		../PitchDetection/PitchesCollector.h \
		../PitchDetection/CppUtils/ListenersSet.h \
		../VocalTrainer/Manager/VxPitchInputReader.h \
		qmltimedpitch.h \
		qmlpitch.h \
		qmlpitchinputreader.h \
		moc_predefs.h \
		../../../Qt/5.11.0/clang_64/bin/moc
	/Users/semyon/Qt/5.11.0/clang_64/bin/moc $(DEFINES) --include ./moc_predefs.h -I/Users/semyon/Qt/5.11.0/clang_64/mkspecs/macx-clang -I/Users/semyon/Projects/VocalTrainer/QtVocalTrainer -I/Users/semyon/Projects/VocalTrainer/include -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Drawers -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Manager -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Workspace -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/AudioPlayback -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/CraigsappMidifile -I/Users/semyon/Projects/VocalTrainer/VocalTrainer -I/Users/semyon/Projects/VocalTrainer/PitchDetection/CppUtils -I/Users/semyon/Projects/VocalTrainer/PitchDetection -I/Users/semyon/Projects/VocalTrainer/include/nanovg -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuickWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuick.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtSvg.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtGui.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQml.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtNetwork.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/include -F/Users/semyon/Qt/5.11.0/clang_64/lib qmlpitchinputreader.h -o moc_qmlpitchinputreader.cpp

moc_qmlvxpitch.cpp: ../../../Qt/5.11.0/clang_64/lib/QtCore.framework/Headers/QObject \
		qmlpitch.h \
		../PitchDetection/Pitch.h \
		../VocalTrainer/VxPlayer/VxPitch.h \
		../include/boost/serialization/serialization.hpp \
		../include/boost/serialization/split_member.hpp \
		qmlvxpitch.h \
		moc_predefs.h \
		../../../Qt/5.11.0/clang_64/bin/moc
	/Users/semyon/Qt/5.11.0/clang_64/bin/moc $(DEFINES) --include ./moc_predefs.h -I/Users/semyon/Qt/5.11.0/clang_64/mkspecs/macx-clang -I/Users/semyon/Projects/VocalTrainer/QtVocalTrainer -I/Users/semyon/Projects/VocalTrainer/include -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Drawers -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Manager -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Workspace -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/AudioPlayback -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/CraigsappMidifile -I/Users/semyon/Projects/VocalTrainer/VocalTrainer -I/Users/semyon/Projects/VocalTrainer/PitchDetection/CppUtils -I/Users/semyon/Projects/VocalTrainer/PitchDetection -I/Users/semyon/Projects/VocalTrainer/include/nanovg -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuickWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuick.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtSvg.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtGui.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQml.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtNetwork.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/include -F/Users/semyon/Qt/5.11.0/clang_64/lib qmlvxpitch.h -o moc_qmlvxpitch.cpp

moc_qmltimedpitch.cpp: qmlpitch.h \
		../../../Qt/5.11.0/clang_64/lib/QtCore.framework/Headers/QObject \
		../PitchDetection/Pitch.h \
		qmltimedpitch.h \
		moc_predefs.h \
		../../../Qt/5.11.0/clang_64/bin/moc
	/Users/semyon/Qt/5.11.0/clang_64/bin/moc $(DEFINES) --include ./moc_predefs.h -I/Users/semyon/Qt/5.11.0/clang_64/mkspecs/macx-clang -I/Users/semyon/Projects/VocalTrainer/QtVocalTrainer -I/Users/semyon/Projects/VocalTrainer/include -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Drawers -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Manager -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Workspace -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/AudioPlayback -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/CraigsappMidifile -I/Users/semyon/Projects/VocalTrainer/VocalTrainer -I/Users/semyon/Projects/VocalTrainer/PitchDetection/CppUtils -I/Users/semyon/Projects/VocalTrainer/PitchDetection -I/Users/semyon/Projects/VocalTrainer/include/nanovg -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuickWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuick.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtSvg.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtGui.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQml.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtNetwork.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/include -F/Users/semyon/Qt/5.11.0/clang_64/lib qmltimedpitch.h -o moc_qmltimedpitch.cpp

moc_mainwindow.cpp: ../../../Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers/QMainWindow \
		../../../Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers/QOpenGLWidget \
		../../../Qt/5.11.0/clang_64/lib/QtQuickWidgets.framework/Headers/QQuickWidget \
		../../../Qt/5.11.0/clang_64/lib/QtSvg.framework/Headers/QSvgWidget \
		QtUtils/qtutils.h \
		../../../Qt/5.11.0/clang_64/lib/QtCore.framework/Headers/QObject \
		../../../Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers/QFrame \
		mainwindow.h \
		moc_predefs.h \
		../../../Qt/5.11.0/clang_64/bin/moc
	/Users/semyon/Qt/5.11.0/clang_64/bin/moc $(DEFINES) --include ./moc_predefs.h -I/Users/semyon/Qt/5.11.0/clang_64/mkspecs/macx-clang -I/Users/semyon/Projects/VocalTrainer/QtVocalTrainer -I/Users/semyon/Projects/VocalTrainer/include -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Drawers -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Manager -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Workspace -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/AudioPlayback -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/CraigsappMidifile -I/Users/semyon/Projects/VocalTrainer/VocalTrainer -I/Users/semyon/Projects/VocalTrainer/PitchDetection/CppUtils -I/Users/semyon/Projects/VocalTrainer/PitchDetection -I/Users/semyon/Projects/VocalTrainer/include/nanovg -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuickWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuick.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtSvg.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtGui.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQml.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtNetwork.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/include -F/Users/semyon/Qt/5.11.0/clang_64/lib mainwindow.h -o moc_mainwindow.cpp

moc_qmlzoomcontroller.cpp: ../../../Qt/5.11.0/clang_64/lib/QtCore.framework/Headers/QObject \
		qmlpitch.h \
		../PitchDetection/Pitch.h \
		../VocalTrainer/Manager/ZoomController.h \
		../PitchDetection/CppUtils/ListenersSet.h \
		qmlzoomcontroller.h \
		moc_predefs.h \
		../../../Qt/5.11.0/clang_64/bin/moc
	/Users/semyon/Qt/5.11.0/clang_64/bin/moc $(DEFINES) --include ./moc_predefs.h -I/Users/semyon/Qt/5.11.0/clang_64/mkspecs/macx-clang -I/Users/semyon/Projects/VocalTrainer/QtVocalTrainer -I/Users/semyon/Projects/VocalTrainer/include -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Drawers -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Manager -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Workspace -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/AudioPlayback -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/CraigsappMidifile -I/Users/semyon/Projects/VocalTrainer/VocalTrainer -I/Users/semyon/Projects/VocalTrainer/PitchDetection/CppUtils -I/Users/semyon/Projects/VocalTrainer/PitchDetection -I/Users/semyon/Projects/VocalTrainer/include/nanovg -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuickWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuick.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtSvg.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtGui.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQml.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtNetwork.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/include -F/Users/semyon/Qt/5.11.0/clang_64/lib qmlzoomcontroller.h -o moc_qmlzoomcontroller.cpp

moc_player.cpp: ../../../Qt/5.11.0/clang_64/lib/QtCore.framework/Headers/QObject \
		../VocalTrainer/VxPlayer/MvxPlayer.h \
		../VocalTrainer/VxPlayer/VxFile.h \
		../VocalTrainer/VxPlayer/VxPitch.h \
		../include/boost/serialization/serialization.hpp \
		../include/boost/serialization/split_member.hpp \
		../PitchDetection/Pitch.h \
		../VocalTrainer/VxPlayer/AudioPlayback/AudioPlayer.h \
		../include/portaudio/portaudio.h \
		../PitchDetection/CppUtils/ListenersSet.h \
		../VocalTrainer/VxPlayer/VxLyricsLine.h \
		../VocalTrainer/VxPlayer/VxLyricsInterval.h \
		../VocalTrainer/VxPlayer/PlaybackChunk.h \
		../include/boost/container/static_vector.hpp \
		../include/boost/serialization/vector.hpp \
		../PitchDetection/CppUtils/StlDebugUtils.h \
		../VocalTrainer/VxPlayer/MvxFile.h \
		../VocalTrainer/VxPlayer/AudioPlayback/VxFileAudioPlayer.h \
		../VocalTrainer/VxPlayer/ParallelVxFileAudioDataGenerator.h \
		../VocalTrainer/VxPlayer/tsf.h \
		../VocalTrainer/VxPlayer/PitchRenderer.h \
		../include/boost/icl/interval_set.hpp \
		../PitchDetection/CppUtils/PeriodicallySleepingBackgroundTask.h \
		../PitchDetection/CppUtils/SynchronizedCallbacksQueue.h \
		../include/boost/lockfree/queue.hpp \
		../include/boost/optional.hpp \
		../VocalTrainer/VxPlayer/PlayingPitchSequence.h \
		qmlvxpitch.h \
		qmlpitch.h \
		../../../Qt/5.11.0/clang_64/lib/QtCore.framework/Headers/QJsonValue \
		player.h \
		moc_predefs.h \
		../../../Qt/5.11.0/clang_64/bin/moc
	/Users/semyon/Qt/5.11.0/clang_64/bin/moc $(DEFINES) --include ./moc_predefs.h -I/Users/semyon/Qt/5.11.0/clang_64/mkspecs/macx-clang -I/Users/semyon/Projects/VocalTrainer/QtVocalTrainer -I/Users/semyon/Projects/VocalTrainer/include -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Drawers -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Manager -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Workspace -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/AudioPlayback -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/CraigsappMidifile -I/Users/semyon/Projects/VocalTrainer/VocalTrainer -I/Users/semyon/Projects/VocalTrainer/PitchDetection/CppUtils -I/Users/semyon/Projects/VocalTrainer/PitchDetection -I/Users/semyon/Projects/VocalTrainer/include/nanovg -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuickWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuick.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtSvg.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtGui.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQml.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtNetwork.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/include -F/Users/semyon/Qt/5.11.0/clang_64/lib player.h -o moc_player.cpp

moc_qopenglworkspacewidget.cpp: ../../../Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers/QOpenGLWidget \
		../VocalTrainer/Workspace/WorkspaceDrawer.h \
		../include/nanovg/nanovg.h \
		../VocalTrainer/Drawers/Drawer.h \
		../PitchDetection/CppUtils/RoundedRect.h \
		../PitchDetection/CppUtils/Point.h \
		../VocalTrainer/Drawers/DrawerColor.h \
		../VocalTrainer/VxPlayer/CraigsappMidifile/MidiEvent.h \
		../VocalTrainer/VxPlayer/CraigsappMidifile/MidiMessage.h \
		../PitchDetection/PitchesCollector.h \
		../VocalTrainer/VxPlayer/VxFile.h \
		../VocalTrainer/VxPlayer/VxPitch.h \
		../include/boost/serialization/serialization.hpp \
		../include/boost/serialization/split_member.hpp \
		../PitchDetection/Pitch.h \
		../VocalTrainer/VxPlayer/AudioPlayback/AudioPlayer.h \
		../include/portaudio/portaudio.h \
		../PitchDetection/CppUtils/ListenersSet.h \
		../VocalTrainer/VxPlayer/VxLyricsLine.h \
		../VocalTrainer/VxPlayer/VxLyricsInterval.h \
		../VocalTrainer/VxPlayer/PlaybackChunk.h \
		../include/boost/container/static_vector.hpp \
		../include/boost/serialization/vector.hpp \
		../PitchDetection/CppUtils/StlDebugUtils.h \
		../VocalTrainer/Workspace/WorkspaceController.h \
		qopenglworkspacewidget.h \
		moc_predefs.h \
		../../../Qt/5.11.0/clang_64/bin/moc
	/Users/semyon/Qt/5.11.0/clang_64/bin/moc $(DEFINES) --include ./moc_predefs.h -I/Users/semyon/Qt/5.11.0/clang_64/mkspecs/macx-clang -I/Users/semyon/Projects/VocalTrainer/QtVocalTrainer -I/Users/semyon/Projects/VocalTrainer/include -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Drawers -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Manager -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/Workspace -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/AudioPlayback -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer -I/Users/semyon/Projects/VocalTrainer/VocalTrainer/VxPlayer/CraigsappMidifile -I/Users/semyon/Projects/VocalTrainer/VocalTrainer -I/Users/semyon/Projects/VocalTrainer/PitchDetection/CppUtils -I/Users/semyon/Projects/VocalTrainer/PitchDetection -I/Users/semyon/Projects/VocalTrainer/include/nanovg -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuickWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQuick.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtSvg.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtWidgets.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtGui.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtQml.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtNetwork.framework/Headers -I/Users/semyon/Qt/5.11.0/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/usr/include -F/Users/semyon/Qt/5.11.0/clang_64/lib qopenglworkspacewidget.h -o moc_qopenglworkspacewidget.cpp

compiler_moc_objc_header_make_all:
compiler_moc_objc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_rcc_clean compiler_moc_predefs_clean compiler_moc_header_clean 

