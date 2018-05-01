#ifndef MAINWINDOW_H
#define MAINWINDOW_H


// NOTE THAT UNLIKE ALL OTHER Q_OBJECT CLASSES, MAINWINDOW HEADER IS WITH LOWERCASE AND .H
// THIS CANNOT BE CHANGED BECAUSE IT IS THE TOP-LEVEL Q_OBJECT, WITH MOC SET FOR IT


#include <iostream>


#include <QMainWindow>
#include <QtWidgets>
#include "portaudio.h" // INITIALIZING PA IN CONSTRUCTOR OF MAINWINDOW



#include "IRUtilities.hpp"




class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    void createNewProject();
    void openProject();
    
    void cleanUpOnQuit();
    
private:
    void createMenus();
    void hideFileNavigator();
    void hideNodeObjInspector();
    
    QMenu *fileMenu;
    QMenu *newFileMenu;
    
    QAction *newProjectAction;
    QAction *openProjectAction;
    
    QMenu *windowMenu;
    QAction *hideFileNavigatorAction;
    QAction *hideNodeObjInspectorAction;
    
    //widget

};

#endif // MAINWINDOW_H
