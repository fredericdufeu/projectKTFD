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


GraphicsView::GraphicsView(GraphicsScene *scene, QWidget *parent)
: QGraphicsView(scene, parent)
{
    parentCentralWidget = static_cast<CentralWidget *>(parent);
    
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
    
}


void GraphicsView::dropEvent(QDropEvent *event)
{
    event->acceptProposedAction();
    
    std::string path(event->mimeData()->text().toStdString());
    
    int index = parentCentralWidget->database->numSoundNodes;
    
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
}

