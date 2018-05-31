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
#include "NodeProxyWidget.hpp"

//#include "kEditorWindow.hpp"



class kNodeObject : public kIRNodeBase
{
    Q_OBJECT
    
public:
    kNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output, QGraphicsScene *parentScene);
    ~kNodeObject();
    
    virtual void createObj();
    virtual void deleteObj();
    

    
    
    IR_Data::INOUTDATA getInputDataType();
    IR_Data::INOUTDATA getOutputDataType();

    IR_Object::Name getObjectName();
    
 
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    
    IR::Frame getFrame();
    IR_Object::Id getUniqueId();
   
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
     /*
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    */
    void objSelectionChanged() override;

    // label
    void setDisplayLabel(bool flag);
    bool isDisplayLabel();


signals:
    void deleteObjSignal();
    
    void objSelectionChangedSignal(std::string);
    
public slots:
    //# main() method for overrided by its child class.
    //# this method is automatically called when the Node object is executed.
    virtual void main();
    
private:
    
    IR_Data::INOUTDATA inputDataType;
    IR_Data::INOUTDATA outputDataType;
    IR_Object::Name objectName;
    
    /* unique ID identifying this object in a workspace. */
    std::string uniqueID;
    
    IR::Frame frame;
    
    bool DisplayLabel = true;
    
    NodeProxyWidget *InnerWidget;

    
    /* generate ID */
    std::string IRRandomStringsGenerator(const int len);
};


#endif /* NodeObjectClass_hpp */
