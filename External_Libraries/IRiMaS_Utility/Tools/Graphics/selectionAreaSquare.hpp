//
//  selectionAreaSquare.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/09.
//

#ifndef selectionAreaSquare_hpp
#define selectionAreaSquare_hpp

#include <stdio.h>
#include <iostream>
#include <QtWidgets>

#include "IRUtilities.hpp"
#include "kNodeUI.h"

class IRSelectionAreaSquare : public QGraphicsObject
{
    Q_OBJECT
public:
    IRSelectionAreaSquare();
    ~IRSelectionAreaSquare();
    
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    
    void drawSelectionArea(QPointF startPos, QPointF currentPos);
    void deleteSquare();
    
    void selectNodeObj(IR::Frame selectedArea, std::vector<kNodeObject *> objs);
    
    
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    
    IR::Frame getFrameSize();
    
    
private:
    IR::Frame frame;
    
};

#endif /* selectionAreaSquare_hpp */
