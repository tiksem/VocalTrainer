//
// Created by Semyon Tikhonenko on 10/6/18.
//

#include "TextImagesFactory.h"
#include "WorkspaceDrawer.h"
#include "PianoDrawer.h"
#include <QString>
#include <QImage>
#include <iostream>

constexpr int MAX_SUPPORTED_DEVICE_PIXEL_RATIO = 2;
constexpr const char* path = ":qml/images/text/";

using std::cerr;

void TextImagesFactory::addImage(Drawer* drawer, int devicePixelRatio, int fontSize, char character) {
    QString fileName = path + QString::number(fontSize * devicePixelRatio) + "_" + QString(character) + ".png";
    QImage image(fileName);
    assert(!image.isNull());

    Drawer::Image* imageHolder = drawer->createImage(image.bits(), image.width(), image.height());

    DrawerTextImagesFactoryCharacterData data;
    data.image = imageHolder;
    data.character = character;
    data.fontSize = fontSize;
    DrawerTextImagesFactory::addImage(data);
}

void TextImagesFactory::load(Drawer* drawer, int devicePixelRatio) {
    if (devicePixelRatio < 1) {
        devicePixelRatio = 1;
        cerr<<"Strange device pixel ratio passed "<<devicePixelRatio;
    } else if(devicePixelRatio > MAX_SUPPORTED_DEVICE_PIXEL_RATIO) {
        devicePixelRatio = MAX_SUPPORTED_DEVICE_PIXEL_RATIO;
        cerr<<"Unsupported device pixel ratio passed "<<devicePixelRatio;
    }

    // digits
    for (int textInt = 0; textInt <= 9; ++textInt) {
        char ch = (char)textInt + '0';
        addImage(drawer, devicePixelRatio, WorkspaceDrawer::YARD_STICK_FONT_SIZE, ch);
        addImage(drawer, devicePixelRatio, PianoDrawer::FONT_SIZE, ch);
    }

    // pitch names
    for (char ch = 'A'; ch <= 'G'; ch++) {
        addImage(drawer, devicePixelRatio, PianoDrawer::FONT_SIZE, ch);
    }
}