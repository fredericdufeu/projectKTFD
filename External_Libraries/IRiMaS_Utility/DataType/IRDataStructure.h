//
//  IRDataStructure.h
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/27.
//

#ifndef IRDataStructure_h
#define IRDataStructure_h

#include <iostream>
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
    

}


#endif /* IRDataStructure_h */
