//
//  IRWorkspaceView.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/02.
//

#include "IRWorkspaceView.hpp"


IRWorkspaceView::IRWorkspaceView(QGraphicsScene *scene, QWidget *parent)
: QGraphicsView(scene, parent)
{
    setAcceptDrops(true);
    
    std::cout << "workspace view size = " << this->width() << ", " << this->height() << std::endl;
}

IRWorkspaceView::~IRWorkspaceView()
{
    
}

void IRWorkspaceView::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
    std::cout << "dragEnterEvent \n"<< std::endl;
}

void IRWorkspaceView::dragMoveEvent(QDragMoveEvent *event)
{
    std::cout << "dragMoveEvent \n"<< std::endl;
    this->mPos.x = event->pos().x();
    this->mPos.y = event->pos().y();
    
}

void IRWorkspaceView::dropEvent(QDropEvent *event)
{
    event->acceptProposedAction();
    std::cout << "drop Event \n"<< std::endl;
    
    QPoint pointInViewCoordinates = event->pos();
    QPointF pointInSceneCoordinates = mapToScene(pointInViewCoordinates);
    
    struct IR::Frame objFrame = { { static_cast<float>(pointInSceneCoordinates.x()), static_cast<float>(pointInSceneCoordinates.y()) }, {150, 40} };
    
    kNodeObject *obj = new kNodeObject(IR_Object::NOTYPE, IR_Object::NONAME, objFrame);
    scene()->addItem(obj);
    scene()->update();
    
}


