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

#include <QtWidgets>

#include "IRDataType.h"
#include "IRObjectName.h"
#include "kIRNodeBase.hpp"
#include "IRUtilities.hpp"
#include "kEditorWindow.hpp"

class kNodeObject : public kIRNodeBase
{
    Q_OBJECT
    
public:
    kNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output);
    ~kNodeObject();
    
    virtual void createObj();
    virtual void deleteObj();
    
    IR_Data::INOUTDATA getInputDataType();
    IR_Data::INOUTDATA getOutputDataType();

    IR_Object::Name getObjectName();
    
    void setFrameSize(IR::Frame frame) override;
    
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    
    IR::Frame getFrame();
    IR_Object::Id getUniqueId();
    /*
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    */
    void objSelectionChanged() override;

signals:
    void deleteObjSignal();
    
    void objSelectionChangedSignal(std::string);
    
private:
    
    IR_Data::INOUTDATA inputDataType;
    IR_Data::INOUTDATA outputDataType;
    IR_Object::Name objectName;
    
    /* unique ID identifying this object in a workspace. */
    std::string uniqueID;
    
    IR::Frame frame;
    
    /* generate ID */
    std::string IRRandomStringsGenerator(const int len);
};


#endif /* NodeObjectClass_hpp */
