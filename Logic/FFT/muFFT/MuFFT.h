//
// Created by Semyon Tikhonenko on 9/24/21.
//

#ifndef VOCALTRAINERANDROID_MUFFT_H
#define VOCALTRAINERANDROID_MUFFT_H

#include "../FFT.h"

class MuFFT : public FFT {
public:
    virtual void setup(int size);
    virtual void execute(std::vector<std::complex<float>> *inOutData, bool forward);
};


#endif //VOCALTRAINERANDROID_MUFFT_H
