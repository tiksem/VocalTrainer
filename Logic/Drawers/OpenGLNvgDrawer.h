//
// Created by Semyon Tikhonenko on 10/25/18.
//

#ifndef VOCALTRAINER_OPENGLNVGDRAWER_H
#define VOCALTRAINER_OPENGLNVGDRAWER_H

#include "NvgDrawer.h"

class OpenGLNvgDrawer : public NvgDrawer {
public:
    OpenGLNvgDrawer();
    ~OpenGLNvgDrawer() override;
    void clear() override;
};


#endif //VOCALTRAINER_OPENGLNVGDRAWER_H
