#ifndef MAINWINDOW_H
#define MAINWINDOW_H


// NOTE THAT UNLIKE ALL OTHER Q_OBJECT CLASSES, MAINWINDOW HEADER IS WITH LOWERCASE AND .H
// THIS CANNOT BE CHANGED BECAUSE IT IS THE TOP-LEVEL Q_OBJECT, WITH MOC SET FOR IT




#include <QMainWindow>

#include <QWidget>
#include <QMenu>
#include <QAction>

#include "GlobalDatabase.hpp"
#include "CentralWidget.hpp"





class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0, GlobalDataBase *refDataBase = nullptr);
    ~MainWindow();
    
    void createNewProject();
    void createNewProjectFromSoundFile();
    void createNewProjectFromFolder();
    void openProject();
    
    GlobalDataBase *dataBase;
    
    int someValueToTestForwardDeclaration;
    
    void someDummyFunctionToTestForwardDeclaration();
    
    void cleanUpOnQuit();
    
private:
    void createMenus();
    
    void toggleFileExplorerHiddenAction();
    void toggleObjectInspectorHiddenAction();
    
    // MENUS and Actions
    
    // File menu
    
    QMenu *fileMenu;
    QMenu *fileMenuNew;
    QAction *newProjectAction;
    QAction *newProjectFromSoundFileAction;
    QAction *newProjectFromFolderAction;
    
    QAction *openProjectAction;
    
    // Window menu
    
    QMenu *windowMenu;
    QAction *toggleFileExplorerHidden;
    QAction *toggleObjectInspectorHidden;
    
    // CENTRAL WIDGET
    
    CentralWidget *widget;
};

#endif // MAINWINDOW_H
