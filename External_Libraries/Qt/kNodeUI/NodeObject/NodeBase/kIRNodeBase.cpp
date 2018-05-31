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
    
    //this->editorWindow = new kEditorWindow(0);
    
    // Give ItemSendsGeometryChanges to receive signal when item position has changed. see itemChange()
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemSendsGeometryChanges);
    
    // set Z order value : 0 is buttom
    setZValue(0);
    
}

kIRNodeBase::~kIRNodeBase()
{
}

void kIRNodeBase::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsObject::mousePressEvent(event);
}

void kIRNodeBase::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsObject::mouseMoveEvent(event);

}

void kIRNodeBase::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsObject::mouseReleaseEvent(event);

}

void kIRNodeBase::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsObject::mouseDoubleClickEvent(event);
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
    return this->frame.origin.x + pos().x();
}

int kIRNodeBase::getY(){
    return this->frame.origin.y + pos().y();
}

IR::Frame kIRNodeBase::getFrameSize()
{
    IR::Frame objFrame = IR::Frame{ {this->frame.origin.x + static_cast<float>(pos().x()), this->frame.origin.y + static_cast<float>(pos().y())} , this->frame.size};
    return objFrame;
    //return this->frame;
}

void kIRNodeBase::setFrameSize(IR::Frame frame)
{
    setX(0);
    setY(0);
    
    this->frame = frame;
    update();
}

void kIRNodeBase::setOrigin(IR::Origin origin)
{
    this->frame.origin = origin;
    update();
}

void kIRNodeBase::openEditorWindow()
{
    /*
    this->editorWindow->show();
    this->editorWindow->raise(); // mac
    this->editorWindow->activateWindow(); // windows??
     */
}
/*

kEditorWindow* kIRNodeBase::getEditorWindow()
{
    return this->editorWindow;
}*/

void kIRNodeBase::objSelectionChanged()
{
    if(isSelected()){
        setZValue(1.0);
    }else{
        setZValue(0.0);
    }
}

QVariant kIRNodeBase::itemChange(GraphicsItemChange change, const QVariant &value)
{
    //std::cout << "itemchange() : " << change << " : "<< std::endl;
    //std::cout << "selectedChange = " << QGraphicsItem::ItemSelectedChange << " : positionHasChanged = " << QGraphicsItem::ItemPositionHasChanged << " : ItemTransformHasChanged = " << QGraphicsItem::ItemTransformHasChanged << std::endl;

    switch (change) {
        case QGraphicsItem::ItemSelectedChange:
            std::cout << "item selected changed!! " << isSelected() <<  std::endl;
            if(isSelected()) { setZValue(0.0); } // if selected return Z Index
            else { setZValue(1.0); }
            break;
        case QGraphicsItem::ItemPositionChange:
            //std::cout << "item position changed!! " << isSelected() <<  std::endl;
            break;
        case QGraphicsItem::ItemPositionHasChanged: {
            //std::cout << "item position has changed!! to " << isSelected() <<  std::endl;
            break;
        }
        default:
            break;
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



