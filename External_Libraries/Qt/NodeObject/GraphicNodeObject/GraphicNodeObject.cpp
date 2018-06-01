//
//  GraphicNodeObject.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/25.
//

#include "GraphicNodeObject.hpp"

GraphicNodeObject::GraphicNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output, QGraphicsScene *parentScene)
: kNodeObject(name,frame,input,output,parentScene)
{
    
}

GraphicNodeObject::~GraphicNodeObject()
{
    
}

void GraphicNodeObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    kNodeObject::paint(painter,option,widget);
}