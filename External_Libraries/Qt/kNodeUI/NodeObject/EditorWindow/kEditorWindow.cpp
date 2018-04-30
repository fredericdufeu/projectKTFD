//
//  EditorWindow.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/30.
//

#include "kEditorWindow.hpp"

kEditorWindow::kEditorWindow(QWidget *parent)
: QWidget(parent)
{
    this->parent = parent;
    //setWindowFlag(Qt::Window);
    //setMinimumSize(400,300);
    
}

kEditorWindow::~kEditorWindow()
{
    
}
