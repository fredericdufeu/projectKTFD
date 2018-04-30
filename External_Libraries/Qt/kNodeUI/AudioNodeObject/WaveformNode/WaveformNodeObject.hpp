//
//  WaveformNodeObject.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/30.
//

#ifndef WaveformNodeObject_hpp
#define WaveformNodeObject_hpp

#include <stdio.h>

#include <QWidget>
#include "NodeObjectClass.hpp"

class WaveformNodeObject : public kNodeObject
{
public:
    WaveformNodeObject(IR_Object::Name name, IR::Frame frame);
    ~WaveformNodeObject();
    
private:
    
};

#endif /* WaveformNodeObject_hpp */
