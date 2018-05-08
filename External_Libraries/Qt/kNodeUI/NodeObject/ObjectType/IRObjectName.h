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
    
    enum Name
    {
        NONAME = -1,
        
        HOGE = 1,
        FORK = 2,
        TEST = 3,
    };
    
    using Id = std::string;
}

#endif /* IRObjectName_h */
