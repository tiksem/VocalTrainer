//
// Created by Semyon Tikhonenko on 8/10/16.
// Copyright (c) 2016 Mac. All rights reserved.
//

#import "PitchGraphView.h"
#include <GLKit/GLKit.h>
#import "GLSceneDrawer.h"
#import "TsfTest.h"

@implementation PitchGraphView {
    GLSceneDrawer* _glSceneDrawer;
    AVAudioPlayer *_player;
}

- (void)prepareOpenGL {
    [_window makeFirstResponder:self];
    glClearColor(0, 0, 0, 0);

    [NSTimer scheduledTimerWithTimeInterval:1.0/60.0
                                     target:self
                                   selector:@selector(onTimer:)
                                   userInfo:nil
                                    repeats:YES];
    _player = testTsf();
}

- (id)initWithCoder:(NSCoder *)coder {
    self = [super initWithCoder:coder];
    if (self) {
        _glSceneDrawer = new GLSceneDrawer();
        _glSceneDrawer->setMoveBetweenOctaves(true);
    }

    return self;
}

- (void)onTimer:(id)onTimer {
    [self display];
}

- (void)drawRect:(NSRect)dirtyRect {
    _glSceneDrawer->draw(dirtyRect.size.width, dirtyRect.size.height);
}

- (void)onWavFileSelected:(NSString *)path {
    _glSceneDrawer->readPitchesFromWav(path.UTF8String);
}

- (void)moveBetweenOctavesFlagDidChange:(BOOL)value {
    _glSceneDrawer->setMoveBetweenOctaves(value);
}


- (void)dealloc {
    delete _glSceneDrawer;
}


@end