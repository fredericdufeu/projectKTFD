//
//  TriangleNodeObject.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/25.
//

#ifndef TriangleNodeObject_hpp
#define TriangleNodeObject_hpp

#include <stdio.h>
#include <iostream>
#include "GraphicNodeObject.hpp"

class TriangleNodeObject : public GraphicNodeObject
{
public:
    TriangleNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output, QGraphicsScene *parentScene);
    ~TriangleNodeObject();
    
    
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};

#endif /* TriangleNodeObject_hpp */
