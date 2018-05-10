//
//  IRWorkspaceView.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/02.
//

#ifndef IRWorkspaceView_hpp
#define IRWorkspaceView_hpp

#include <stdio.h>
#include <iostream>

#include <QtWidgets>

#include "IRUtilities.hpp"
#include "kNodeUI.h"

#include "NodeDatabase.hpp"
#include "IRWorkspaceScene.hpp"

#include "IRWaveformNodeObject.hpp"


class IRWorkspaceView : public QGraphicsView
{
    Q_OBJECT
    
public:
    IRWorkspaceView(QGraphicsScene *scene, QWidget *parent);
    ~IRWorkspaceView();
    
    virtual void dragEnterEvent(QDragEnterEvent *event) override;
    virtual void dragMoveEvent(QDragMoveEvent *event) override;
    virtual void dropEvent(QDropEvent *event) override;

    /* fundamental */
    void createObj(IR_Object::Name name, IR::Frame objFrame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output);
    void copyObj();
    void deleteObj();

signals:
    void createObjSignal(IR_Object::Name name, IR::Frame objFrame);

    
private:
    IR::Point mPos;
    
    void createAudioObj(IR::Frame objFrame);

};

#endif /* IRWorkspaceView_hpp */
