//
//  IRFFT.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/06/01.
//

#ifndef IRFFT_hpp
#define IRFFT_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>
#include "fftw3.h"
#include "IRWindow.hpp"

namespace IR_FFT {

    
    enum DIRECTION {
        FORWARD          = FFTW_FORWARD,
        BACKWARD         = FFTW_BACKWARD,
    };
    
    enum MODE {
        MEASURE          = FFTW_MEASURE,
        ESTIMATE         = FFTW_ESTIMATE,
    };
    
    struct complexFFTW {
        fftw_complex *data;
    };
    
}

class IRFFT {
    
public:
    IRFFT(unsigned int fftsize, IR_FFT::DIRECTION sign, IR_FFT::MODE flags, IR_FFT::WINDOW windowType);
    ~IRFFT();
    
    void setInput(float *data, bool windowFlag);
    fftw_complex *getOutput();
    IR_FFT::WINDOW getWindowType();
    unsigned int getFFTSize();
    unsigned int getFFTHalfSize();
    
    void cartopol();
    
    double *getAmplitude();
    double *getPhase();
    
    void FFT();    
    
    double *amplitude;
    double *phase;
    
private:

    fftw_complex *in;
    fftw_complex *out;

    unsigned int numFrame;
    
    unsigned int fftsize;
    unsigned int ffthalfsize;
    
    fftw_plan plan;
    
    IR_FFT::WINDOW windowType;
    double *window;
    
    void createWindow();
    
};

#endif /* IRFFT_hpp */
