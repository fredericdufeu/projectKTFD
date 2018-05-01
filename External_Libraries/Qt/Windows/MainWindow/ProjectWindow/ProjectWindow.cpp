//
//  ProjectWindow.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#include "ProjectWindow.hpp"


IRProjectWindow::IRProjectWindow(QWidget *parent)
: QWidget(parent)
{
    
    resize(640, 480);
    setWindowTitle("workspace");
    move(200,100);
    /* delete this window when closed. */
    setAttribute(Qt::WA_DeleteOnClose);
    
    
    this->workspace = new WorkSpace(this);

    this->layout = new QHBoxLayout(this);
    
    this->layout->addWidget(this->workspace);
    
    
    setLayout(this->layout);
    
    
    this->layout->setSpacing(0);
    
    show();

}

IRProjectWindow::IRProjectWindow()
{
    delete this->workspace;
}

void IRProjectWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton res = QMessageBox::question(this, tr("Do you want to keep this new document?"), tr("Save? \n You can choose to save your changes, or delete this document. You can't undo this action."), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    
    switch(res)
    {
        case QMessageBox::Yes:
            event->ignore();
            event->accept();
            break;
            
        case QMessageBox::No:
            event->accept();
            break;
            
        case QMessageBox::Cancel:
            event->ignore();
            break;
    }
    
}
