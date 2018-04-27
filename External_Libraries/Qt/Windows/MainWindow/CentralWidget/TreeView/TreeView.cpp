//
//  TreeView.cpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 23/04/2018.
//

#include <iostream>

#include "TreeView.hpp"
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QApplication>
#include <QAbstractItemView>
#include <QFileSystemModel>

TreeView::TreeView(QWidget *parent)
: QTreeView(parent)
{
    setDragDropMode(QAbstractItemView::DragDrop);
}


TreeView::~TreeView()
{
    
}


void TreeView::mousePressEvent(QMouseEvent *event)
{
    
    // create a drag event here
    
    // QDrag *drag = new QDrag(this);
    
    // Qt::DropAction dropAction = drag->exec();
    
    clickedIndex = indexAt(event->pos());
    clickedFileName = static_cast<QFileSystemModel *>(model())->fileName(clickedIndex);
    clickedFilePath = static_cast<QFileSystemModel *>(model())->filePath(clickedIndex);
    // std::cout << "row: "  << clickedIndex.row() << std::endl;
    // std::cout << "name: "  << clickedFileName.toStdString() << std::endl;
    
    dragStartPosition = event->pos();
    
    QTreeView::mousePressEvent(event); // call the base class
}


void TreeView::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->pos() - dragStartPosition).manhattanLength() < QApplication::startDragDistance())
    {
        QTreeView::mouseMoveEvent(event);
    }
    else
    {
        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;
        
        // now, need to get "information" on the item clicked
        
        // mimeData->setData
        
        mimeData->setText(clickedFilePath);
        
        drag->setMimeData(mimeData); // does not carry any data for now, but let us see
        
        Qt::DropAction dropAction = drag->exec(Qt::MoveAction | Qt::CopyAction);
    }
}
























