//
//  IRObjectName.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/10.
//

#include "IRObjectName.h"

namespace IR_Object {


    
}

std::ostream& operator<<(std::ostream& lhs, const IR_Object::Name& rhs)
{
    const std::string st = rhs.getValue();
    lhs << st;
    return lhs;
    
    }
