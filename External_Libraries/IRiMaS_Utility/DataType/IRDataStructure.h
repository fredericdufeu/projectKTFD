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
        
        bool isFrameInside(Frame frame) {
            return false;
        }
        
        bool isFrameOverlap(Frame frame){
            
            float width = size.width + frame.size.width; //size.width >= frame.size.width ? size.width : frame.size.width;
            float height = size.height + frame.size.height; //size.height >= frame.size.height ? size.height : frame.size.height;
            
            
            float dis_x = fabs(origin.x - frame.origin.x);
            float dis_y = fabs(origin.y - frame.origin.y);
        
            std::cout << "\n";
            std::cout << "dis_x = " << dis_x << " dis_y = " << dis_y << " : " << "width = " << width << " height = " << height << "\n";

            if(dis_x <= width/2 && dis_y <= height/2){
                std::cout << "true\n";
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
