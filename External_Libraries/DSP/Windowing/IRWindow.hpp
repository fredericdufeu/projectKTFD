//
//  IRWindow.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/06/01.
//

#ifndef IRWindow_hpp
#define IRWindow_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>

namespace IR_FFT {
    
    enum WINDOW{
        NONE           = 0,
        HANNING        = 1,
        HAMMING        = 2,
        BLACKMAN       = 3,
    };
}

class IRWindow{
public:
    IRWindow();
    ~IRWindow();
    
    float *none(unsigned int size);
    double *noneD(unsigned int size);
    
    float *hanning(unsigned int size);
    double *hanningD(unsigned int size);
    
    float *hamming(unsigned int size);
    double *hammingD(unsigned int size);
    
    float *blackman(unsigned int size);
    double *blackmanD(unsigned int size);

    
    
private:
    float *windowf;
    double *windowd;
};

#endif /* IRWindow_hpp */
