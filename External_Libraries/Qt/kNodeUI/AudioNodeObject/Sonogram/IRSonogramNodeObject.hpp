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
#include "SoundFile.hpp"
#include "readSoundFileAtPath.h"
#include "IRUtilities.hpp"

class IRSonogramNodeObject : public kNodeObject
{
public:
    IRSonogramNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output, QGraphicsScene *parentScene);
    ~IRSonogramNodeObject();
    
    // main execute function called by CTRL + R by Scene
    void main() override;
    
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    
private:
    std::string url;
    SoundFile *soundfile;
    IR::Frame frame;
    IR_Object::Name name;

};


#endif /* IRSonogramNodeObject_hpp */
