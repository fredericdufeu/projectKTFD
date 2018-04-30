//
//  IRObjectName.h
//  NodeObjectSystem2
//
//  Created by Keitaro Takahashi on 2018/04/25.
//  Copyright © 2018 Keitaro Takahashi. All rights reserved.
//

#ifndef IRObjectName_h
#define IRObjectName_h

namespace IR_Object {
    
    enum Type
    {
        NOTYPE = -1,
        
        AUDIO = 1,
        IMAGE = 2,
        MOVIE = 3,
        SCORE = 4,
    };

    enum Name
    {
        NONAME = -1,
        
        HOGE = 1,
        FORK = 2,
        TEST = 3,
        
        
    };
}

#endif /* IRObjectName_h */
