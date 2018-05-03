//
//  LeftArea.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#ifndef LeftArea_hpp
#define LeftArea_hpp

#include <stdio.h>
#include <iostream>
#include <QtWidgets>

#include "IRiMaSFoundation.h"

class NavigatorSpace : public QWidget
{
    Q_OBJECT
    
public:
    NavigatorSpace(QWidget *parent);
    ~NavigatorSpace();
    
    IRWorkspaceListNavigator *getWorkspaceList();
    
private:
    IRGraphicsView *fileTreeView;
    IRGraphicsScene *fileTreeScene;
    
    IRWorkspaceListNavigator *workspacelist;
    
    QVBoxLayout *layout;
    
};

#endif /* LeftArea_hpp */
