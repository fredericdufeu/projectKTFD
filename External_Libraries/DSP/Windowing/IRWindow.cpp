//
//  IRWindow.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/06/01.
//

#include "IRWindow.hpp"

IRWindow::IRWindow()
{
    
}

IRWindow::~IRWindow()
{
    
}

float *IRWindow::none(unsigned int size)
{
    unsigned int i;
    float *buffer = new float [size];
    for(i=0;i<size;i++){
        buffer[i] = 0;
    }
    return buffer;
}

double *IRWindow::noneD(unsigned int size)
{
    unsigned int i;
    double *buffer = new double [size];
    for(i=0;i<size;i++){
        buffer[i] = 0;
    }
    return buffer;
}


float *IRWindow::hanning(unsigned int size)
{
    unsigned int i;
    float *buffer = new float [size];
    for(i=0;i<size;i++){
        buffer[i] = 0.5 - 0.5 * cosf(2 * M_PI * ((float)i/size));
    }
    return buffer;
}

double *IRWindow::hanningD(unsigned int size)
{
    unsigned int i;
    double *buffer = new double [size];
    for(i=0;i<size;i++){
        buffer[i] = 0.5 - 0.5 * cos(2 * M_PI * ((double)i/size));
    }
    return buffer;
}

float *IRWindow::hamming(unsigned int size)
{
    unsigned int i;
    float *buffer = new float [size];
    for(i=0;i<size;i++){
        buffer[i] = 0.54 - 0.46 * cosf(2 * M_PI * ((float)i/size));
    }
    return buffer;
}

double *IRWindow::hammingD(unsigned int size)
{
    unsigned int i;
    double *buffer = new double [size];
    for(i=0;i<size;i++){
        buffer[i] = 0.54 - 0.46 * cos(2 * M_PI * ((double)i/size));
    }
    return buffer;
}

float *IRWindow::blackman(unsigned int size)
{
    unsigned int i;
    float *buffer = new float [size];
    for(i=0;i<size;i++){
        float x = (float)i/size;
        buffer[i] = 0.42 - 0.5 * cosf(2.0 * M_PI * x) + 0.08 * cosf(4.0 * M_PI * x);
    }
    return buffer;
}

double *IRWindow::blackmanD(unsigned int size)
{
    unsigned int i;
    double *buffer = new double [size];
    for(i=0;i<size;i++){
        double x = (double)i/size;
        buffer[i] = 0.42 - 0.5 * cos(2.0 * M_PI * x) + 0.08 * cos(4.0 * M_PI * x);
    }
    return buffer;
}

