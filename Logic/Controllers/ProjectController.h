//
// Created by Semyon Tykhonenko on 2019-07-12.
//

#ifndef TEXTIMAGESGENERATOR_PROJECTCONTROLLER_H
#define TEXTIMAGESGENERATOR_PROJECTCONTROLLER_H

#include <string>
#include "WorkspaceController.h"
#include "MvxPlayer.h"
#include "AudioInputManager.h"
#include "Timer.h"

class ProjectControllerDelegate {
public:
    virtual inline void updateAudioLevel(double level) {}
    virtual inline void updateSeek(double seek) {}
    virtual inline void onPlaybackStarted() {}
    virtual inline void onPlaybackStopped() {}
    virtual inline void onHasLyricsChanged(bool hasLyrics) {}
    virtual inline void updateLyricsText(const std::string& lyricsLineUtf8) {}
    virtual inline void onLyricsVisibilityChanged(bool showLyrics) {}
    virtual inline void onMetronomeEnabledChanged(bool enabled) {}
    virtual inline void onTracksVisibilityChanged(bool value) {}
    virtual inline void updateVocalPianoVolume(float volume) {}
    virtual inline void updateInstrumentalVolume(float volume) {}
    virtual inline void updateVocalVolume(float volume) {}
    virtual inline void updateInputSensitivity(float value) {}
    virtual inline void updateSaveIndicator(bool hasSaveIndicator) {}
    virtual inline void onZoomChanged(float value) {}
    virtual inline void onRewindStatusChanged(bool rewindRunning, bool backward) {}
};

class ProjectController : CppUtils::DestructorQueue, public WorkspaceControllerDelegate {
    WorkspaceController* workspaceController = nullptr;
    ProjectControllerDelegate* delegate = nullptr;
    MvxPlayer* player;
    AudioInputManager* audioInputManager;
    bool lyricsVisible = true;
    CppUtils::Timer timer;

    void onStopPlaybackRequested();
    void updateSeek(double seek);

    void play();
    void stop();
public:
    explicit ProjectController(ProjectControllerDelegate* delegate);

    // Public interface
    void setWorkspaceController(WorkspaceController *workspaceController);

    const std::string& getArtistNameUtf8();
    const std::string& getSongTitleUtf8();

    void togglePlay();
    bool isPlaying() const;
    void toggleRewind(bool backward);

    bool isBoundsSelectionEnabled() const;
    void setBoundsSelectionEnabled(bool boundsSelectionEnabled);

    void setVocalVolume(float value);
    void setInputSensitivity(float value);
    void setVocalPianoVolume(float value);
    void setInstrumentalVolume(float value);

    void setLyricsVisible(bool value);
    void setMetronomeEnabled(bool value);
    void setTracksVisible(bool value);

    bool isLyricsVisible() const;
    bool isTracksVisible() const;
    bool isMetronomeEnabled() const;

    void setZoom(float zoom);
    float getZoom() const;
    float getMinZoom() const;
    float getMaxZoom() const;

    // Delegates
    void onPlaybackBoundsChangedByUserEvent(const PlaybackBounds &newBounds) override;
    void onSeekChangedByUserEvent(float newSeek) override;
};


#endif //TEXTIMAGESGENERATOR_PROJECTCONTROLLER_H
