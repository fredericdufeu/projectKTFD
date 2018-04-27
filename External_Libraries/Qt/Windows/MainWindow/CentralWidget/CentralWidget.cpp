//
//  CentralWidget.cpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 23/04/2018.
//


#include "CentralWidget.hpp"

// HERE I SHOULD BE ABLE TO INCLUDE MAINWINDOW.H, SHOULDN'T I?
#include "MainWindow.hpp"



CentralWidget::CentralWidget(QWidget *parent, GlobalDataBase *refDatabase)
: QWidget(parent)
{
    // NOW, SEE HOW TO SHOW / HIDE, LEFT AND RIGHT
    // I GET IT: show() / hide()!!! Beautiful!!! Now. I will try to connect the menus to that.
    // which of course, will raise the problem of how to pass data from the guys.
    // but at least I now have a very clear structure
    // mainWindow
    // -> CentralWidget (centralWidget of mainWindow) => parent? Can I set it to mainwindow? QMainWindow inherits QWidget
    // --> layout               (parent: null)
    // -----> fileExplorer      (parent: null)
    // -----> view              (parent: CentralWidget)
    // -----> objectInspector   (parent: null)
    
    // QWidget *dummyWidget = dummyMainWindowForForwardDeclarationTests->centralWidget();
    
    // JUST TO TEST: LET US DO SOMETHING WITH A DUMMY PARAM OF MY MAIN WINDOW
    
    editorWindow = new EditorWindow(this);
    
    
    database = refDatabase;
    
    // now, what makes sense in terms of parents?
    
    layout = new QHBoxLayout;
    fileExplorerIsHidden = false;
    objectInspectorIsHidden = false;
    
    fileExplorer = new TreeView(this);
    fileExplorer->setFixedWidth(200);
    
    scene = new GraphicsScene;
    scene->setSceneRect(-100, -100, 200, 200);
    scene->addLine(0, 0, 100, 100);
    
    view = new GraphicsView(scene, this);
    
    objectInspector = new QTextEdit; // of course, this later will be a custom widget
    objectInspector->setFixedWidth(200);
    
    layout->addWidget(fileExplorer);
    layout->addWidget(view);
    layout->addWidget(objectInspector);
    
    this->setLayout(layout);
}


CentralWidget::~CentralWidget()
{
    delete layout;
    
    delete fileExplorer;
    delete objectInspector;
    
    delete scene;
    delete view;
}


TreeView *CentralWidget::getFileExplorer() const
{
    return fileExplorer;
}


GraphicsView *CentralWidget::getView() const
{
    return view;
}


GraphicsScene *CentralWidget::getScene() const
{
    return scene;
}


QTextEdit *CentralWidget::getObjectInspector() const
{
    return objectInspector;
}


bool CentralWidget::isFileExplorerHidden() const
{
    return fileExplorerIsHidden;
}


bool CentralWidget::isObjectInspectorHidden() const
{
    return objectInspectorIsHidden;
}


void CentralWidget::setIsFileExplorerHidden(bool hidden)
{
    fileExplorerIsHidden = hidden;
    if (fileExplorerIsHidden)
        fileExplorer->hide();
    else
        fileExplorer->show();
}


void CentralWidget::setIsObjectInspectorHidden(bool hidden)
{
    objectInspectorIsHidden = hidden;
    if (objectInspectorIsHidden)
        objectInspector->hide();
    else
        objectInspector->show();
    // NOW, MORE CHALLENGING: CHANGE THE STRING IN MENU... DOING FROM MAIN WINDOW - THIS CANNOT BE AWARE OF PARENT CLASS...
}


/*
void CentralWidget::toggleFileExplorerHidden()
{
    setIsFileExplorerHidden(!fileExplorerIsHidden);
}


void CentralWidget::toggleObjectInspectorHidden()
{
    setIsObjectInspectorHidden(!objectInspectorIsHidden);
}
 */






