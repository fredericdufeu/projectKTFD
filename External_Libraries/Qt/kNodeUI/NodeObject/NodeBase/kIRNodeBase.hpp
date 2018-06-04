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
#include <functional>
#include <QtWidgets>


#include "IRUtilities.hpp"

//class kEditorWindow;

class kIRNodeBase : public QGraphicsObject
{
    Q_OBJECT
public:
    kIRNodeBase(IR::Frame frame);
    ~kIRNodeBase();
    
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    
    /* move object to the indicated position */
    void setObjPos(IR::Origin pos); // FD TO CLARIFY
    void moveObjBy(IR::Origin pos); // FD TO CLARIFY

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    
    void openEditorWindow();

    /* handle all item status change */
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    
    /* call when selection changed in mousePressEvent() */
    void ItemSelectedChange();
    
    virtual void objSelectionChanged();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    
    void ItemSelectedHasChanged();
    
    int getX(); // FD TO CLARIFY
    int getY(); // FD TO CLARIFY
    
    IR::Frame getFrameSize(); // FD TO CLARIFY
    
    // virtual void setFrameSize(IR::Frame frame);
    virtual void setOrigin(IR::Origin origin);
    
    /* enable to open an editor window when double clickled */
    bool isOpenEditorWindow = false;
    
    // DUFEU ADD ON
    
    void setFrame(IR::Frame frame);
    virtual void setFrameOrigin(IR::Origin origin);
    virtual void setFrameSize(IR::Size size); // TO REPLACE FROM THE ABOVE WHEN SURE
    
    IR::Frame getFrame();
    IR::Origin getFrameOrigin();
    // IR::Size getFrameSize(); // TO REPLACE FROM THE ABOVE WHEN SURE
    
    /* give signals to inform events */
signals:
    void mousePressSignal(QGraphicsSceneMouseEvent *event);
    void mouseMoveSignal(QGraphicsSceneMouseEvent *event);
    void mouseReleaseSignal(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickSignal(QGraphicsSceneMouseEvent *event);
    


private:
    IR::Frame frame;
    
    // *** COORD STUFF ADDED BY FD
    
    public:
    
    float xc;
    float yc;
    
    float xdim;
    float ydim;
    
    float xl;
    float xr;
    float yt;
    float yb;
    
    private:
    // *** (end) COORD STUFF ADDED BY FD

    bool isEnableMultiSelection = false;
    

    
};
#endif /* kIRNodeBase_hpp */
