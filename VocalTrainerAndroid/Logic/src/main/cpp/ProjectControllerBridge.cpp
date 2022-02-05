//
// Created by Semyon Tikhonenko on 12/28/21.
//

#include "ProjectControllerBridge.h"
#include "Algorithms.h"
#include "ProjectController.h"
#include "StringEncodingUtils.h"

void ProjectControllerBridge::addDelegate(ProjectControllerBridgeDelegate delegate) {
    delegates.add(delegate);
}

void ProjectControllerBridge::removeDelegate(ProjectControllerBridgeDelegate delegate) {
    delegates.remove(delegate);
}

void ProjectControllerBridge::clearPlaybackBounds() {
    cpp->setPlaybackBounds(PlaybackBounds());
}

double ProjectControllerBridge::convertSeekToPlaybackProgress(double seek) {
    return cpp->convertSeekToPlaybackProgress(seek);
}

std::string ProjectControllerBridge::getArtistName() {
    return cpp->getArtistNameUtf8();
}

double ProjectControllerBridge::getBeatsPerMinute() {
    return cpp->getBeatsPerMinute();
}

double ProjectControllerBridge::getEndSeek() {
    return cpp->getEndSeek();
}

int32_t ProjectControllerBridge::getLinesCount() {
    return cpp->getLinesCount();
}

std::string ProjectControllerBridge::getLyricsLine(int32_t index) {
    auto lineU32 = cpp->getLyricsLine(index);
    return UtfUtils::ToUtf8(lineU32);
}

std::vector<Lyrics::Section> ProjectControllerBridge::getLyricsSections() {
    return cpp->getLyricsSections();
}

float ProjectControllerBridge::getMaxZoom() {
    return cpp->getMaxZoom();
}

float ProjectControllerBridge::getMinZoom() {
    return cpp->getMinZoom();
}

double ProjectControllerBridge::getOriginalBeatsPerMinute() {
    return cpp->getOriginalBeatsPerMinute();
}

Tonality ProjectControllerBridge::getOriginalTonality() {
    return cpp->getOriginalTonality();
}

std::vector<float> ProjectControllerBridge::getRecordingPreviewSamples(int32_t numberOfSamples) {
    return cpp->getRecordingPreview(numberOfSamples);
}

std::string ProjectControllerBridge::getSongTitle() {
    return cpp->getSongTitleUtf8();
}

float ProjectControllerBridge::getVerticalScrollPosition() {
    return cpp->getVerticalScrollPosition();
}

float ProjectControllerBridge::getZoom() {
    return cpp->getZoom();
}

bool ProjectControllerBridge::hasPlaybackBounds() {
    return cpp->hasPlaybackBounds();
}

bool ProjectControllerBridge::hasPlaybackSource() {
    return cpp->hasPlaybackSource();
}

bool ProjectControllerBridge::isMetronomeEnabled() {
    return cpp->isMetronomeEnabled();
}

bool ProjectControllerBridge::isPlaying() {
    return cpp->isPlaying();
}

bool ProjectControllerBridge::isRecording() {
    return cpp->isRecording();
}

void ProjectControllerBridge::setInstrumentalVolume(float value) {
    cpp->setInstrumentalVolume(value);
}

void ProjectControllerBridge::setPitchShift(int32_t shift) {
    cpp->setPitchShift(shift);
}

void ProjectControllerBridge::setPlaybackBounds(int32_t firstLineIndex, int32_t lastLineIndex) {
    cpp->setPlaybackBoundsUsingLineIndexes(firstLineIndex, lastLineIndex);
}

void ProjectControllerBridge::setPlaybackProgress(double progress) {
    cpp->setPlaybackProgress(progress);
}

void ProjectControllerBridge::setPlaybackSourceFilePath(const JString &filePath) {
    cpp->setPlaybackSource(filePath.getData());
}

void ProjectControllerBridge::setPlaybackSourcePtr(int64_t playbackSourcePtr) {
    cpp->setPlaybackSource(reinterpret_cast<VocalTrainerFile *>(playbackSourcePtr));
}

void ProjectControllerBridge::setTempoFactor(double factor) {
    cpp->setTempoFactor(factor);
}

void ProjectControllerBridge::setVocalPianoVolume(float value) {
    cpp->setVocalPianoVolume(value);
}

void ProjectControllerBridge::setVocalVolume(float value) {
    cpp->setVocalVolume(value);
}

void ProjectControllerBridge::setZoomIntoPoint(float zoom, const CppUtils::PointF& point) {
    cpp->setZoom(zoom, point);
}

void ProjectControllerBridge::stop() {
    cpp->stop();
}

void ProjectControllerBridge::toggleMetronomeEnabled() {
    cpp->setMetronomeEnabled(!cpp->isMetronomeEnabled());
}

void ProjectControllerBridge::togglePlay() {
    cpp->togglePlay();
}

ProjectControllerBridge::ProjectControllerBridge() {
    cpp = new ProjectController(&delegates);
}

ProjectControllerBridge::~ProjectControllerBridge() {
    delete cpp;
}
