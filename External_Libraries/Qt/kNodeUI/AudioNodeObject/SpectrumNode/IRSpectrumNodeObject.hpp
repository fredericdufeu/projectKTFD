//
//  IRSpectrumNodeObject.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/06/01.
//

#ifndef IRSpectrumNodeObject_hpp
#define IRSpectrumNodeObject_hpp

#include <stdio.h>
#include <iostream>
#include "IRFFT.hpp"
#include "IRUtilities.hpp"
#include "IRGraphDataStructure.hpp"
#include "kNodeUI.h"
#include "readSoundFileAtPath.h"

class IRSpectrumNodeObject : public kNodeObject
{
public:
    IRSpectrumNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output, QGraphicsScene *parentScene);
    ~IRSpectrumNodeObject();
    
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
    
    IRFFT *fft;
    
    IR::Frame frame2;

};

#endif /* IRSpectrumNodeObject_hpp */
