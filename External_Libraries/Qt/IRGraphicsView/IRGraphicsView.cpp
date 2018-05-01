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
    setAcceptDrops(true);
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

}

void IRGraphicsView::dropEvent(QDropEvent *event)
{
    std::cout << "drop Event \n"<< std::endl;

}
