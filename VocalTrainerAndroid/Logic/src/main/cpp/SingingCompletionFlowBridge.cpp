#include "SingingCompletionFlowBridge.h"

void SingingCompletionFlowBridge::listen() {
    cpp->listen();
}

void SingingCompletionFlowBridge::save() {
    cpp->save();
}

void SingingCompletionFlowBridge::tryAgain() {
    cpp->tryAgain();
}

SingingCompletionFlowBridge::~SingingCompletionFlowBridge() {
    delete cpp;
}

SingingCompletionFlowBridge::SingingCompletionFlowBridge(SingingCompletionFlow *cpp) : cpp(cpp) {}
