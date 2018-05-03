//
//  IRWorkspaceScene.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/02.
//

#ifndef IRWorkspaceScene_hpp
#define IRWorkspaceScene_hpp

#include <stdio.h>
#include <iostream>

#include <QtWidgets>

class IRWorkspaceScene : public QGraphicsScene
{
    Q_OBJECT
    
public:
    IRWorkspaceScene(QWidget *parent);
    ~IRWorkspaceScene();
};
#endif /* IRWorkspaceScene_hpp */
