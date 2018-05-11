//
//  IRWaveformNodeObject.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/10.
//

#ifndef IRWaveformNodeObject_hpp
#define IRWaveformNodeObject_hpp

#include <stdio.h>
#include "kNodeUI.h"
#include "IRUtilities.hpp"

class IRWaveformNodeObject : public kNodeObject
{
public:
    IRWaveformNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output, QGraphicsScene *parentScene);
    ~IRWaveformNodeObject();
    
    // main execute function called by CTRL + R by Scene
    void main() override;
    
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};
#endif /* IRWaveformNodeObject_hpp */
