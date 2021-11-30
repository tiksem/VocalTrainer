#include "FFT.h"
#ifdef __APPLE__
#include "AccelerateFFT.h"
#else
#include "muFFT/MuFFT.h"
#endif

FFT* FFT::create() {
#ifdef __APPLE__
    return new AccelerateFFT();
#else
    return new MuFFT();
#endif
}