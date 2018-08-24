include(CppUtils/CppUtils.pri)

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += \
    $$PWD/Pitch.h \
    $$PWD/PitchDetectionSmoothingAudioBuffer.h \
    $$PWD/YinPitchDetector.h \
    $$PWD/PitchInputReader.h \
    $$PWD/PitchInputReaderCollector.h \
    $$PWD/AudioInputReader.h \
    $$PWD/WAVFile.h \
    $$PWD/AudioUtils.h \
    $$PWD/AubioPitchDetector.h \
    $$PWD/PortAudioUtils.h


SOURCES += \
    $$PWD/Pitch.cpp \
    $$PWD/YinPitchDetector.cpp \
    $$PWD/PitchInputReader.cpp \
    $$PWD/PitchInputReaderCollector.cpp \
    $$PWD/PitchesCollector.cpp \
    $$PWD/PitchDetectionSmoothingAudioBuffer.cpp \
    $$PWD/AudioUtils.cpp \
    $$PWD/WAVFile.cpp \
    $$PWD/AubioPitchDetector.cpp \
    $$PWD/PortAudioUtils.cpp

win32 {
SOURCES += \
    $$PWD/AudioInputReader_win.cpp

}
macx {
SOURCES += \
    $$PWD/AudioInputReader_mac.cpp
}
INCLUDEPATH += ../include