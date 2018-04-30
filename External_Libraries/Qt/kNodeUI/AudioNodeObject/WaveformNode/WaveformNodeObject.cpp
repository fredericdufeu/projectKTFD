//
//  WaveformNodeObject.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/30.
//

#include "WaveformNodeObject.hpp"


WaveformNodeObject::WaveformNodeObject(IR_Object::Name name, IR::Frame frame)
: kNodeObject(IR_Object::Type::AUDIO, name,frame)
{
    
}

WaveformNodeObject::~WaveformNodeObject()
{
    
}


