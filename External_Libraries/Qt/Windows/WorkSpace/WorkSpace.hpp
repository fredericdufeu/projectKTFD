//
//  WorkSpace.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#ifndef WorkSpace_hpp
#define WorkSpace_hpp

#include <stdio.h>
#include <iostream>

#include <QObject>
#include <QtWidgets>

#include "IRGraphicsView.hpp"
#include "IRGraphicsScene.hpp"

#include "IRWorkspaceView.hpp"
#include "IRWorkspaceScene.hpp"

class WorkSpace : public QWidget {
    
    Q_OBJECT
    
public:
    WorkSpace(QWidget *parent);
    ~WorkSpace();
    
    IRWorkspaceView *getView() const;
    IRWorkspaceScene *getScene() const;
    

    
    
private:
    IRWorkspaceView *workspaceView;
    IRWorkspaceScene *workspaceScene;
    
    IRGraphicsView *InspectorView;
    IRGraphicsScene *InspectorScene;
    
    QHBoxLayout *layout;
    
};

#endif /* WorkSpace_hpp */
