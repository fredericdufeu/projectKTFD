//
//  IRWaveformNodeObject.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/10.
//

#include "IRWaveformNodeObject.hpp"



IRWaveformNodeObject::IRWaveformNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output)
: kNodeObject(name, frame, input, output)
{
    
    
    
}

IRWaveformNodeObject::~IRWaveformNodeObject()
{
    
}


void IRWaveformNodeObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    
    kNodeObject::paint(painter,option,widget);
}
