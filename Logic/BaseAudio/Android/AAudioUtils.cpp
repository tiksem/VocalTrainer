//
// Created by Semyon Tikhonenko on 11/21/21.
//

#include "AAudioUtils.h"
#include "AudioOperationFailedException.h"

constexpr int BUFFER_CAPACITY_MULTIPLIER = 4;

namespace AAudioUtils {
    void CheckError(aaudio_result_t result) {
        if (result != AAUDIO_OK) {
            throw AudioOperationFailedException(AAudio_convertResultToText(result));
        }
    }
}