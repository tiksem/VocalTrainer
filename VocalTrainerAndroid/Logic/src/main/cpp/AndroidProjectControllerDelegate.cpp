//
// Created by Semyon Tikhonenko on 12/28/21.
//

#include "AndroidProjectControllerDelegate.h"
#include "RecordingsProviderBridge.h"

void AndroidProjectControllerDelegate::add(const ProjectControllerBridgeDelegate &delegate) {
    delegates.push_back(delegate);
}

void AndroidProjectControllerDelegate::remove(const ProjectControllerBridgeDelegate &delegate) {
    CppUtils::RemoveIf(delegates, [&] (const auto& o) {
        return o.getJavaObject() == delegate.getJavaObject();
    });
}

void AndroidProjectControllerDelegate::updateAudioLevel(double level) {
    for (auto& d : delegates) {
        d.updateAudioLevel(level);
    }
}

void AndroidProjectControllerDelegate::updateSeek(double seek) {
    for (auto& d : delegates) {
        d.updateSeek(seek);
    }
}

void AndroidProjectControllerDelegate::onPlaybackStarted() {
    for (auto& d : delegates) {
        d.playbackDidStart();
    }
}

void AndroidProjectControllerDelegate::onPlaybackStopped() {
    for (auto& d : delegates) {
        d.playbackDidStop();
    }
}

void AndroidProjectControllerDelegate::updateLyricsLines(
        const LyricsDisplayedLinesProvider *linesProvider) {
    for (auto& d : delegates) {
        d.updateCurrentLyricsLines(linesProvider);
    }
}

void AndroidProjectControllerDelegate::updateLyricsSelection(
        const LyricsPlayer::Selection &selection) {
    for (auto& d : delegates) {
        d.updateLyricsSelection(selection.lineSelection.charactersCount,
                                selection.lineSelection.lastCharacterSelectionPosition,
                                selection.lineIndex);
    }
}

void AndroidProjectControllerDelegate::updateLyricsVisibilityChanged(bool showLyrics) {
}

void AndroidProjectControllerDelegate::onMetronomeEnabledChanged(bool enabled) {
    for (auto& d : delegates) {
        d.updateMetronomeEnabled(enabled);
    }
}

void AndroidProjectControllerDelegate::onTracksVisibilityChanged(bool value) {
}

void AndroidProjectControllerDelegate::updateVocalPianoVolume(float volume) {
    for (auto& d : delegates) {
        d.updateVocalPianoVolume(volume);
    }
}

void AndroidProjectControllerDelegate::updateInstrumentalVolume(float volume) {
    for (auto& d : delegates) {
        d.updateInstrumentalVolume(volume);
    }
}

void AndroidProjectControllerDelegate::updateVocalVolume(float volume) {
    for (auto& d : delegates) {
        d.updateVocalVolume(volume);
    }
}

void AndroidProjectControllerDelegate::updateInputSensitivity(float value) {
}

void AndroidProjectControllerDelegate::updateZoom(float value) {
    for (auto& d : delegates) {
        d.updateZoom(value);
    }
}

void AndroidProjectControllerDelegate::updateTonality(int shift) {
    for (auto& d : delegates) {
        d.updateTonality(shift);
    }
}

void AndroidProjectControllerDelegate::updateTempoFactor(double tempoFactor) {
    for (auto& d : delegates) {
        d.updateTempo(tempoFactor);
    }
}

void AndroidProjectControllerDelegate::updateEndSeek(double endSeek) {
    for (auto& d : delegates) {
        d.updateEndSeek(endSeek);
    }
}

void AndroidProjectControllerDelegate::onRewindStatusChanged(bool rewindRunning, bool backward) {
}

void AndroidProjectControllerDelegate::showSingingCompletionFlow(
        SingingCompletionFlow *songCompletionFlow) {
    for (auto& d : delegates) {
        d.showSingingCompletionFlow(new SingingCompletionFlowBridge(songCompletionFlow), nullptr);
    }
}

void AndroidProjectControllerDelegate::hideSingingCompletionFlow() {
    for (auto& d : delegates) {
        d.hideSingingCompletionFlow();
    }
}

void AndroidProjectControllerDelegate::startListeningToRecording(MvxFile *recording) {
    for (auto& d : delegates) {
        d.startListeningToRecording(reinterpret_cast<int64_t>(recording));
    }
}

std::shared_ptr<std::ostream>
AndroidProjectControllerDelegate::createStreamToSaveRecording(const VocalTrainerFile *recording) {
    auto newFilePath = RecordingsProviderBridge::instance().newRecordingFileName();
    return std::make_shared<std::fstream>(newFilePath.data(), std::ios::out);
}
