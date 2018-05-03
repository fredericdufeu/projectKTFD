//
//  IRGraphicsView.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#include "IRGraphicsView.hpp"


IRGraphicsView::IRGraphicsView(QGraphicsScene *scene, QWidget *parent)
: QGraphicsView(scene, parent)
{
    setAcceptDrops(false);
}

IRGraphicsView::~IRGraphicsView()
{
    
}


void IRGraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
    std::cout << "dragEnterEvent \n"<< std::endl;
}

void IRGraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
    std::cout << "dragMoveEvent \n"<< std::endl;
    this->mPos.x = event->pos().x();
    this->mPos.y = event->pos().y();

}

void IRGraphicsView::dropEvent(QDropEvent *event)
{
    //event->acceptProposedAction();
    //std::cout << "drop Event \n"<< std::endl;
    
   

}
