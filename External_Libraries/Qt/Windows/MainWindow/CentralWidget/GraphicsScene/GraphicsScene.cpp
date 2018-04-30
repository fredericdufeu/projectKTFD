//
//  GraphicsScene.cpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 23/04/2018.
//

#include "GraphicsScene.hpp"
#include <QGraphicsSceneMouseEvent>
#include <QPainterPath>
#include <QTransform>
#include <iostream>

#include "GraphicsView.hpp"

GraphicsScene::GraphicsScene()
: QGraphicsScene()
{
    // selectionPainterPath;
}


GraphicsScene::~GraphicsScene()
{
    
}


GraphicsView* GraphicsScene::getView()
{
    return static_cast<GraphicsView*>(views()[0]);
}


void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    GraphicsView *view = getView();
    std::cout << "graphics scene mouse press event called (with mouse event): " << mouseEvent->pos().x() << ", " << mouseEvent->pos().y() << std::endl;
    std::cout << "graphics scene mouse press event called (with mPos field - raw): " << view->getMPos().x << ", " << view->getMPos().y << std::endl;
    std::cout << "graphics scene mouse press event called (with mPosScene field): " << view->getMPosScene().x << ", " << view->getMPosScene().y << std::endl;
    
    QPointF clickedPointInSceneCoords;
    clickedPointInSceneCoords.setX(view->getMPosScene().x);
    clickedPointInSceneCoords.setY(view->getMPosScene().y);
    
    if (itemAt(view->getMPosScene().x, view->getMPosScene().y, QTransform()))
    {
        // std::cout << "clicked on item" << std::endl;
    
        QGraphicsScene::mousePressEvent(mouseEvent); // ONLY CALL THE ORIGINAL IF THERE IS AN ITEM AT THIS COORD
    }
    else
    {
        // std::cout << "clicked nowhere" << std::endl;
        
        // Here, typically make selection rectangle or something like that
        
        // YOU PROBABLY NEED TO INVESTIGATE QGraphicsView::RubberBandDrag
        
        QPainterPath selectionAreaPath;
        selectionAreaPath.addRect(view->getMPosScene().x, view->getMPosScene().y, 20, 20);
        // QBrush brush(Qt::lightGray);
        // setBackgroundBrush(brush);
        // QBrush brush2(Qt::black);
        // setForegroundBrush(brush2);
        // set
        setSelectionArea(selectionAreaPath);
        
        update();
    }
}


void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    // std::cout << "indeed" << std::endl;
    GraphicsView *view = getView();
    double deltaX = mouseEvent->pos().x() - mouseEvent->lastPos().x();
    double deltaY = mouseEvent->pos().y() - mouseEvent->lastPos().y();
    QPainterPath selectionAreaPath;
    // selectionAreaPath.
    selectionAreaPath.addRect(0, 0, 100, 100);
    setSelectionArea(selectionAreaPath);
    // addPath(selectionAreaPath);
    update();
    
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}
