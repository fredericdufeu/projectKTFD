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
    this->database = new NodeDatabase();
    
    this->selectionAreaSquare = new IRSelectionAreaSquare();
    addItem(this->selectionAreaSquare);
    

}

IRWorkspaceScene::~IRWorkspaceScene()
{
    delete this->selectionAreaSquare;
}

void IRWorkspaceScene::setSelectionAreaSquare(bool flag)
{
    this->isSelectionAreaSquareFlag = flag;
}

void IRWorkspaceScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
    this->mouse_down_flag = true;
    
    calcSelectedObjecsts();
    if(isSelected()) {
        this->isSelectionAreaSquareFlag = false;
    }else { this->isSelectionAreaSquareFlag = true; }
    
    
    event->setLastScenePos(event->scenePos());
    
    event->setButtonDownScenePos(Qt::MouseButton::LeftButton, event->scenePos());

}

void IRWorkspaceScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
    
    
    if(this->isSelectionAreaSquareFlag && this->mouse_down_flag) {
        //std::cout << "button down position = " << event->buttonDownScenePos(Qt::MouseButton::LeftButton).x() << ", " <<event->buttonDownScenePos(Qt::MouseButton::LeftButton).y() << " : " << event->scenePos().x() << ", " << event->scenePos().y() << std::endl;
        this->selectionAreaSquare->drawSelectionArea( event->buttonDownScenePos(Qt::MouseButton::LeftButton), event->scenePos());
        update();
    }
    

}

void IRWorkspaceScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
    this->mouse_down_flag = false;
    // erase selectionAreaSquare
    if(this->isSelectionAreaSquareFlag) {
        IR::Frame selectedFrame = this->selectionAreaSquare->getFrameSize();
        
        for(auto item:this->database->getDatabase()){
            
            //std::cout << "square frame " << selectedFrame.origin.x << ", " << selectedFrame.origin.y << " : node frame " << item.second->getFrame().origin.x << ", " << item.second->getFrame().origin.y << "\n";
            
            std::cout << "selected area\n";
            selectedFrame.show();
            std::cout << "node area\n";

            item.second->getFrame().show();
            
            
            if(selectedFrame.isFrameOverlap(item.second->getFrame())){
                item.second->setSelected(true);
            }
        }
        
        this->selectionAreaSquare->deleteSquare();
        update();
        
    }
    
}

void IRWorkspaceScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseDoubleClickEvent(event);
    
    // remove all double click events when any keys are pressed!!
    if(!event->modifiers()){
        //get selected objects
        calcSelectedObjecsts();
        
        if(this->selectedObject[0] != nullptr) {
            this->selectedObject[0]->openEditorWindow();
        }
    }
}

std::vector<kNodeObject* > IRWorkspaceScene::getSelectedObjects()
{
    //get selected objects
    calcSelectedObjecsts();
    return this->selectedObject;
}

void IRWorkspaceScene::calcSelectedObjecsts()
{
    QList<QGraphicsItem* > list = QGraphicsScene::selectedItems();
    this->selectedObject.clear();
    this->isSelectedFlag = false;
    for(auto item: list) {
        this->isSelectedFlag = true;
        this->selectedObject.push_back(static_cast<kNodeObject* >(item));
    }
}
bool IRWorkspaceScene::isSelected()
{
    return this->isSelectedFlag;
}
void IRWorkspaceScene::createObj(kNodeObject *obj)
{
    //register to the database
    this->database->registerObjToDatabase(obj->getUniqueId(), obj);
    //add
    addItem(obj);
    update();
    
    //show database
    this->database->showDatabase();
}

void IRWorkspaceScene::deleteObj()
{
    std::cout << "delete obj in scene \n";
    
    calcSelectedObjecsts();
    for(auto item: this->selectedObject) {
        //deregister from the database
        this->database->removeObjFromDatabase(item->getUniqueId());
        removeItem(item);
        delete item;
    }
    this->database->showDatabase();

    emit deleteObjSignal();
}

void IRWorkspaceScene::copyObj(kNodeObject *node)
{
    
    calcSelectedObjecsts();
    emit copyObjSignal(node);
}

void IRWorkspaceScene::pasteObj(IR::Frame objFrame)
{
    emit pasteObjSignal(objFrame);
}

void IRWorkspaceScene::duplicateObj()
{
    std::cout << "duplicate obj " << std::endl;
    
    calcSelectedObjecsts();
    for(auto item: this->selectedObject) {
        
        auto name = item->getObjectName();
        auto objFrame = item->getFrame();
        // shift object a bit upper left
        objFrame.origin.x += 25;
        objFrame.origin.y -= 25;
        auto input = item->getInputDataType();
        auto output = item->getOutputDataType();
        //create new object here.
        kNodeObject *obj = new kNodeObject(name,objFrame,input,output);
        // change the status of duplicated objects to selected.
        obj->setSelected(true);
        // change the status of original objects to unselected
        item->setSelected(false);
        createObj(obj);
        
    }

    
    emit duplicateObjSignal();
}

/* event */
void IRWorkspaceScene::keyPressEvent(QKeyEvent *event)
{
    std::cout << "key pressed! in view " << event->key() << " : alt option " << Qt::Key_Option << std::endl;
    switch (event->key())
    {
        case Qt::Key_Delete:
        case 16777219:
            deleteObj();
            break;
        case Qt::Key_S:
            
        case Qt::Key_D:
            if(this->key_option_press_flag) {duplicateObj();}
            break;
        case Qt::Key_Option:
        case Qt::Key_Alt:
            this->key_option_press_flag = true;
            break;
            break;
    }
}


void IRWorkspaceScene::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Option:
            this->key_option_press_flag = false;
            break;
    }
}


