//
// Created by Semyon Tikhonenko on 12/19/21.
//

#ifndef JNIBRIDGEGENERATOR_AndroidApplicationModelFunctions_H
#define JNIBRIDGEGENERATOR_AndroidApplicationModelFunctions_H

#include <jni.h>
#include <string>
#include <vector>
#include "JString.h"
// headers

// headers

namespace AndroidApplicationModelFunctions {
    void nativeInit(const JString& sfzPath, const JString& metronomeDataPath);
}

#endif //JNIBRIDGEGENERATOR_AndroidApplicationModelFunctions_H
