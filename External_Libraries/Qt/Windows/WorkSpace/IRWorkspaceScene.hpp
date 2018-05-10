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
#include "NodeDatabase.hpp"
#include "kNodeUI.h"
#include "selectionAreaSquare.hpp"

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
    
    void createObj(kNodeObject *obj);
    void deleteObj();
    void copyObj(kNodeObject *node);
    void pasteObj(IR::Frame objFrame);
    void duplicateObj();
    void selectAllObj();
    
    void setSelectionAreaSquare(bool flag);
    
    bool isSelected();
    
signals:
    void deleteObjSignal();
    void copyObjSignal(kNodeObject *node);
    void pasteObjSignal(IR::Frame objFrame);
    void duplicateObjSignal();
    void selectAllObjSignal();
    
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    
private:
    
    NodeDatabase *database;
    void calcSelectedObjecsts();
    
    /* selection area square flag */
    bool isSelectionAreaSquareFlag = true;
    IRSelectionAreaSquare *selectionAreaSquare;
    
    /* if there is any selected objects */
    bool isSelectedFlag = false;
    
    /* key flag */
    bool key_option_press_flag = false;
    bool key_ctrl_press_flag = false; // in mac commando
    
    /* mouse flag */
    bool mouse_down_flag = false;
};
#endif /* IRWorkspaceScene_hpp */
