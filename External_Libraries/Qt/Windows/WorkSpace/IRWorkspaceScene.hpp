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

    std::vector<kNodeObject* > getSelectedObjects();
    
    void createObj(IR_Object::Name name, IR::Frame objFrame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output);
    void createObj2(IR_Object::Name name, IR::Frame objFrame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output);

    void createObj(kNodeObject *obj);
    void deleteObj();
    void copyObj();
    void copyDeleteObj();
    void pasteObj();
    void duplicateObj();
    void selectAllObj();
    
    void setSelectionAreaSquare(bool flag);
    
    bool isSelected();
    void createPopUpWindow(QPointF pos);
    
    
    
    // method generate signal to call main() method in NodeObject.
    void executeObj();
    

    
signals:
    void createObjSignal(kNodeObject *obj);
    void deleteObjSignal(std::string id);
    void copyObjSignal(std::vector<kNodeObject* > node);
    void copyDeleteObjSignal();
    void pasteObjSignal();
    void duplicateObjSignal();
    void selectAllObjSignal();
    void unselectAllObjSignal();
    void areaSelectionSignal(IR::Frame selectedFrame);
    void openEditorWindowSignal(std::string id);

    
    // signal to call a slot in NodeObject.
    void executeObjSignal();
    
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    
private:
    
    void calcSelectedObjecsts();
    
    /* store pointers of the copied objects */
    std::vector<kNodeObject* > copiedObj;
    /* store pointers of the selected objects */
    std::vector<kNodeObject* > selectedObject;

    /* unselect all objects */
    void unselectAll();
    
    /* selection area square flag */
    bool isSelectionAreaSquareFlag = true;
    IRSelectionAreaSquare *selectionAreaSquare;
    
    /* if there is any selected objects */
    bool isSelectedFlag = false;
    
    /* key flag */
    bool key_option_press_flag = false;
    bool key_ctrl_press_flag = false;
    bool key_command_press_flag = false;
    
    /* mouse flag */
    bool mouse_down_flag = false;
    IR::Frame currentMousePos;
};
#endif /* IRWorkspaceScene_hpp */
