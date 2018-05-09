//
//  selectionAreaSquare.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/09.
//

#include "selectionAreaSquare.hpp"

IRSelectionAreaSquare::IRSelectionAreaSquare()
: QGraphicsObject()
{
    this->frame = IR::Frame{{0,0}, {0,0}};
    setFlags(QGraphicsItem::ItemSendsGeometryChanges);
    
    // set square top
    setZValue(100);
}

IRSelectionAreaSquare::~IRSelectionAreaSquare()
{
    
}

void IRSelectionAreaSquare::drawSelectionArea(QPointF startPos, QPointF currentPos)
{
    IR::Frame newFrame;
    


    newFrame.size.width = fabs(startPos.x() - currentPos.x());
    newFrame.size.height = fabs(startPos.y() - currentPos.y());
    
    newFrame.origin.x = (startPos.x() < currentPos.x()) ? startPos.x() : currentPos.x();
    newFrame.origin.x += newFrame.size.width/2;
    newFrame.origin.y = (startPos.y() < currentPos.y()) ? startPos.y() : currentPos.y();
    newFrame.origin.y += newFrame.size.height/2;

    
    this->frame = newFrame;
    
}

void IRSelectionAreaSquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::darkGray);
    painter->setPen(pen);
    
    float x = this->frame.origin.x - this->frame.size.width/2;
    float y = this->frame.origin.y - this->frame.size.height/2;
    
    painter->drawRect(x, y, this->frame.size.width, this->frame.size.height);
    
    QColor color = QColor(0, 100, 0);
    color.setAlpha(20);
    
    painter->fillRect(x, y, this->frame.size.width, this->frame.size.height, color);
}

void IRSelectionAreaSquare::deleteSquare()
{
    IR::Frame newFrame = {{0,0},{0,0}};
    this->frame = newFrame;

}


QRectF IRSelectionAreaSquare::boundingRect() const
{
    float x = this->frame.origin.x - this->frame.size.width/2;
    float y = this->frame.origin.y - this->frame.size.height/2;
    return QRectF(x-1, y-1, this->frame.size.width + 1, this->frame.size.height + 1);
}

QPainterPath IRSelectionAreaSquare::shape() const
{
    QPainterPath path;
    float x = this->frame.origin.x - this->frame.size.width/2;
    float y = this->frame.origin.y - this->frame.size.height/2;
    //path.addRect(0 - 0.5, 0 - 0.5, 800 + 1, 800 + 1);
    path.addRect(x, y, this->frame.size.width, this->frame.size.height);
    return path;
}

IR::Frame IRSelectionAreaSquare::getFrameSize()
{
    return this->frame;
}

void IRSelectionAreaSquare::selectNodeObj(IR::Frame selectedArea, std::vector<kNodeObject *> objs)
{
    std::vector<kNodeObject *> TrueObjs;
    for(auto item:objs) {
        if(selectedArea.isFrameOverlap(item->getFrameSize())) {
            item->setSelected(true);
        }
    }
}

