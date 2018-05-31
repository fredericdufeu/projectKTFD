//
//  NodeLabel.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/29.
//

#ifndef NodeLabel_hpp
#define NodeLabel_hpp

#include <stdio.h>
#include <iostream>
#include <QtWidgets>
#include "IRUtilities.hpp"
#include "IRObjectName.h"

class NodeLabel : public QLineEdit
{
public:
    NodeLabel(QWidget *parent, IR::Frame frame, IR_Object::Name name);
    ~NodeLabel();
    
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
private:
    IR::Frame frame;
};

#endif /* NodeLabel_hpp */
