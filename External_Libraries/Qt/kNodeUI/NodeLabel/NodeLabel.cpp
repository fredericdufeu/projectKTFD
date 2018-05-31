//
//  NodeLabel.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/29.
//

#include "NodeLabel.hpp"

NodeLabel::NodeLabel(QWidget *parent, IR::Frame frame, IR_Object::Name name)
: QLineEdit(parent)
{
   
}

NodeLabel::~NodeLabel()
{
    
}

void NodeLabel::mousePressEvent(QMouseEvent *event){
    event->ignore();
}


void NodeLabel::mouseMoveEvent(QMouseEvent *event){
    event->ignore();
}
