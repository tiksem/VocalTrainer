//
// Created by Semyon Tikhonenko on 7/2/18.
// Copyright (c) 2018 Mac. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import <MetalKit/MetalKit.h>
#include "MetalViewCallback.h"

@interface MetalView : NSView
- (instancetype)initWithFrame:(CGRect)frameRect callback:(MetalViewCallback*)callback;
- (void)resize:(CGSize)size;
- (void)render;
- (CAMetalLayer*)metalLayer;
@end