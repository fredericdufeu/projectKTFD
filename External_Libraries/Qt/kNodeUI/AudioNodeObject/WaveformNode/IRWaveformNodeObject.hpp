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
#include "readSoundFileAtPath.h"
#include "SoundFile.hpp"
#include "IRUtilities.hpp"

class IRWaveformNodeObject : public kNodeObject
{
public:
    IRWaveformNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output, QGraphicsScene *parentScene);
    ~IRWaveformNodeObject();
    
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
    
    
};
#endif /* IRWaveformNodeObject_hpp */
