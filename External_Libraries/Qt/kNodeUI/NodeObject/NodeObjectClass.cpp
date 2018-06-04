//
//  kNodeObjectClass.cpp
//  kNodeObjectSystem
//
//  Created by Keitaro Takahashi on 2018/04/25.
//  Copyright © 2018 Keitaro Takahashi. All rights reserved.
//

#include "NodeObjectClass.hpp"

//#include "IRWorkspaceScene.hpp"

kNodeObject::kNodeObject(IR_Object::Name name, IR::Frame frame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output, QGraphicsScene *parentScene)
: kIRNodeBase(frame)
{
    
    this->objectName = name;
    this->uniqueID = IRRandomStringsGenerator(IR::RANDOM_STRING_LEN);
    
    // **** DUFEU REPLACE
    // this->frame = frame;
    // **** DUFEU WITH
    // this->setFrame(frame);
    // **** DUFEU COMMENTS: NO, THIS IS IN SUPERCLASS ALREADY
    
    this->inputDataType = input;
    this->outputDataType = output;
    
    //this->ObjectLabel = new NodeLabel(frame,name);
    
    //this->InnerWidget = new NodeProxyWidget(this, frame, name);
    
    /*
    //## Connect signal from Workspace to slot of kNodeObject main()
    IRWorkspaceScene *delegateScene = static_cast<IRWorkspaceScene *>(parentScene);
    QObject::connect(delegateScene, SIGNAL(executeObjSignal()), this, SLOT(main()));
    */
    
    
    /*
    
    std::cout << "\n" << std::endl;
    std::cout << "Node Object created!\n" << "\t name = " << this->objectName << "\n" << "\t uniqueID = " << this->uniqueID << std::endl;
    std::cout << "\t frame = origin (" << this->frame.origin.x << ", " << this->frame.origin.y << ") : size (" << this->frame.size.width << ", " << this->frame.size.height << ")" << std::endl;
    std::cout << "\n" << std::endl;
     
     */

}

kNodeObject::~kNodeObject()
{
    // delete this->InnerWidget;
}

void kNodeObject::createObj()
{
    // std::cout << "kNodeObject created!" << std::endl;
}

void kNodeObject::deleteObj()
{
    // std::cout << "kNodeObject deleted!" << std::endl;
}


IR_Data::INOUTDATA kNodeObject::getInputDataType()
{
    return this->inputDataType;
}

IR_Data::INOUTDATA kNodeObject::getOutputDataType()
{
    return this->outputDataType;
}



IR_Object::Name kNodeObject::getObjectName()
{
    return this->objectName;
}


IR::Frame kNodeObject::getFrame()
{
    return getFrameSize();
}


IR_Object::Id kNodeObject::getUniqueId()
{
    return this->uniqueID;
}


void kNodeObject::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "test" << std::endl;
    kIRNodeBase::mouseMoveEvent(event);
}


void kNodeObject::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    kIRNodeBase::mousePressEvent(event);
    
}


void kNodeObject::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    kIRNodeBase::mouseDoubleClickEvent(event);
}


void kNodeObject::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    kIRNodeBase::mouseReleaseEvent(event);
}


void kNodeObject::setFrameSize(IR::Size size)
{
    kIRNodeBase::setFrameSize(size);
}


void kNodeObject::setFrameOrigin(IR::Origin origin)
{
    kIRNodeBase::setFrameOrigin(origin);
}


std::string kNodeObject::IRRandomStringsGenerator(const int len)
{
    std::string s = "";
    
    char alphanum[] = "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";
    for (int i=0;i<len;i++){
        s += alphanum[rand()%(sizeof(alphanum) - 1)];
    }
    return s;
}


void kNodeObject::objSelectionChanged()
{
    std::cout << this->uniqueID << " selected." << std::endl;
    emit objSelectionChangedSignal(this->uniqueID);
}


void kNodeObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    
    kIRNodeBase::paint(painter,option,widget);
    
    /*
     
    float x = this->frame.origin.x - this->frame.size.width/2;
    float y = this->frame.origin.y - this->frame.size.height/2;
    
    QPen pen(isSelected()? Qt::darkRed : Qt::blue);
    pen.setColor(Qt::gray);
    painter->setPen(pen);
    
    QFont font = painter->font();
    int fontsize = 20;
    font.setPointSize(fontsize);
    painter->setFont(font);
    std::cout << this->frame.size.height/2 << std::endl;
    painter->drawText(QPoint(x, y+this->frame.size.height/2), QString::fromStdString(this->objectName.getParam()[1]));
    
    
    //painter->setFont("Helvetica")
    
    */
}


void kNodeObject::main()
{
    
}

// label display
void kNodeObject::setDisplayLabel(bool flag)
{
    this->DisplayLabel = flag;
}


bool kNodeObject::isDisplayLabel()
{
    return this->DisplayLabel;
}


