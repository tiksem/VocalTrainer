//
// Created by Semyon Tikhonenko on 2/27/21.
// Copyright (c) 2021 Semyon Tikhonenko. All rights reserved.
//

#ifndef VOCALTRAINER_LYRICSPLAYER_H
#define VOCALTRAINER_LYRICSPLAYER_H

#include "Lyrics.h"
#include "LyricsDisplayedLinesProvider.h"
#include <vector>
#include <functional>

class LyricsPlayer : public LyricsDisplayedLinesProvider {
    const Lyrics* lyrics;
    double seek = 0;
    int simultaneouslyLinesDisplayCount;
    int currentFirstLineIndex = 0;
    Lyrics::LineSelection selection;

    void updateLines();
    void updateSelection();
public:
    std::function<void(const LyricsDisplayedLinesProvider*)> onLinesChanged;
    std::function<void(const Lyrics::LineSelection&)> onSelectionChanged;

    LyricsPlayer(const Lyrics *lyrics, int simultaneouslyLinesDisplayCount = 2);

    double getSeek() const;
    void setSeek(double seek);

    int getDisplayLinesCount() const override;
    std::u32string_view getDisplayedLineAt(int index) const override;
};


#endif //VOCALTRAINER_LYRICSPLAYER_H
