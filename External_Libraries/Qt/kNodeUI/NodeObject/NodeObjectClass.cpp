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
    
    this->objectName = name;
    this->uniqueID = IRRandomStringsGenerator(IR::RANDOM_STRING_LEN);
    std::cout << "uniqueID = " << this->uniqueID << std::endl;
    this->frame = frame;
    
    this->inputDataType = input;
    this->outputDataType = output;
    
    std::cout << "\n" << std::endl;
    std::cout << "Node Object created!\n" << "\t name = " << this->objectName << "\n" << "\t uniqueID = " << this->uniqueID << std::endl;
    std::cout << "\t frame = origin (" << this->frame.origin.x << ", " << this->frame.origin.y << ") : size (" << this->frame.size.width << ", " << this->frame.size.height << ")" << std::endl;
    std::cout << "\n" << std::endl;

}

kNodeObject::~kNodeObject() {
    
}

void kNodeObject::createObj() {
    std::cout << "kNodeObject created!" << std::endl;
}

void kNodeObject::deleteObj() {
    std::cout << "kNodeObject deleted!" << std::endl;

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
    return getFrameSize();
}

IR_Object::Id kNodeObject::getUniqueId()
{
    return this->uniqueID;
}
/*
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
}*/

std::string kNodeObject::IRRandomStringsGenerator(const int len)
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

void kNodeObject::objSelectionChanged()
{
    std::cout << this->uniqueID << " selected." << std::endl;
    emit objSelectionChangedSignal(this->uniqueID);
}

void kNodeObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    
    kIRNodeBase::paint(painter,option,widget);
    
}


