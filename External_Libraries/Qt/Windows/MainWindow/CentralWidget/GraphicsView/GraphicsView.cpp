//
//  GraphicsView.cpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 23/04/2018.
//

#include "GraphicsView.hpp"
#include <iostream>
#include <string>
#include <QAbstractItemView>
#include <QMimeData>
#include <QString>

#include "SoundNodeObject.hpp"

#include <QWidget>

#include "CentralWidget.hpp"

#include "kNodeUI.h"
#include "IRUtilities.hpp"


GraphicsView::GraphicsView(GraphicsScene *scene, QWidget *parent)
: QGraphicsView(scene, parent)
{
    this->parent = parent;
    //parentCentralWidget = static_cast<CentralWidget *>(parent);
    
    setAcceptDrops(true);
    // setDragDropMode(QAbstractItemView::DragDrop);
}


GraphicsView::~GraphicsView()
{
    
}


void GraphicsView::dragEnterEvent(QDragEnterEvent *event) // THIS WORKS
{
    // std::cout << "entered drag event..." << std::endl;
    event->acceptProposedAction();
}


void GraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
    std::cout << "mainView mousePosition : " << event->pos().x() << " , " << event->pos().y() << std::endl;
    this->mPos.x = event->pos().x();
    this->mPos.y = event->pos().y();
}


void GraphicsView::dropEvent(QDropEvent *event)
{
    event->acceptProposedAction();
    
    std::string path(event->mimeData()->text().toStdString());
    
    scene();
    QPoint pointInViewCoordinates = event->pos();
    QPointF pointInSceneCoordinates = mapToScene(pointInViewCoordinates);
    
    std::cout << "drop coordonates (view): " << event->pos().x() << ", " << event->pos().y() << "\n";
    std::cout << "drop coordonates (scene): " << pointInSceneCoordinates.x() << ", " << pointInSceneCoordinates.y() << "\n";
    
    // int index = parentCentralWidget->database->numSoundNodes;
    
    
 /*
    // NodeObject *nodeObject = new NodeObject(path)
    SoundNodeObject *soundNodeObject = new SoundNodeObject(path);
    
    // NOW, I WANT TO PUT IT WHERE I HAVE DROPPED IT.
    
    std::cout << "dropped at " << event->pos().x() << ", " << event->pos().y() << std::endl;
    // THIS IS RELATIVE TO THE WIDGET
    
    soundNodeObject->graphicsItem->setPos(0, index * 100);
    
    parentCentralWidget->database->soundNodes[parentCentralWidget->database->numSoundNodes] = *soundNodeObject;
    parentCentralWidget->database->numSoundNodes++;
    
    std::cout << "num sound nodes is now " << parentCentralWidget->database->numSoundNodes << std::endl;
    
     
    scene()->addItem(soundNodeObject->graphicsItem);
   */
    
    struct IR::Frame objFrame = { { static_cast<float>(pointInSceneCoordinates.x()), static_cast<float>(pointInSceneCoordinates.y()) }, {150, 40} };
    kNodeObject *obj = new kNodeObject(IR_Object::NOTYPE, IR_Object::NONAME, objFrame);
    scene()->addItem(obj);
    scene()->update();
     
    //std::cout << "object position = " << obj->getFrame().origin.x << " , " << obj->getFrame().origin.y << " set by mouse position " << this->mPos.x << " , " << this->mPos.y << std::endl;
}

