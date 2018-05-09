//
//  kIRNodeBase.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/27.
//

#ifndef kIRNodeBase_hpp
#define kIRNodeBase_hpp

#include <stdio.h>
#include <iostream>

#include <QtWidgets>


#include "kEditorWindow.hpp"
#include "IRUtilities.hpp"



class kIRNodeBase : public QGraphicsObject
{
    Q_OBJECT
public:
    kIRNodeBase(IR::Frame frame);
    ~kIRNodeBase();
    
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    
    /* move object to the indicated position */
    void setObjPos(IR::Origin pos);
    void moveObjBy(IR::Origin pos);

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    
    void openEditorWindow();

    /* handle all item status change */
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    
    /* call when selection changed in mousePressEvent() */
    void ItemSelectedChange();
    
    virtual void objSelectionChanged();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    
    void ItemSelectedHasChanged();
    
    int getX();
    int getY();
    
    IR::Frame getFrameSize();
    
    virtual void setFrameSize(IR::Frame frame);
    
    /* enable to open an editor window when double clickled*/
    bool isOpenEditorWindow = false;
    
    kEditorWindow *getEditorWindow();
    
    
    /* give signals to inform events */
signals:
    void mousePressSignal(QGraphicsSceneMouseEvent *event);
    void mouseMoveSignal(QGraphicsSceneMouseEvent *event);
    void mouseReleaseSignal(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickSignal(QGraphicsSceneMouseEvent *event);
    


private:
    IR::Frame frame;
    kEditorWindow *editorWindow = nullptr;
    
    bool isEnableMultiSelection = false;

    
};
#endif /* kIRNodeBase_hpp */
