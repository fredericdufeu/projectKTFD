//
//  IRWaveformNodeObject.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/10.
//

#include "IRWaveformNodeObject.hpp"



IRWaveformNodeObject::IRWaveformNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output, QGraphicsScene *parentScene)
: kNodeObject(name, frame, input, output, parentScene)
{
    
    main();
    
}

IRWaveformNodeObject::~IRWaveformNodeObject()
{
    
}

void IRWaveformNodeObject::main()
{
    std::cout << "main() in IRWaveformNodeObject called!\n";
    
}



void IRWaveformNodeObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    
    kNodeObject::paint(painter,option,widget);
}
