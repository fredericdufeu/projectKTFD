//
//  kIRNodeBase.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/27.
//

#include "kIRNodeBase.hpp"

kIRNodeBase::kIRNodeBase(IR::Frame frame) :
    QGraphicsItem()
{
    this->frame = frame;

    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
}

kIRNodeBase::~kIRNodeBase()
{
    
}




void kIRNodeBase::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    
}

void kIRNodeBase::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //std::cout << "mouse moved. " << event->scenePos().x() << " , " << event->scenePos().y() << std::endl;
    
}

void kIRNodeBase::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    
}

void kIRNodeBase::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    
}

void kIRNodeBase::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    
    QPen pen(Qt::darkRed);
    pen.setColor(Qt::black);
    painter->setPen(pen);
    
    float x = this->frame.origin.x - this->frame.size.width/2;
    float y = this->frame.origin.y - this->frame.size.height/2;

    painter->drawRect(x, y, this->frame.size.width, this->frame.size.height);
    painter->fillRect(x, y, this->frame.size.width, this->frame.size.height, Qt::lightGray);
    
    //painter->drawRect(0,0,100,200);

    
    printf("paint called! :: object made in %f, %f", this->frame.origin.x, this->frame.origin.y);
}

QRectF kIRNodeBase::boundingRect() const
{
    return QRectF(-1, -1, this->frame.size.width + 1, this->frame.size.height + 1);
}

QPainterPath kIRNodeBase::shape() const
{
    QPainterPath path;
    path.addRect(0 - 0.5, 0 - 0.5, 800 + 1, 800 + 1);
    return path;
}


int kIRNodeBase::getX(){
    return this->frame.origin.x;
}
int kIRNodeBase::getY(){
    return this->frame.origin.y;
}

void kIRNodeBase::setFrameSize(IR::Frame frame)
{
    this->frame = frame;
}

