//
//  NodeObjectClass.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/27.
//

#ifndef NodeObjectClass_hpp
#define NodeObjectClass_hpp

#include <stdio.h>
#include <iostream>

#include <QObject>
#include <QWidget>

#include "IRDataType.h"
#include "IRObjectName.h"
#include "kIRNodeBase.hpp"
#include "IRUtilities.hpp"
#include "kEditorWindow.hpp"


class kNodeObject : public kIRNodeBase
{
public:
    kNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output);
    ~kNodeObject();
    
    virtual void createObj();
    
    IR_Data::INOUTDATA getInputDataType();
    IR_Data::INOUTDATA getOutputDataType();

    IR_Object::Name getObjectName();
    
    void setFrameSize(IR::Frame frame) override;
    
    IR::Frame getFrame();
    
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    
private:
    
    IR_Data::INOUTDATA inputDataType;
    IR_Data::INOUTDATA outputDataType;
    IR_Object::Name objectName;
    
    IR::Frame frame;
};


#endif /* NodeObjectClass_hpp */
