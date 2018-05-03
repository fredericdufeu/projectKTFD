//
//  ProjectWindow.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#include "ProjectWindow.hpp"


IRProjectWindow::IRProjectWindow(QString id, QWidget *parent)
: QWidget(parent)
{
    /*
     # ===== Project Window =====
     #  It consists of several widgets : 
     #      1. Navigator space
     #          a. File free navigator
     #          b. workspace nagivator
     #      2. Work space widget
     #          a. work space
     #          b. work space Inspector
     #
     */
    
    this->id = id;
    
    /* get screen size */
    //QRect screenSize = QApplication::desktop()->screenGeometry();
    resize(1280, 640);
    setWindowTitle(this->id);
    move(200,100);
    /* delete this window when closed. */
    setAttribute(Qt::WA_DeleteOnClose);
    
    
    /* create workspace widget which contains both workspace and workspace inspector widgets */
    this->workspace = new WorkSpace(this);
    this->workspaceCounter = 1; // initialy 1
    
    /* create navigatorspace widget which contains both workspace navigator and file tree navigator widgets */
    this->navigatorspace = new NavigatorSpace(this);
    
    /* create layout */
    this->layout = new QHBoxLayout(this);

    this->layout->addWidget(this->navigatorspace,1);
    this->layout->addWidget(this->workspace,5);
    

    /* setup layout spacing */
    this->layout->setSpacing(4);
    setLayout(this->layout);

    /* show */
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

QString IRProjectWindow::getWindowID()
{
    return this->id;
}

unsigned int IRProjectWindow::getWorkspaceCount()
{
    return this->workspaceCounter;
}

void IRProjectWindow::createWorkspace()
{
    this->workspaceCounter += 1;
    QString item = "workspace_" + QString::number(this->workspaceCounter);
    this->navigatorspace->getWorkspaceList()->addNewItem(item);
}

void IRProjectWindow::deleteWorkspace()
{
    this->workspaceCounter -= 1;
}
