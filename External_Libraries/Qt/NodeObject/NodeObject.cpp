//
//  NodeObject.cpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 24/04/2018.
//

#include "NodeObject.hpp"


NodeObject::NodeObject()
{
    
}


NodeObject::NodeObject(const std::string path)
{
    originalFilePath = path;
}


NodeObject::~NodeObject()
{
    
}


std::string NodeObject::getOriginalFilePath() const
{
    return originalFilePath;
}
