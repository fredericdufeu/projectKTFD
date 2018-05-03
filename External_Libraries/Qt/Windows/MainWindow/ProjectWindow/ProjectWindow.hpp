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
#include "WorkSpaceDatabase.hpp"

class IRProjectWindow : public QWidget
{
    Q_OBJECT
    
public:
    IRProjectWindow(QString id, QWidget *parent = 0);
    ~IRProjectWindow();
    
    QString getWindowID();
    unsigned int getWorkspaceCount();
    
    void createWorkspace();
    void deleteWorkspace();
    
public slots:
    void workspaceSelectionChangedSlot(QString id);

    
private:
    void closeEvent(QCloseEvent *event) override;
    
    
    unsigned int workspaceCounter = 0;
    WorkSpaceDatabase *DB_workspace;
    
    /* This pointer indicates the workspace which should be shown on the Project Window. */
    WorkSpace *topWorkspace;
    /* for switching Widget */
    QStackedWidget *stackeWidget;
    
    NavigatorSpace *navigatorspace;
    QHBoxLayout *layout;
    
    QString id;

    
};

#endif /* ProjectWindow_hpp */
