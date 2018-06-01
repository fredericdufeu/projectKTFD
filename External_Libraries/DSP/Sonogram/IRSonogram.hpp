//
//  IRSonogram.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/31.
//

#ifndef IRSonogram_hpp
#define IRSonogram_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

#include "SoundFile.hpp"
#include "IRDataStructure.h"

class IRSonogram
{
public:
    IRSonogram();
    ~IRSonogram();
    
    void makeVertexBuffer(SoundFile *soundfile, float width, float height, float samplePerPixel);
    
    std::vector<IR::Vertex4D> getVertexBuffer() const;
    
private:
    std::vector<IR::Vertex4D> vertexBuffer;
    
    
};


#endif /* IRSonogram_hpp */
