//
//  LeftArea.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#include "NavigatorSpace.hpp"


NavigatorSpace::NavigatorSpace(QWidget *parent)
: QWidget(parent)
{
    
    this->layout = new QVBoxLayout(this);
    
    this->fileTreeScene = new IRGraphicsScene(this);
    this->fileTreeView = new IRGraphicsView(this->fileTreeScene,this);
    this->layout->addWidget(this->fileTreeView);
    

    this->workspacelist = new IRWorkspaceListNavigator(this);

    this->layout->addWidget(this->workspacelist);
    
    
    this->layout->setSpacing(4);
    
}

NavigatorSpace::~NavigatorSpace()
{
    
}

IRWorkspaceListNavigator* NavigatorSpace::getWorkspaceList()
{
    return this->workspacelist;
}

