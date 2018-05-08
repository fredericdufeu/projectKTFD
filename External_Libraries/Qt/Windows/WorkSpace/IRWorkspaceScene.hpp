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
#include "kNodeUI.h"

class IRWorkspaceScene : public QGraphicsScene
{
    Q_OBJECT
    
public:
    IRWorkspaceScene(QWidget *parent);
    ~IRWorkspaceScene();
    
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    /* this method is like DRAG event */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    
    // # IMPORTANT : Double click is ignored when any keys are pressed!
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    
    std::vector<kNodeObject* > selectedObject;
    
    std::vector<kNodeObject* > getSelectedObjects();
    
    void deleteObj();
    void copyObj(kNodeObject *node);
    void pasteObj(IR::Frame objFrame);
    void duplicateObj();
    
signals:
    void deleteObjSignal();
    void copyObjSignal(kNodeObject *node);
    void pasteObjSignal(IR::Frame objFrame);
    void duplicateObjSignal();
    
    
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    
private:
    void calcSelectedObjecsts();

};
#endif /* IRWorkspaceScene_hpp */
