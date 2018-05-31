//
//  NodeProxyWidget.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/29.
//

#ifndef NodeProxyWidget_hpp
#define NodeProxyWidget_hpp

#include <stdio.h>
#include <iostream>
#include <QtWidgets>
#include "IRUtilities.hpp"
#include "IRObjectName.h"
#include "NodeLabel.hpp"

class NodeProxyWidget : public QGraphicsProxyWidget
{
public:
    NodeProxyWidget(QGraphicsItem *object, IR::Frame frame, IR_Object::Name name);
    ~NodeProxyWidget();
    
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    
private:
    NodeLabel *line1;
    QFont font;
    
    
};


#endif /* NodeProxyWidget_hpp */
