//
//  IRWorkspaceNavigatorView.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#include "IRWorkspaceNavigatorView.hpp"


IRWorkspaceNavigatorView::IRWorkspaceNavigatorView(QGraphicsScene *scene, QWidget *parent)
: QGraphicsView(scene, parent)
{
    setStyleSheet("background-color:yellow;");
}

IRWorkspaceNavigatorView::~IRWorkspaceNavigatorView()
{
    
}
