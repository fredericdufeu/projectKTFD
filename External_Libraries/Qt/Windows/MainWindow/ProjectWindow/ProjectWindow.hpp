//
//  ProjectWindow.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#ifndef ProjectWindow_hpp
#define ProjectWindow_hpp

#include <stdio.h>
#include <iostream>
#include <QtWidgets>
#include "WorkSpace.hpp"
#include "NavigatorSpace.hpp"

class IRProjectWindow : public QWidget
{
    Q_OBJECT
    
public:
    IRProjectWindow(QString id, QWidget *parent = 0);
    IRProjectWindow();
    
    QString getWindowID();
    unsigned int getWorkspaceCount();
    
    void createWorkspace();
    void deleteWorkspace();

    
private:
    void closeEvent(QCloseEvent *event) override;
    
    
    WorkSpace *workspace;
    unsigned int workspaceCounter = 0;
    //std::map<std::string>

    NavigatorSpace *navigatorspace;
    QHBoxLayout *layout;
    
    QString id;

    
};

#endif /* ProjectWindow_hpp */
