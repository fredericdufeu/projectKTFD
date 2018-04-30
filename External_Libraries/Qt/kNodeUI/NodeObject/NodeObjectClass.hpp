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
    kNodeObject(IR_Object::Type type, IR_Object::Name name, IR::Frame frame);
    ~kNodeObject();
    
    virtual void createObj();
    
    IR_Object::Type getObjectType();
    IR_Object::Name getObjectName();
    
    void setFrameSize(IR::Frame frame) override;
    
    IR::Frame getFrame();
    
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    
private:
    IR_Object::Type objectType;
    IR_Object::Name objectName;
    
    IR::Frame frame;
};


#endif /* NodeObjectClass_hpp */
