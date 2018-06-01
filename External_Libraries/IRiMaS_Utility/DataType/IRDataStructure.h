//
//  IRDataStructure.h
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/27.
//

#ifndef IRDataStructure_h
#define IRDataStructure_h

#include <iostream>
#include <vector>
#include "math.h"

//#include "WorkSpace.hpp"


namespace IR {
    
    struct Origin{
        float x;
        float y;
    };
    
    struct Size{
        float width;
        float height;
    };
    
    struct Frame{
        Origin origin;
        Size size;

        
        // check if the given frame overlaps to this frame.
        bool isFrameOverlap(Frame frame){
            
            float width = size.width + frame.size.width;
            float height = size.height + frame.size.height;
            
            float dis_x = fabs(origin.x - frame.origin.x);
            float dis_y = fabs(origin.y - frame.origin.y);
        
            if(dis_x <= width/2 && dis_y <= height/2){
                    return true;
            }
            return false;
        }
        
        void show(){
            std::cout << " origin  " << origin.x << ", " << origin.y << " : size " << size.width << ", " << size.height << std::endl;
        }
        
    };
    
    struct Point{
        float x;
        float y;
    };
    
    
    /* vector data structure */
    
    struct vector_float2{
        float x = 0.0;
        float y = 0.0;
    };
    
    struct vector_float4{
        int r = 0.0;
        int g = 0.0;
        int b = 0.0;
        int a = 0.0;
    };
    
    struct Vertex4D{
        
        vector_float2 pos1;
        vector_float2 pos2;
        vector_float2 pos3;
        vector_float2 pos4;
        
        vector_float4 color1;
        vector_float4 color2;
        vector_float4 color3;
        vector_float4 color4;
    };
    

}


#endif /* IRDataStructure_h */
