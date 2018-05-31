//
//  NodeProxyWidget.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/29.
//

#include "NodeProxyWidget.hpp"


NodeProxyWidget::NodeProxyWidget(QGraphicsItem *object, IR::Frame frame, IR_Object::Name name)
: QGraphicsProxyWidget(object)
{
    
    //ignore mous
    //this->setAttribute(Qt::WA_TransparentForMouseEvents);
  
    QString text = name.toQString();
    this->line1 = new NodeLabel(0,frame,name);
    
    float x = frame.origin.x;
    float y = frame.origin.y;
    float w = frame.size.width;
    float h = frame.size.height;
    float w2 = w/2;
    float h2 = h/2;
    
  
    this->line1->setText(text);
    this->line1->setGeometry(0,0,w,h);
    this->line1->setDisabled(true);
    this->line1->setStyleSheet("QLineEdit { background: rgba(255, 255, 255, 0); selection-background-color: rgb(233, 99, 0); }");
    this->line1->setAttribute(Qt::WA_TransparentForMouseEvents);
    this->setWidget(line1);
    this->QGraphicsWidget::setGeometry(x-w2, y-h2, 100, h);
    
}

NodeProxyWidget::~NodeProxyWidget()
{
    
}

void NodeProxyWidget::mousePressEvent(QGraphicsSceneMouseEvent *event){
    event->ignore();
}


