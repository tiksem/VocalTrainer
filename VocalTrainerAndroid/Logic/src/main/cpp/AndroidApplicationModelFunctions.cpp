#include "AndroidApplicationModelFunctions.h"
#include "ApplicationModel.h"

namespace AndroidApplicationModelFunctions {
    void nativeInit(const JString& sfzPath, const JString& metronomeDataPath) {
        ApplicationModel::init(sfzPath.getData(), metronomeDataPath.getData());
    }
}