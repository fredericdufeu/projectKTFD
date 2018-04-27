//
//  kNodeObjectClass.cpp
//  kNodeObjectSystem
//
//  Created by Keitaro Takahashi on 2018/04/25.
//  Copyright © 2018 Keitaro Takahashi. All rights reserved.
//

#include "NodeObjectClass.hpp"


kNodeObject::kNodeObject(IR_Object::Type type, IR_Object::Name name, IR::Frame frame)
: kIRNodeBase(frame)
{
    this->frame = frame;
    this->objectType = type;
    this->objectName = name;
}

kNodeObject::~kNodeObject() {
    
}

void kNodeObject::createObj() {
    std::cout << "kNodeObject created!" << std::endl;
}


IR_Object::Type kNodeObject::getObjectType() {
    return this->objectType;
}

IR_Object::Name kNodeObject::getObjectName() {
    return this->objectName;
}


void kNodeObject::setFrameSize(IR::Frame frame)
{
    
}

IR::Frame kNodeObject::getFrame()
{
    return this->frame;
}

