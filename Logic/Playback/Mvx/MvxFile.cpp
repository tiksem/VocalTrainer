//
// Created by Semyon Tikhonenko on 4/22/18.
// Copyright (c) 2018 Mac. All rights reserved.
//

#include "MvxFile.h"
#include <fstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <Decoder/audiodecoder.h>
#include "StringUtils.h"
#include "AudioUtils.h"

constexpr int MAX_SAMPLES_PREVIEW_COUNT = 5000;

using namespace CppUtils;

void MvxFile::writeToStream(std::ostream &os) {
    boost::archive::text_oarchive ar(os);
    ar << *this;
}

void MvxFile::writeToFile(const char *outFilePath) {
    std::fstream file = Streams::OpenFile(outFilePath, std::ios::binary | std::ios::out);
    writeToStream(file);
}

MvxFile MvxFile::readFromStream(std::istream &is, bool readOnlySignature) {
    MvxFile file;
    file.readOnlySignature = readOnlySignature;
    boost::archive::text_iarchive ar(is);
    ar >> file;
    return file;
}

MvxFile MvxFile::readFromFile(const char *filePath, bool readOnlySignature) {
    std::fstream file = Streams::OpenFile(filePath, std::ios::binary | std::ios::in);
    return readFromStream(file, readOnlySignature);
}

const VxFile &MvxFile::getVxFile() const {
    return vxFile;
}

VxFile &MvxFile::getVxFile() {
    return vxFile;
}

double MvxFile::getBeatsPerMinute() const {
    return beatsPerMinute;
}

void MvxFile::setBeatsPerMinute(double beatsPerMinute) {
    this->beatsPerMinute = beatsPerMinute;
}

void MvxFile::loadInstrumentalFromStream(std::istream &is) {
    instrumental = Strings::StreamToString(is);
}

void MvxFile::loadInstrumentalFromFile(const char *filePath) {
    std::fstream file = Streams::OpenFile(filePath, std::ios::binary | std::ios::in);
    loadInstrumentalFromStream(file);
}

const std::string &MvxFile::getInstrumental() const {
    return instrumental;
}

double MvxFile::getScore() const {
    return score;
}

void MvxFile::setScore(double score) {
    assert(score <= 100);
    MvxFile::score = score;
}

const std::string &MvxFile::getSongTitleUtf8() const {
    return songTitleUtf8;
}

void MvxFile::setSongTitleUtf8(const std::string &songTitleUtf8) {
    MvxFile::songTitleUtf8 = songTitleUtf8;
}

const std::string &MvxFile::getArtistNameUtf8() const {
    return artistNameUtf8;
}

void MvxFile::setArtistNameUtf8(const std::string &artistNameUtf8) {
    MvxFile::artistNameUtf8 = artistNameUtf8;
}

const std::string &MvxFile::getRecordingData() const {
    return recordingData;
}

void MvxFile::setInstrumental(const std::string &instrumental) {
    this->instrumental = instrumental;
}

std::string &MvxFile::moveInstrumental() {
    return instrumental;
}

bool MvxFile::isRecording() const {
    return recording;
}

void MvxFile::setRecordingData(const std::string &recordingData) {
    MvxFile::recordingData = recordingData;
    recording = !recordingData.empty();
}

void MvxFile::setVxFile(const VxFile &vxFile) {
    this->vxFile = vxFile;
}

std::vector<double> &MvxFile::moveRecordedPitchesTimes() {
    return recordedPitchesTimes;
}

void MvxFile::setRecordedPitchesTimes(const std::vector<double> &recordedPitchesTimes) {
    MvxFile::recordedPitchesTimes = recordedPitchesTimes;
}

std::vector<float> &MvxFile::moveRecordedPitchesFrequencies() {
    return recordedPitchesFrequencies;
}

void MvxFile::setRecordedPitchesFrequencies(const std::vector<float > &recordedPitchesFrequencies) {
    MvxFile::recordedPitchesFrequencies = recordedPitchesFrequencies;
}

std::string &MvxFile::moveRecordingData() {
    return recordingData;
}

const std::vector<short> &MvxFile::getInstrumentalPreviewSamples() const {
    return instrumentalPreviewSamples;
}

void MvxFile::setInstrumentalPreviewSamples(const std::vector<short> &instrumentalPreviewSamples) {
    this->instrumentalPreviewSamples = instrumentalPreviewSamples;
}

void MvxFile::generateInstrumentalPreviewSamplesFromInstrumental() {
    DecodedTrack decoded = AudioDecoder::decodeAllIntoRawPcm(instrumental);
    int previewSamplesCount = std::min(MAX_SAMPLES_PREVIEW_COUNT, int(decoded.rawPcm.size() / sizeof(short)));
    std::vector<short> previewSamples = AudioUtils::ResizePreviewSamples(decoded.rawPcm, previewSamplesCount);
    setInstrumentalPreviewSamples(previewSamples);
}

const Lyrics &MvxFile::getLyrics() const {
    return lyrics;
}
