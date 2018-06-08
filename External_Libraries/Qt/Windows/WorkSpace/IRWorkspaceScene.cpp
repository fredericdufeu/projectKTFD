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
    
    if(this->key_ctrl_press_flag){
        createPopUpWindow(QCursor::pos());
        this->key_ctrl_press_flag = false;
    }else{
        
        this->mouse_down_flag = true;

        // ==========
        //  check if this action selects any objects.
        // ==========
        calcSelectedObjecsts();
        if(isSelected()) { // if any objects are selected, then we do not have selection square.
            this->isSelectionAreaSquareFlag = false;
        }else { // if no objects are selected, then we draw selection square.
            this->isSelectionAreaSquareFlag = true;
        }
        
       
        
        // store button down scene position here.
        event->setButtonDownScenePos(Qt::MouseButton::LeftButton, event->scenePos());
    }

}

void IRWorkspaceScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
    
    this->currentMousePos.origin.x = event->pos().x();
    this->currentMousePos.origin.y = event->pos().x();

    
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
        
        if(selectedFrame.size.width != 0 && selectedFrame.size.height != 0){
            std::cout << "selection\n";
            emit areaSelectionSignal(selectedFrame);
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
        if(this->isSelectedFlag) { // if any objects are selected.
            //get selected objects
            calcSelectedObjecsts();
            if(this->selectedObject[0] != nullptr) {
                //this->selectedObject[0]->openEditorWindow();
                // retrieve editor window from dataabse.
                std::string id = this->selectedObject[0]->getUniqueId();
                emit openEditorWindowSignal(id);
            }
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
void IRWorkspaceScene::createObj(IR_Object::Name name, IR::Frame objFrame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output)
{
    
    IRWaveformNodeObject *obj = new IRWaveformNodeObject(name, objFrame, input, output, this);

    //register to the database
    //this->database->registerObjToDatabase(obj->getUniqueId(), obj);
    //add
    addItem(obj);
    update();
    
    //show database
    //this->database->showDatabase();
    emit createObjSignal(obj);

}

void IRWorkspaceScene::createObj2(IR_Object::Name name, IR::Frame objFrame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output)
{
    
    IRSpectrumNodeObject *obj = new IRSpectrumNodeObject(name, objFrame, input, output, this);
    
    //register to the database
    //this->database->registerObjToDatabase(obj->getUniqueId(), obj);
    //add
    addItem(obj);
    update();
    
    //show database
    //this->database->showDatabase();
    emit createObjSignal(obj);
    
}

void IRWorkspaceScene::createObj(kNodeObject *obj)
{
    //register to the database
    //this->database->registerObjToDatabase(obj->getUniqueId(), obj);
    //add
    addItem(obj);
    update();
    emit createObjSignal(obj);
}


void IRWorkspaceScene::deleteObj()
{
    std::cout << "delete obj in scene \n";
    
    calcSelectedObjecsts();
    for(auto item: this->selectedObject) {
        //deregister from the database
        //this->database->removeObjFromDatabase(item->getUniqueId());
        emit deleteObjSignal(item->getUniqueId());

        removeItem(item);
        delete item;
    }
    //this->database->showDatabase();

}

void IRWorkspaceScene::copyObj()
{
    calcSelectedObjecsts();
    this->copiedObj.clear();
    for(auto item: this->selectedObject) {
        
        this->copiedObj.push_back(static_cast<kNodeObject* >(item));
    }
    emit copyObjSignal(this->copiedObj);
}

void IRWorkspaceScene::pasteObj()
{
    
    /* unselect all object */
    unselectAll();
    /* duplicate copied objects */
    for(auto item: this->copiedObj) {
        auto name = item->getObjectName();
        auto objFrame = item->getFrame();
        // shift object a bit upper left
        objFrame.origin.x += 25;
        objFrame.origin.y += 25;
        auto input = item->getInputDataType();
        auto output = item->getOutputDataType();
        //create new object here.
        kNodeObject *obj = new kNodeObject(name,objFrame,input,output, this);
        // change the status of duplicated objects to selected.
        obj->setSelected(true);
        // change the status of original objects to unselected
        item->setSelected(false);
        createObj(obj);
    }
    // when the paste process completes, we copy items selected through the process which are the newly duplicated objects.
    // this process is aimed to store the coordinates of newly created objects for the case we continuously paste the same copied objects.
    // otherwise, we paste end up with pasting multiple objects at the exactly same coordinates.
    copyObj();
    
    emit pasteObjSignal();
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
        kNodeObject *obj = new kNodeObject(name,objFrame,input,output, this);
        // change the status of duplicated objects to selected.
        obj->setSelected(true);
        // change the status of original objects to unselected
        item->setSelected(false);
        createObj(obj);
    }
    emit duplicateObjSignal();
}

void IRWorkspaceScene::copyDeleteObj()
{
    copyObj();
    deleteObj();
    emit copyDeleteObjSignal();
}

void IRWorkspaceScene::selectAllObj()
{
    emit selectAllObjSignal();
}

void IRWorkspaceScene::unselectAll()
{
    emit unselectAllObjSignal();
}


/* event */
void IRWorkspaceScene::keyPressEvent(QKeyEvent *event)
{
    
    std::cout << "key pressed! in view " << event->key() << " : alt option " << Qt::Key_Control << std::endl;
    
    std::cout <<  " c = " << Qt::Key_C << " d = " << Qt::Key_D << " v = " << Qt::Key_V << std::endl;
    
    switch (event->key())
    {
        case Qt::Key_Delete:
        case 16777219:
            deleteObj();
            break;
        case Qt::Key_A:
            if(this->key_ctrl_press_flag) { selectAllObj(); }
            break;
        case Qt::Key_C:
            if(this->key_ctrl_press_flag) { copyObj(); }
            break;
        case Qt::Key_D:
            if(this->key_option_press_flag || this->key_ctrl_press_flag) { duplicateObj(); }
            break;
        case Qt::Key_R:
            if(this->key_ctrl_press_flag) { executeObj(); }
            break;
        case Qt::Key_V:
            if(this->key_ctrl_press_flag) { pasteObj();}
            break;
        case Qt::Key_X:
            //if(this->key_ctrl_press_flag) { copyDeleteObj(); }
            break;
        case Qt::Key_Option:
        case Qt::Key_Alt:
            this->key_option_press_flag = true;
            break;
        case Qt::Key_Control:
        case 16777250:
            this->key_ctrl_press_flag = true;
            break;
        default:
            break;
    }
}


void IRWorkspaceScene::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Option:
        case Qt::Key_Alt:
            this->key_option_press_flag = false;
            break;
        case Qt::Key_Control:
        case 16777250:
            this->key_ctrl_press_flag = false;
            break;
        default:
            break;
    }
}

void IRWorkspaceScene::executeObj()
{
    std::cout << "IRWorkspaceScene executeObj()\n";
    emit executeObjSignal();
}

void IRWorkspaceScene::createPopUpWindow(QPointF pos)
{
    QWidget *popup = new QWidget(0);
    popup->setWindowOpacity(0.7);
    popup->setWindowFlag(Qt::Popup);
    int w = 260; int h = 480;
    popup->resize(w, h);
    popup->move(pos.x(), pos.y());
    popup->show();
    
}

