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


