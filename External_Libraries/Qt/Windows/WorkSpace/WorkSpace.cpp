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
    this->scene = new IRGraphicsScene(this);
    this->view = new IRGraphicsView(this->scene, this);
    this->layout->addWidget(this->view);
    
    this->InspectorScene = new IRGraphicsScene(this);
    this->InspectorView = new IRGraphicsView(this->InspectorScene,this);
    this->layout->addWidget(this->InspectorView);
    
    this->layout->setSpacing(4);
    
}

WorkSpace::~WorkSpace()
{
    
}

IRGraphicsView *WorkSpace::getView() const
{
    return this->view;
}

IRGraphicsScene *WorkSpace::getScene() const
{
    return this->scene;
}
