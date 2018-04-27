#include "MainWindow.hpp"





#include <iostream>

#include <QMenuBar>
#include <QString>
#include <QFileDialog>
#include <QFileSystemModel>
#include <QDirModel>
#include <QTreeView>
#include <QDir>
#include <QAbstractItemView>

#include "portaudio.h" // INITIALIZING PA IN CONSTRUCTOR OF MAINWINDOW



MainWindow::MainWindow(QWidget *parent, GlobalDataBase *refDataBase)
: QMainWindow(parent)
{
    
    PaError err = Pa_Initialize();
    if (err != paNoError)
        std::cout << "PortAudio error on initialise" << err << std::endl;
    
    
    
    setMinimumSize(1000, 750);
    
    dataBase = refDataBase;
    
    someValueToTestForwardDeclaration = 22;
    
    // CREATE MENUS
    
    createMenus();
    
    // CONNECTION OF MENU ACTIONS TO METHODS
    
    connect(newProjectAction, &QAction::triggered, this, &MainWindow::createNewProject);
    connect(newProjectFromSoundFileAction, &QAction::triggered, this, &MainWindow::createNewProjectFromSoundFile);
    connect(newProjectFromFolderAction, &QAction::triggered, this, &MainWindow::createNewProjectFromFolder);
    connect(openProjectAction, &QAction::triggered, this, &MainWindow::openProject);
    
    connect(toggleFileExplorerHidden, &QAction::triggered, this, &MainWindow::toggleFileExplorerHiddenAction);
    connect(toggleObjectInspectorHidden, &QAction::triggered, this, &MainWindow::toggleObjectInspectorHiddenAction);
    
    // CENTRAL WIDGET
    
    widget = new CentralWidget(this, dataBase);
    setCentralWidget(widget);
    
    
}


MainWindow::~MainWindow()
{
    delete widget;
}


void MainWindow::someDummyFunctionToTestForwardDeclaration()
{
    std::cout << "HELLO GUYS!!!" << std::endl;
}


void MainWindow::createMenus()
{
    // std::cout << "creating Menus" << std::endl;
    
    // FILE MENU
    
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenuNew = fileMenu->addMenu("New");
    newProjectAction = fileMenuNew->addAction("IRiMaS Project...");
    fileMenuNew->addSeparator();
    newProjectFromSoundFileAction = fileMenuNew->addAction("IRiMaS Project from Sound File...");
    newProjectFromFolderAction = fileMenuNew->addAction("IRiMaS Project from Folder...");
    fileMenu->addSeparator();
    openProjectAction = fileMenu->addAction("Open IRiMaS Project...");
    
    // WINDOW MENU
    
    windowMenu = menuBar()->addMenu(tr("&Window"));
    toggleFileExplorerHidden = windowMenu->addAction("Hide File Explorer");
    toggleObjectInspectorHidden = windowMenu->addAction("Hide Object Inspector");
}


void MainWindow::createNewProject()
{
    std::cout << "creating New Project" << std::endl;
    CentralWidget *widget = static_cast<CentralWidget *>(centralWidget());
    // widget->getFileExplorer()->hide(); // this works, but now I am doing it more cleverly hopefully
    // widget->toggleFileExplorerHidden();
    
    
    
    
    
}


void MainWindow::createNewProjectFromSoundFile()
{
    std::cout << "creating New Project From Sound File" << std::endl;
    CentralWidget *widget = static_cast<CentralWidget *>(centralWidget());
    // widget->getFileExplorer()->show();
    // widget->toggleObjectInspectorHidden(); // this is ideal, but centralwidget cannot be aware of the mainwindow class
    
    
    
    
    
    
    
    
    
}



void MainWindow::createNewProjectFromFolder()
{
    std::cout << "creating New Project From Folder" << std::endl;
    
    QString pathname = QFileDialog::getExistingDirectory(
                                                         nullptr,
                                                         tr("Choose a Folder"),
                                                         QDir::homePath(), // see the qdir path for more investigation
                                                         QFileDialog::ShowDirsOnly
                                                         | QFileDialog::DontResolveSymlinks
                                                         );
    
    if (pathname.isNull())
    {
        std::cout << "cancelled" << std::endl;
        return;
    }
    
    std::cout << "Path Name " << pathname.toStdString() << std::endl;
    
    // NOW, HOW DO I PUT THE FOLDER INTO MY QTREEVIEW???
    
    // 1) FIRST CREATE A QFILESYSTEMMODEL
    
    QFileSystemModel *model = new QFileSystemModel(this);
    model->setRootPath(pathname);
    widget->getFileExplorer()->setModel(model);
    widget->getFileExplorer()->setRootIndex(model->index(pathname));
    
    widget->getFileExplorer()->hideColumn(1); // size
    widget->getFileExplorer()->hideColumn(2); // kind
    widget->getFileExplorer()->hideColumn(3); // date modified
    
    widget->getFileExplorer()->setSelectionMode(QAbstractItemView::MultiSelection);
    widget->getFileExplorer()->setDragEnabled(true);
    widget->getFileExplorer()->setAcceptDrops(true);
    
    // OK - NOW HOW CAN I CLICK AND DRAG FROM THIS??? THAT IS THE QUESTION
    
    
}


void MainWindow::openProject()
{
    std::cout << "opening Project" << std::endl;
}


void MainWindow::toggleFileExplorerHiddenAction()
{
    if (widget->isFileExplorerHidden())
    {
        widget->setIsFileExplorerHidden(false);
        windowMenu->actions()[0]->setText("Hide File Explorer");
    }
    else
    {
        widget->setIsFileExplorerHidden(true);
        windowMenu->actions()[0]->setText("Show File Explorer");
    }
}


void MainWindow::toggleObjectInspectorHiddenAction()
{
    if (widget->isObjectInspectorHidden())
    {
        widget->setIsObjectInspectorHidden(false);
        windowMenu->actions()[1]->setText("Hide Object Inspector");
    }
    else
    {
        widget->setIsObjectInspectorHidden(true);
        windowMenu->actions()[1]->setText("Show Object Inspector");
    }
}


void MainWindow::cleanUpOnQuit()
{
    std::cout << "cleaning up..." << std::endl;
    // DONE WITH PORTAUDIO NOW...
    
    PaError err = Pa_Terminate();
    std::cout << "Terminate PA error code: " << err << std::endl;
}


