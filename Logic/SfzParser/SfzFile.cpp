//
// Created by Semyon Tykhonenko on 3/29/20.
// Copyright (c) 2020 Semyon Tikhonenko. All rights reserved.
//

#include "SfzFile.h"
#include "SfzSectionsParser.h"

using OptString = std::optional<std::string>;

SfzFile::SfzFile(const std::string &data) {
    SfzSectionsParser parser;
    std::vector<SfzSection> sections = parser.parse(data);

    bool isLowVelocity = false;

    for (auto& section : sections) {
        if (section.name == "region") {
            OptString sampleFilePath = section.attrs["sample"];
            OptString highKeyOpt = section.attrs["hikey"];
            OptString lowKeyOpt = section.attrs["lokey"];
            OptString keyCenterOpt = section.attrs["pitch_keycenter"];
            OptString keyOpt = section.attrs["key"];
            OptString loopStartOpt = section.attrs["loop_start"];
            OptString loopEndOpt = section.attrs["loop_end"];

            assert((keyCenterOpt || keyOpt) && "pitch_keycenter not present");
            assert(sampleFilePath && "sample not present");

            SfzRegion region;
            region.filePath = *sampleFilePath;
            auto key = *(keyCenterOpt ? keyCenterOpt : keyOpt);
            region.keyCenter = std::stoi(key);

            if (highKeyOpt) {
                region.highKey = std::stoi(*highKeyOpt);
            } else {
                region.highKey = region.keyCenter;
            }

            if (lowKeyOpt) {
                region.lowKey = std::stoi(*lowKeyOpt);
            } else {
                region.lowKey = region.keyCenter;
            }

            if (loopStartOpt) {
                assert(loopEndOpt && "loop_start is defined, so loop_end should be defined");
                region.loop = SfzLoop(std::stoi(*loopStartOpt), std::stoi(*loopEndOpt));
            }

            assert(region.lowKey <= region.highKey);

            region.isLowVelocity = isLowVelocity;
            regions.push_back(region);
        } else if (section.name == "group") {
        } else if (section.name == "global") {
            isLowVelocity = section.attrs.count("lovel") == 0;
        }
    }
}