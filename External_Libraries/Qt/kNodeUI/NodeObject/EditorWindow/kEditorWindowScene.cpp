//
//  kEditorWindowScene.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/30.
//

#include "kEditorWindowScene.hpp"

kEditorWindowScene::kEditorWindowScene(QWidget *parent)
: QGraphicsScene(parent)
{
    this->parent = parent;
}

kEditorWindowScene::~kEditorWindowScene()
{
    
}
