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

#include <QGraphicsItem>
#include <QRectF>
#include <QPainterPath>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QColor>
#include <QKeyEvent>

#include "kEditorWindow.hpp"



class kIRNodeBase : public QGraphicsItem
{
    
public:
    kIRNodeBase(IR::Frame frame);
    ~kIRNodeBase();
    
    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    
    int getX();
    int getY();
    
    virtual void setFrameSize(IR::Frame frame);
    
    /* enable to open an editor window when double clickled*/
    bool isOpenEditorWindow = false;
    //kEditorWindow getEditorWindow();


private:
    IR::Frame frame;
    
    
};
#endif /* kIRNodeBase_hpp */
