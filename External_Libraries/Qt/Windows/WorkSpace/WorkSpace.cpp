//
//  WorkSpace.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#include "WorkSpace.hpp"


WorkSpace::WorkSpace(QWidget *parent)
: QWidget(parent)
{
    
    std::cout << "workspace made" << std::endl;
    
    this->layout = new QHBoxLayout(this);
    this->workspaceScene = new IRWorkspaceScene(this);
    this->workspaceView = new IRWorkspaceView(this->workspaceScene, this);
    this->layout->addWidget(this->workspaceView,5);
    
    this->InspectorScene = new IRGraphicsScene(this);
    this->InspectorView = new IRGraphicsView(this->InspectorScene,this);
    this->layout->addWidget(this->InspectorView,1);
    
    this->layout->setSpacing(4);
    this->layout->setContentsMargins(4, 4, 4, 4);

}

WorkSpace::~WorkSpace()
{
    
}

IRWorkspaceView *WorkSpace::getView() const
{
    return this->workspaceView;
}

IRWorkspaceScene *WorkSpace::getScene() const
{
    return this->workspaceScene;
}
