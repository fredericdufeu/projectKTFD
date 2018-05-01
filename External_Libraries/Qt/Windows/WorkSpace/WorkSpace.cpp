//
//  WorkSpace.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#include "WorkSpace.hpp"


WorkSpace::WorkSpace(QWidget *parent)
{
    
    std::cout << "workspace made" << std::endl;
    setGeometry(20, 20, 11, 300);
    
    
    //resize(250, 250);
    //move(20,20);
    //setStyleSheet("background-color:black;");
    
    
    QHBoxLayout *layout = new QHBoxLayout(this);
    QPushButton *button = new QPushButton("hello");
    layout->addWidget(button);
    setLayout(layout);
    
    show();
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
