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

#include "NodeDatabase.hpp"
#include "kNodeUI.h"

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
    
    NodeDatabase *database;
    
private slots:
    void createObj(kNodeObject *obj);
    void deleteObj(std::string id);
    void copyObj();
    void copyDeleteObj();
    void pasteObj();
    void duplicateObj();
    void selectAllObj();
    void unselectAllObj();
    void areaSelection(IR::Frame selectedFrame);
    void openEditorWindow(std::string id);

    
    
};

#endif /* WorkSpace_hpp */
