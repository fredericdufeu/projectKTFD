//
//  IRSonogramNodeObject.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/10.
//

#ifndef IRSonogramNodeObject_hpp
#define IRSonogramNodeObject_hpp

#include <stdio.h>
#include "kNodeUI.h"
#include "IRUtilities.hpp"

class IRSonogramNodeObject : public kNodeObject
{
public:
    IRSonogramNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output, QGraphicsScene *parentScene);
    ~IRSonogramNodeObject();
    
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};


#endif /* IRSonogramNodeObject_hpp */
