//
//  IRDataStructure.h
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/27.
//

#ifndef IRDataStructure_h
#define IRDataStructure_h

#include <iostream>
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
    };
    
    struct Point{
        float x;
        float y;
    };
    

}


#endif /* IRDataStructure_h */
