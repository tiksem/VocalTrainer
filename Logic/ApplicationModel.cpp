//
// Created by Semyon Tykhonenko on 2019-07-21.
//

#include "ApplicationModel.h"
#include "SfzPitchRenderer.h"
#include "StringUtils.h"
#include "TimeUtils.h"
#include <iostream>

using namespace CppUtils;
using std::cout;

static ApplicationModel* model = nullptr;

ApplicationModel::ApplicationModel(const std::string &sfzPath,
                                   const std::string &metronomeDataFilePath) {
    SfzPitchRenderer::initSfz(sfzPath);
    if (!metronomeDataFilePath.empty()) {
        std::string metronomeData = Strings::ReadBinaryFileContent(metronomeDataFilePath.data());
        MetronomeAudioPlayer::setMetronomeAudioData(std::move(metronomeData));
    }
}

VocalTrainerFilePlayer *ApplicationModel::createPlayer() {
    return new VocalTrainerFilePlayer();
}

AudioInputManager *ApplicationModel::createAudioInputManager() {
    return new AudioInputManager();
}

void ApplicationModel::init(
        const std::string& sfzPath, const std::string& metronomeDataFilePath) {
    model = new ApplicationModel(sfzPath, metronomeDataFilePath);
}

ApplicationModel *ApplicationModel::instance() {
    return model;
}
