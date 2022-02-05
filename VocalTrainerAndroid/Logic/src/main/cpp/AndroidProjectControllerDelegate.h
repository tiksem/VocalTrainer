//
// Created by Semyon Tikhonenko on 12/28/21.
//

#ifndef VOCALTRAINERANDROID_ANDROIDPROJECTCONTROLLERDELEGATE_H
#define VOCALTRAINERANDROID_ANDROIDPROJECTCONTROLLERDELEGATE_H

#include "ProjectControllerBridgeDelegate.h"
#include "ProjectController.h"

class AndroidProjectControllerDelegate : public ProjectControllerDelegate {
    std::vector<ProjectControllerBridgeDelegate> delegates;
public:
    void add(const ProjectControllerBridgeDelegate& delegate);
    void remove(const ProjectControllerBridgeDelegate& delegate);

    void updateAudioLevel(double level) override;

    void updateSeek(double seek) override;

    void onPlaybackStarted() override;

    void onPlaybackStopped() override;

    void updateLyricsLines(const LyricsDisplayedLinesProvider *linesProvider) override;

    void updateLyricsSelection(const LyricsPlayer::Selection &selection) override;

    void updateLyricsVisibilityChanged(bool showLyrics) override;

    void onMetronomeEnabledChanged(bool enabled) override;

    void onTracksVisibilityChanged(bool value) override;

    void updateVocalPianoVolume(float volume) override;

    void updateInstrumentalVolume(float volume) override;

    void updateVocalVolume(float volume) override;

    void updateInputSensitivity(float value) override;

    void updateZoom(float value) override;

    void updateTonality(int shift) override;

    void updateTempoFactor(double tempoFactor) override;

    void updateEndSeek(double endSeek) override;

    void onRewindStatusChanged(bool rewindRunning, bool backward) override;

    void showSingingCompletionFlow(SingingCompletionFlow *songCompletionFlow) override;

    void hideSingingCompletionFlow() override;

    void startListeningToRecording(MvxFile *recording) override;

    std::shared_ptr<std::ostream>
    createStreamToSaveRecording(const VocalTrainerFile *recording) override;
};


#endif //VOCALTRAINERANDROID_ANDROIDPROJECTCONTROLLERDELEGATE_H
