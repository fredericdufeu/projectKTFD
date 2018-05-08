//
//  randomStringGenerator.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/08.
//

#ifndef randomStringGenerator_hpp
#define randomStringGenerator_hpp

#include <stdio.h>
#include <iostream>

namespace IR {
    
    std::string IRRandomStringsGenerator(const int len)
    {
        std::string s = "";
        
        char alphanum[] = "0123456789"
                                 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                 "abcdefghijklmnopqrstuvwxyz";
        for (int i=0;i<len;i++){
            s += alphanum[rand()%(sizeof(alphanum) - 1)];
        }
        return s;
    }
    

    
}

#endif /* randomStringGenerator_hpp */
