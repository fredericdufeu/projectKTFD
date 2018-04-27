//
//  EditorWindow.cpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 24/04/2018.
//

#include "EditorWindow.hpp"


EditorWindow::EditorWindow(QWidget *parent)
: QWidget(parent)
{
    setWindowFlags(Qt::Window);
    setMinimumSize(800, 600);
    
    layout = new QHBoxLayout;

    scene = new EditorWindowGraphicsScene;
    view = new EditorWindowGraphicsView(scene, this);
    
    inspector = new QTextEdit;
    inspector->setFixedWidth(200);
    
    layout->addWidget(view);
    layout->addWidget(inspector);
    
    this->setLayout(layout);
}


EditorWindow::~EditorWindow()
{

}

