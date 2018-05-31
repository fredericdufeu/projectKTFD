//
//  TriangleNodeObject.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/25.
//

#include "TriangleNodeObject.hpp"


TriangleNodeObject::TriangleNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output, QGraphicsScene *parentScene)
: GraphicNodeObject(name, frame, input, output, parentScene)
{
    
}

TriangleNodeObject::~TriangleNodeObject()
{
    
}


void TriangleNodeObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    GraphicNodeObject::paint(painter,option,widget);
}
