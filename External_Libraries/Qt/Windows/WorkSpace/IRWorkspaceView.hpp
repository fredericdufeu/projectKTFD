//
//  IRWorkspaceView.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/02.
//

#ifndef IRWorkspaceView_hpp
#define IRWorkspaceView_hpp

#include <stdio.h>
#include <iostream>

#include <QtWidgets>

#include "IRUtilities.hpp"
#include "kNodeUI.h"


class IRWorkspaceView : public QGraphicsView
{
    Q_OBJECT
    
public:
    IRWorkspaceView(QGraphicsScene *scene, QWidget *parent);
    ~IRWorkspaceView();
    
    virtual void dragEnterEvent(QDragEnterEvent *event) override;
    virtual void dragMoveEvent(QDragMoveEvent *event) override;
    virtual void dropEvent(QDropEvent *event) override;
    
private:
    IR::Point mPos;
};

#endif /* IRWorkspaceView_hpp */
