#include "MainWindow.hpp"




MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
   /* set window size */
    setMinimumSize(1000, 750);
    /* create menuws */
    createMenus();
    
    /* connect actions */
    connect(newProjectAction, &QAction::triggered, this, &MainWindow::createNewProject);
    this->newProjectAction->setShortcut(Qt::CTRL + Qt::Key_N); // set shortcuts (windows control+n, mac commando+n)
    connect(openProjectAction, &QAction::triggered, this, &MainWindow::openProject);
    this->openProjectAction->setShortcut(Qt::CTRL + Qt::Key_O); // set shortcuts (windows control+o, mac commando+o)
    connect(hideFileNavigatorAction, &QAction::triggered, this, &MainWindow::hideFileNavigator);
    connect(hideNodeObjInspectorAction, &QAction::triggered, this, &MainWindow::hideNodeObjInspector);
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
    this->newProjectAction = this->newFileMenu->addAction("IRiMaS Project... ");
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



void MainWindow::cleanUpOnQuit()
{

}
