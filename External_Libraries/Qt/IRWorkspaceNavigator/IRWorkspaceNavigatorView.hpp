//
//  IRWorkspaceNavigatorView.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#ifndef IRWorkspaceNavigatorView_hpp
#define IRWorkspaceNavigatorView_hpp

#include <stdio.h>
#include <iostream>
#include <QtWidgets>

class IRWorkspaceNavigatorView : public QGraphicsView
{
public:
    IRWorkspaceNavigatorView(QGraphicsScene *scene, QWidget *parent);
    ~IRWorkspaceNavigatorView();
};

#endif /* IRWorkspaceNavigatorView_hpp */
