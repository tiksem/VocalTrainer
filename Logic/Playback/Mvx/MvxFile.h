//
// Created by Semyon Tikhonenko on 4/22/18.
// Copyright (c) 2018 Mac. All rights reserved.
//

#ifndef VOCALTRAINER_MVXFILE_H
#define VOCALTRAINER_MVXFILE_H

#include <iostream>
#include "VxFile.h"

class MvxFile {
    VxFile vxFile;
    std::string instrumental;
    double beatsPerMinute;
    std::string songTitleUtf8;
    std::string artistNameUtf8;
    double score = -1.0;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & beatsPerMinute;
        ar & vxFile;
        ar & instrumental;
    }

public:

    MvxFile();
    MvxFile(VxFile &&vxFile, std::string &&instrumental, double beatsPerMinute);
    MvxFile(const VxFile &vxFile, std::istream& instrumentalStream, double beatsPerMinute);
    MvxFile(const VxFile &vxFile, const char* instrumentalFile, double beatsPerMinute);

    MvxFile(MvxFile&& mvxFile) = default;
    // Preferably use move constructor instead
    MvxFile(const MvxFile& mvxFile) = delete;

    void writeToStream(std::ostream& os);
    void writeToFile(const char* outFilePath);

    static MvxFile readFromStream(std::istream& is);
    static MvxFile readFromFile(const char* outFilePath);

    const VxFile &getVxFile() const;
    VxFile &getVxFile();

    const std::string &getInstrumental() const;
    std::string &getInstrumental();

    double getBeatsPerMinute() const;
    void setBeatsPerMinute(double beatsPerMinute);

    double getScore() const;
    void setScore(double score);

    const std::string &getSongTitleUtf8() const;
    void setSongTitleUtf8(const std::string &songTitleUtf8);

    const std::string &getArtistNameUtf8() const;
    void setArtistNameUtf8(const std::string &artistNameUtf8);

    void loadInstrumentalFromStream(std::istream& is);
    void loadInstrumentalFromFile(const char* filePath);
};


#endif //VOCALTRAINER_MVXFILE_H
