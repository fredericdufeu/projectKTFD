//
//  kIRNodeBase.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/27.
//

#include "kIRNodeBase.hpp"

kIRNodeBase::kIRNodeBase(IR::Frame frame)
: QGraphicsObject()
{
    this->frame = frame;
    
    this->editorWindow = new kEditorWindow(0);

    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
}

kIRNodeBase::~kIRNodeBase()
{
}
/*
void kIRNodeBase::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //necessary to call it to select this object
    QGraphicsObject::mousePressEvent(event);
    std::cout << "mouse pressed " << isSelected() << " : " << event->scenePos().x() << std::endl;

    if(isSelected()){
        objSelectionChanged();
    }
    emit mousePressSignal(event);
}

void kIRNodeBase::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "mouse move " << event->scenePos().x() << std::endl;
    moveBy(event->scenePos().x() - event->lastScenePos().x(), event->scenePos().y() - event->lastScenePos().y());
    
    emit mouseMoveSignal(event);
}

void kIRNodeBase::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsObject::mouseReleaseEvent(event);
    std::cout << "mouse released " << isSelected() << " : " << event->scenePos().x() << std::endl;

    emit mouseReleaseSignal(event);
}

void kIRNodeBase::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    this->editorWindow->show();
    this->editorWindow->raise(); // mac
    this->editorWindow->activateWindow(); // windows??
    
    emit mouseDoubleClickSignal(event);
}*/

void kIRNodeBase::openEditorWindow()
{
    this->editorWindow->show();
    this->editorWindow->raise(); // mac
    this->editorWindow->activateWindow(); // windows??
}


void kIRNodeBase::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    
    QPen pen(isSelected()? Qt::darkRed : Qt::blue);
    pen.setColor(Qt::black);
    painter->setPen(pen);
    
    float x = this->frame.origin.x - this->frame.size.width/2;
    float y = this->frame.origin.y - this->frame.size.height/2;

    painter->drawRect(x, y, this->frame.size.width, this->frame.size.height);
    
    auto color = isSelected()? Qt::blue : Qt::lightGray;
    painter->fillRect(x, y, this->frame.size.width, this->frame.size.height, color);

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

kEditorWindow* kIRNodeBase::getEditorWindow()
{
    return this->editorWindow;
}

void kIRNodeBase::objSelectionChanged()
{
    
}

QVariant kIRNodeBase::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if(change == ItemSelectedChange) {
        std::cout << "item selected changed!! " << isSelected() <<  std::endl;
    }
    
    return QGraphicsObject::itemChange(change,value);
}

void kIRNodeBase::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::SHIFT:
            this->isEnableMultiSelection = true;
            break;
        
    }
}

void kIRNodeBase::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::SHIFT:
            this->isEnableMultiSelection = false;
            break;
            
    }
}


void kIRNodeBase::setObjPos(IR::Origin pos)
{
    setPos(pos.x, pos.y);
}

void kIRNodeBase::moveObjBy(IR::Origin pos)
{
    moveBy(pos.x - this->frame.origin.x, pos.y - this->frame.origin.y);
}


