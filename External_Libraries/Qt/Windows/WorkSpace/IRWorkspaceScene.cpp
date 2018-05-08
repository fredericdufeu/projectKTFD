//
//  IRWorkspaceScene.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/02.
//

#include "IRWorkspaceScene.hpp"

IRWorkspaceScene::IRWorkspaceScene(QWidget *parent)
: QGraphicsScene(parent)
{
    setSceneRect(-2500, -2500, 5000, 5000);
}

IRWorkspaceScene::~IRWorkspaceScene()
{
    
}

void IRWorkspaceScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
    std::cout << "mouse pressed in scene!" << std::endl;
    
    calcSelectedObjecsts();
    
}

void IRWorkspaceScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "mouse move in scene!" << std::endl;
    QGraphicsScene::mouseMoveEvent(event);

}

void IRWorkspaceScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
    std::cout << "mouse release in scene!" << std::endl;
    
}

void IRWorkspaceScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseDoubleClickEvent(event);
    
    // remove all double click events when any keys are pressed!!
    if(!event->modifiers()){
        std::cout << "mouse double click in scene!" << std::endl;
        
        calcSelectedObjecsts();
        if(this->selectedObject[0] != nullptr) {
            this->selectedObject[0]->openEditorWindow();
        }
    }
}

std::vector<kNodeObject* > IRWorkspaceScene::getSelectedObjects()
{
    return this->selectedObject;
}

void IRWorkspaceScene::calcSelectedObjecsts()
{
    QList<QGraphicsItem* > list = QGraphicsScene::selectedItems();
    this->selectedObject.clear();
    for(auto item: list) {
        this->selectedObject.push_back(static_cast<kNodeObject* >(item));
    }
}

void IRWorkspaceScene::deleteObj()
{
    std::cout << "delete obj in scene \n";

    calcSelectedObjecsts();
    for(auto item: this->selectedObject) {
        removeItem(item);
        delete item;
    }
    emit deleteObjSignal();
}

void IRWorkspaceScene::copyObj(kNodeObject *node)
{
    emit copyObjSignal(node);
}

void IRWorkspaceScene::pasteObj(IR::Frame objFrame)
{
    emit pasteObjSignal(objFrame);
}

void IRWorkspaceScene::duplicateObj()
{
    emit duplicateObjSignal();
}

/* event */
void IRWorkspaceScene::keyPressEvent(QKeyEvent *event)
{
    std::cout << "key pressed! in view " << event->key() << std::endl;
    switch (event->key())
    {
        case Qt::Key_Delete:
        case 16777219:
            deleteObj();
            break;
        case Qt::Key_S:
            break;
    }
}

void IRWorkspaceScene::keyReleaseEvent(QKeyEvent *event)
{
    
}


