//
//  NodeObjectProducer.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/11.
//

#ifndef NodeObjectProducer_hpp
#define NodeObjectProducer_hpp

#include <stdio.h>
#include <iostream>

#include "IRDataType.h"
#include "IRObjectName.h"
#include "kIRNodeBase.hpp"
#include "IRUtilities.hpp"

class NodeObjectProducer
{
public:
    NodeObjectProducer();
    ~NodeObjectProducer();
    
    bool produceObjFromDropFile(IR_FILE::FILEIDENTITY fileIdentity);
    
private:    
    bool NodeObjectAssigner(IR_FILE::FILEIDENTITY fileIdentity);
    
    
    
};

#endif /* NodeObjectProducer_hpp */
