//
//  GraphicNodeObject.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/25.
//

#ifndef GraphicNodeObject_hpp
#define GraphicNodeObject_hpp

#include <stdio.h>
#include <iostream>
#include "NodeObjectClass.hpp"

class GraphicNodeObject : public kNodeObject
{
public:
    GraphicNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output, QGraphicsScene *parentScene);
    ~GraphicNodeObject();
    
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    
};


#endif /* GraphicNodeObject_hpp */
