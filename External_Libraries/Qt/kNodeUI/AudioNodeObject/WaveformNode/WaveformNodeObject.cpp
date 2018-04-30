//
//  WaveformNodeObject.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/30.
//

#include "WaveformNodeObject.hpp"


WaveformNodeObject::WaveformNodeObject(IR_Object::Name name, IR::Frame frame, QWidget *parent)
: kNodeObject(IR_Object::Type::AUDIO, name,frame,parent)
{
    this->parent = parent;
    
}

WaveformNodeObject::~WaveformNodeObject()
{
    
}


