#import "ApplicationModel.h"
#include "StringUtils.h"

using namespace CppUtils;

static std::string getSfzFilePath() const {
    NSString *sfzPath = [[NSBundle bundleWithIdentifier:@"Logic"] pathForResource:@"piano" ofType:@"sfz"];
    return std::string(sfzPath.UTF8String);
}

static std::string getMetronomeDataFilePath() const {
    NSString *result = [NSBundle.mainBundle pathForResource:@"metronome" ofType:@"wav"];
    if (!result) {
        return "";
    }

    return std::string(result.UTF8String);
}

ApplicationModel::ApplicationModel() :
        ApplicationModel(getSfzFilePath(), getMetronomeDataFilePath()) {
}

void ApplicationModel::init() {
    model = new ApplicationModel();
}