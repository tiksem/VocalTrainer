//
// Created by Semyon Tykhonenko on 2019-07-21.
//

#ifndef TEXTIMAGESGENERATOR_APPLICATIONMODEL_H
#define TEXTIMAGESGENERATOR_APPLICATIONMODEL_H

#include "VocalTrainerFilePlayer.h"
#include "AudioInputManager.h"

class ApplicationModel {
public:
#ifdef __APPLE__
    static void init();
#elif __ANDROID__
    static void init(
            const std::string& sfzPath, const std::string& metronomeDataFilePath);
#endif
    ApplicationModel(const std::string& sfzPath, const std::string& metronomeDataFilePath);
    static ApplicationModel* instance();
    VocalTrainerFilePlayer *createPlayer();
    AudioInputManager *createAudioInputManager();
};


#endif //TEXTIMAGESGENERATOR_APPLICATIONMODEL_H
