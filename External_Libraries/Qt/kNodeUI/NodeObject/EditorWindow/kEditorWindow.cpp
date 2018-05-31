//
//  EditorWindow.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/30.
//

#include "kEditorWindow.hpp"
#include "NodeObjectClass.hpp"


kEditorWindow::kEditorWindow(QString &windowTitle, QWidget *parent)
: QWidget(parent)
{
    this->parent = parent;
    setWindowFlag(Qt::WindowStaysOnTopHint);
    setMinimumSize(200,150);
    resize(640, 480);
    this->setWindowTitle(windowTitle);

    
    this->layout = new QHBoxLayout(this);
    this->scene = new kEditorWindowScene(this);
    this->view = new kEditorWindowView(this->scene,this);
    
    this->layout->addWidget(this->view);
    this->layout->setContentsMargins(0, 0, 0, 0);
    this->layout->setSpacing(4);
    
    /* register shortcut key */
    QShortcut *closeCtrlW = new QShortcut(this);
    closeCtrlW->setKey(Qt::CTRL + Qt::Key_W);
    connect(closeCtrlW, SIGNAL(activated()), this, SLOT(close()));
    
    
}

kEditorWindow::~kEditorWindow()
{
    
}
