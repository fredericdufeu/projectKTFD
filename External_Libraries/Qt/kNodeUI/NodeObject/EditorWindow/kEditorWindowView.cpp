//
//  kEditorWindowView.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/04.
//

#include "kEditorWindowView.hpp"

kEditorWindowView::kEditorWindowView(QGraphicsScene *scene, QWidget *parent)
: IRWorkspaceView(scene, parent)
{
    setAcceptDrops(true);
}

kEditorWindowView::~kEditorWindowView()
{
    
}
