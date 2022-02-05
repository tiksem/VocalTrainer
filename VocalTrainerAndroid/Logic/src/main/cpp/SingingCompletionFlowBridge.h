//
// Created by Semyon Tikhonenko on 11/29/21.
//

#ifndef JNIBRIDGEGENERATOR_SingingCompletionFlowBridge_H
#define JNIBRIDGEGENERATOR_SingingCompletionFlowBridge_H

#include "JArray.h"
#include "JString.h"
#include "SingingCompletionFlow.h"
#include <string>
// headers

// headers

class SingingCompletionFlowBridge {
    SingingCompletionFlow* cpp;
public:
    SingingCompletionFlowBridge(SingingCompletionFlow *cpp);

    // Public Jni Interface
        void listen();
        void save();
        void tryAgain();
    // Public Jni Interface
    ~SingingCompletionFlowBridge();
};


#endif //JNIBRIDGEGENERATOR_SingingCompletionFlowBridge_H
