//
//  kNodeObjectClass.cpp
//  kNodeObjectSystem
//
//  Created by Keitaro Takahashi on 2018/04/25.
//  Copyright © 2018 Keitaro Takahashi. All rights reserved.
//

#include "NodeObjectClass.hpp"


kNodeObject::kNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output)
: kIRNodeBase(frame)
{
    this->frame = frame;
    this->objectName = name;
    
    this->inputDataType = input;
    this->outputDataType = output;
    
}

kNodeObject::~kNodeObject() {
    
}

void kNodeObject::createObj() {
    std::cout << "kNodeObject created!" << std::endl;
}


IR_Data::INOUTDATA kNodeObject::getInputDataType()
{
    return this->inputDataType;
}

IR_Data::INOUTDATA kNodeObject::getOutputDataType()
{
    return this->outputDataType;
}



IR_Object::Name kNodeObject::getObjectName() {
    return this->objectName;
}


void kNodeObject::setFrameSize(IR::Frame frame)
{
    // call superclass to set frame and update.
    kIRNodeBase::setFrameSize(frame);
}

IR::Frame kNodeObject::getFrame()
{
    return this->frame;
}

void kNodeObject::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "test" << std::endl;
    kIRNodeBase::mouseMoveEvent(event);
}

void kNodeObject::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    kIRNodeBase::mousePressEvent(event);
}

void kNodeObject::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    kIRNodeBase::mouseDoubleClickEvent(event);
}
void kNodeObject::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    kIRNodeBase::mouseReleaseEvent(event);
}


