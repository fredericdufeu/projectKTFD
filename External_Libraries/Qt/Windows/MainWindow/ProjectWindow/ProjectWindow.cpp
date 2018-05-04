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
    
    /* create navigatorspace widget which contains both workspace navigator and file tree navigator widgets */
    /* This object should be crated before DB_workspace */
    this->navigatorspace = new NavigatorSpace(this);
    
    /* create stacke widget */
    this->stackeWidget = new QStackedWidget;
    
    /* connect event */
    IRWorkspaceListNavigator* workspaceList = this->navigatorspace->getWorkspaceList();
    QObject::connect(workspaceList, SIGNAL(selectionChangedSignal(QString)), this, SLOT(workspaceSelectionChangedSlot(QString)));

    /* create WorkSpace Database*/
    this->DB_workspace = new WorkSpaceDatabase();
    /* create one WorkSpace which is initial one */
    createWorkspace();

    /* ====== create layout ====== */
    this->layout = new QHBoxLayout(this);
    this->layout->addWidget(this->navigatorspace,1);
    /* add stackeWidget instead of WorkSpace object. */
    this->layout->addWidget(this->stackeWidget,5);
    /* setup layout spacing */
    this->layout->setSpacing(4);
    setLayout(this->layout);

    /* show */
    show();

}

IRProjectWindow::~IRProjectWindow()
{
    /* delete all WorkSpace poitner */
    this->DB_workspace->deleteAllWorkSpace();
    delete this->DB_workspace;
}

void IRProjectWindow::closeEvent(QCloseEvent *event)
{
    
    QString t = this->id + " : Do you want to keep this new document?";
    QString t2 = this->id + "Save? \n You can choose to save your changes, or delete this document. You can't undo this action.";
    
    QMessageBox::StandardButton res = QMessageBox::question(this, tr(t.toLatin1().data()), tr(t2.toLatin1().data()), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    
    switch(res)
    {
        case QMessageBox::Yes:
            //event->ignore();
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
    
    WorkSpace *newWorkSpace = new WorkSpace(this);
    
    if(this->DB_workspace->registerObjToDatabase(item.toStdString(), newWorkSpace) == false) {
        QMessageBox msg(this); msg.setText(tr("fatal Error : IRProjectWindow() : Could not create new workspace!\n")); msg.exec();
    }else{
        /* set new workspace on top to display on the Project window. */
        this->topWorkspace = newWorkSpace;
    }
    
    std::cout << "\n ===== WorkSpace Database ===== \n" << std::endl;
    this->DB_workspace->showDatabase();
    
    auto idx = this->stackeWidget->addWidget(newWorkSpace);
    auto index = this->stackeWidget->currentIndex();
    std::cout << "current Index = " << index << " : " << idx << std::endl;
    this->stackeWidget->setCurrentIndex(0);
    
    
}


/*
 #  This method is called when a SIGNAL selectionChangedSignal(QString) is called in IRWorkspaceListNavigator class.
 #  id represents the name of workspace user made or otherwise "workspace_" + counter.
 #  The displayed WorkSpace object is stored in topWorkspace member.
 */
void IRProjectWindow::workspaceSelectionChangedSlot(QString id)
{
    std::cout << "workspaceSelectionChanged slot called!! " << id.toStdString() << std::endl;
    /* retrieve a pointer of the selected WorkSpace object */
    WorkSpace *ws = this->DB_workspace->retrieveObjFromDatabase(id.toStdString());
    /* get an index of the retrieved WorkSpace object registered to QStackeWidget */
    int index = this->stackeWidget->indexOf(ws);
    /* set the selected WorkSpace to stackeWidget */
    this->stackeWidget->setCurrentIndex(index);
    /* insert the selected WorkSpace to topWorkSpace*/
    this->topWorkspace = ws;

}

void IRProjectWindow::deleteWorkspace()
{
    this->workspaceCounter -= 1;
}
