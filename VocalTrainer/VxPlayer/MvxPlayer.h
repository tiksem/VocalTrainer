//
// Created by Semyon Tikhonenko on 1/15/18.
// Copyright (c) 2018 Mac. All rights reserved.
//

#ifndef VOCALTRAINER_MVXPLAYER_H
#define VOCALTRAINER_MVXPLAYER_H

#include <iostream>
#include "VxFile.h"

class MvxPlayer {
    VxFile vxFile;
    std::string audioData;
    AudioPlayer player;
public:
    MvxPlayer();
    void load(std::istream& audioFile, std::istream& vxFile);
    void play();
    void pause();
    void resume();
    void seek(double value);
};


#endif //VOCALTRAINER_MVXPLAYER_H