#include "EditorWindowGraphicsView.hpp"
#include "EditorWindowGraphicsScene.hpp"
#include <iostream>
#include <string>
#include <QAbstractItemView>
#include <QMimeData>
#include <QString>

#include "SoundNodeObject.hpp"

#include <QWidget>

#include "CentralWidget.hpp"


EditorWindowGraphicsView::EditorWindowGraphicsView(EditorWindowGraphicsScene *scene, QWidget *parent)
: QGraphicsView(scene, parent)
{
    
}


EditorWindowGraphicsView::~EditorWindowGraphicsView()
{
    
}



