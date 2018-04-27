//
//  IRFileUtility.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/27.
//

#ifndef IRFileUtility_hpp
#define IRFileUtility_hpp

#include <stdio.h>
#include <iostream>
#include "IRFileTypeEnum.hpp"

class IRFileUtility
{
public:
    IRFileUtility();
    ~IRFileUtility();
    
    IR_FILE::TYPE checkFileType(std::string& filename);
    std::string getFileExtension(const std::string& s);
    
    std::map<std::string, IR_FILE::TYPE>IR_FILE_TYPE_EXT;
    
};

#endif /* IRFileUtility_hpp */
