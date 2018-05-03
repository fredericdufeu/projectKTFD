//
//  kIRNodeBase.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/27.
//

#include "kIRNodeBase.hpp"

kIRNodeBase::kIRNodeBase(IR::Frame frame)
: QGraphicsItem()
{
    this->frame = frame;
    
    //this->editorWindow = new kEditorWindow(this->parent);

    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
}

kIRNodeBase::~kIRNodeBase()
{
    
}




void kIRNodeBase::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "mouse pressed " << event->scenePos().x() << std::endl;

}

void kIRNodeBase::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "mouse move " << event->scenePos().x() << std::endl;
    moveBy(event->scenePos().x() - event->lastScenePos().x(), event->scenePos().y() - event->lastScenePos().y());

    
}

void kIRNodeBase::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    
}

void kIRNodeBase::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(this->isOpenEditorWindow == true) {
    }
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

}

QRectF kIRNodeBase::boundingRect() const
{
    float x = this->frame.origin.x - this->frame.size.width/2;
    float y = this->frame.origin.y - this->frame.size.height/2;
    return QRectF(x-1, y-1, this->frame.size.width + 1, this->frame.size.height + 1);
}

QPainterPath kIRNodeBase::shape() const
{
    QPainterPath path;
    float x = this->frame.origin.x - this->frame.size.width/2;
    float y = this->frame.origin.y - this->frame.size.height/2;
    //path.addRect(0 - 0.5, 0 - 0.5, 800 + 1, 800 + 1);
    path.addRect(x, y, this->frame.size.width, this->frame.size.height);
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
    update();
}


