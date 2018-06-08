//
//  IRFFT.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/06/01.
//

#include "IRFFT.hpp"

IRFFT::IRFFT(unsigned int fftsize, IR_FFT::DIRECTION sign, IR_FFT::MODE flags, IR_FFT::WINDOW windowType)
{
    this->fftsize = fftsize;
    this->ffthalfsize = this->fftsize/2;
    this->windowType = windowType;
    
    createWindow();
    
    this->in = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * this->fftsize);
    this->out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * this->fftsize);
        
    this->plan = fftw_plan_dft_1d(this->fftsize, this->in, this->out, sign, flags);
}
IRFFT::~IRFFT()
{
    fftw_destroy_plan(this->plan);
    fftw_free(this->in);
    fftw_free(this->out);
    free(this->window);
    free(this->amplitude);
    free(this->phase);
}

void IRFFT::setInput(float *data, bool windowFlag)
{
    
    if(windowFlag){
        for(unsigned int i=0;i<this->fftsize;i++) {
            this->in[i][0] = data[i] * this->window[i];
            this->in[i][1] = 0.0;
        }
    }else{
        for(unsigned int i=0;i<this->fftsize;i++) {
            this->in[i][0] = data[i];
            this->in[i][1] = 0.0;
        }
    }
}

fftw_complex* IRFFT::getOutput()
{
    return this->out;
}

IR_FFT::WINDOW IRFFT::getWindowType()
{
    return this->windowType;
}

unsigned int IRFFT::getFFTSize()
{
    return this->fftsize;
}
unsigned int IRFFT::getFFTHalfSize()
{
    return this->ffthalfsize;
}

void IRFFT::FFT()
{
    fftw_execute(this->plan);
}

void IRFFT::createWindow()
{
    IRWindow Win = IRWindow();
    
    switch (this->windowType) {
        case IR_FFT::WINDOW::NONE:
            this->window = Win.noneD(this->fftsize);
            break;
        case IR_FFT::WINDOW::HANNING:
            this->window = Win.hanningD(this->fftsize);
            break;
        case IR_FFT::WINDOW::HAMMING:
            this->window = Win.hammingD(this->fftsize);
            break;
        case IR_FFT::BLACKMAN:
            this->window = Win.blackmanD(this->fftsize);
            break;
        default:
            break;
    }

}

void IRFFT::cartopol()
{
    this->amplitude = getAmplitude();
    this->phase = getPhase();
    
    for(unsigned int i = 0; i<this->ffthalfsize; i++) {
        printf("amplitude[%d] = %lf\n",i,this->amplitude[i]);
    }
}

double* IRFFT::getAmplitude()
{
    double *buffer = new double [this->ffthalfsize];
    for(unsigned int i=0;i<this->ffthalfsize;i++){
        buffer[i] = sqrt(this->out[i][0] * this->out[i][0] + this->out[i][1] * this->out[i][1]);
    }
    return buffer;
}

double *IRFFT::getPhase()
{
    double *buffer = new double [this->ffthalfsize];
    for(unsigned int i=0;i<this->ffthalfsize;i++){
        buffer[i] = atan2(this->out[i][1], this->out[i][0]);
    }
    return buffer;
}
