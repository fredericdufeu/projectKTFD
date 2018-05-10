#include "MainWindow.hpp"




MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
   /* set window size */
    setMinimumSize(100, 100);
    move(0,0);
    /* create menuws */
    createMenus();
    
    show(); // call show() to show menu
    hide(); // hide main window

    /* connect actions */
    connect(newWorkSpaceAction, &QAction::triggered, this, &MainWindow::newWorkSpaceActionFunc);
    this->newWorkSpaceAction->setShortcut(Qt::CTRL + Qt::Key_N);
    connect(newProjectAction, &QAction::triggered, this, &MainWindow::createNewProject);
    this->newProjectAction->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_N); // set shortcuts (windows control+n, mac commando+n)
    connect(openProjectAction, &QAction::triggered, this, &MainWindow::openProject);
    this->openProjectAction->setShortcut(Qt::CTRL + Qt::Key_O); // set shortcuts (windows control+o, mac commando+o)
    connect(hideFileNavigatorAction, &QAction::triggered, this, &MainWindow::hideFileNavigator);
    connect(hideNodeObjInspectorAction, &QAction::triggered, this, &MainWindow::hideNodeObjInspector);
    
    connect(this->saveProjectFileAction, &QAction::triggered, this, &MainWindow::saveProjectFileActionFunc);
    this->saveProjectFileAction->setShortcut(Qt::CTRL + Qt::Key_S);
    connect(this->saveAsProjectFileAction, &QAction::triggered, this, &MainWindow::saveAsProjectFileActionFunc);
    this->saveAsProjectFileAction->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_S);
    
    
}


MainWindow::~MainWindow()
{
    //delete widget;
}

void MainWindow::createMenus()
{
    //file menus
    this->fileMenu = menuBar()->addMenu(tr("&File"));
    this->newFileMenu = this->fileMenu->addMenu("New");
    this->newWorkSpaceAction = this->newFileMenu->addAction("new Workspace");
    this->newProjectAction = this->newFileMenu->addAction("IRiMaS Project... ");
    this->saveProjectFileAction = this->fileMenu->addAction("Save Project");
    this->saveAsProjectFileAction = this->fileMenu->addAction("Save As Project");
    
    
    this->newFileMenu->addSeparator();
    this->fileMenu->addSeparator();
    this->openProjectAction = this->fileMenu->addAction("Open IRiMaS Project... ");
    
    //window menus
    this->windowMenu = menuBar()->addMenu(tr("&window"));
    this->hideFileNavigatorAction = this->windowMenu->addAction("Hide File Navigator");
    this->hideNodeObjInspectorAction = this->windowMenu->addAction("Hide Object Inspector");
}


/* ===== actions =====  */
void MainWindow::createNewProject()
{
    std::cout << "create new project" << std::endl;
    
    this->windowCounter += 1;
    QString uniqueID = "My Project " + QString::number(this->windowCounter);
    
    /* win is automatically deleted when closed by Qt::WA_DeleteOnClose method. CHECK IF IT IS TRUE OR NOT!! */
    
    IRFileSystem IRDir = IRFileSystem();
    IRDir.createProjectDirectory();
    
    
    IRProjectWindow *win = new IRProjectWindow(uniqueID,0);
    
    
}

void MainWindow::newWorkSpaceActionFunc()
{
    std::cout << "create new workspace" << std::endl;
    /* get currently top-level window */
    if(QApplication::activeWindow() != nullptr){
        IRProjectWindow *win = static_cast<IRProjectWindow* >(QApplication::activeWindow());
        win->createWorkspace();
        std::cout << win->getWindowID().toStdString() << " of " << win->getWorkspaceCount() <<std::endl;
    }else{
        std::cout << "Error newWorkSpaceActionFunc() : Could not find any active Window.\n" << std::endl;
    }
}


void MainWindow::openProject()
{
    
}

void MainWindow::hideFileNavigator()
{
    
}

void MainWindow::hideNodeObjInspector()
{
    
}

void MainWindow::saveProjectFileActionFunc()
{
    std::cout << "saveProjectFileAction" << std::endl;
}

void MainWindow::saveAsProjectFileActionFunc()
{
    std::cout << "saveAsProjectFileAction" << std::endl;

}


void MainWindow::cleanUpOnQuit()
{

}

