//
//  IRGraphicsView.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#ifndef IRGraphicsView_hpp
#define IRGraphicsView_hpp

#include <stdio.h>
#include <iostream>
#include <QtWidgets>

#include "IRUtilities.hpp"
#include "kNodeUI.h"



class IRGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    IRGraphicsView(QGraphicsScene *scene, QWidget *parent);
    ~IRGraphicsView();
    
    
    virtual void dragEnterEvent(QDragEnterEvent *event) override;
    virtual void dragMoveEvent(QDragMoveEvent *event) override;
    virtual void dropEvent(QDropEvent *event) override;
    
private:
    IR::Point mPos;

};

#endif /* IRGraphicsView_hpp */