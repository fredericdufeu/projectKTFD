//
//  IRWorkspaceView.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/02.
//

#include "IRWorkspaceView.hpp"


IRWorkspaceView::IRWorkspaceView(QGraphicsScene *scene, QWidget *parent)
: QGraphicsView(scene, parent)
{
    setAcceptDrops(true);
    std::cout << "workspace view size = " << this->width() << ", " << this->height() << std::endl;
    
    
}

IRWorkspaceView::~IRWorkspaceView()
{
    
}



void IRWorkspaceView::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
    std::cout << "dragEnterEvent \n"<< std::endl;
}

void IRWorkspaceView::dragMoveEvent(QDragMoveEvent *event)
{
    std::cout << "dragMoveEvent \n"<< std::endl;
    this->mPos.x = event->pos().x();
    this->mPos.y = event->pos().y();
    
}

void IRWorkspaceView::dropEvent(QDropEvent *event)
{
    event->acceptProposedAction();
    std::cout << "drop Event \n"<< std::endl;
    
    std::string path(event->mimeData()->text().toStdString());
    
    QPoint pointInViewCoordinates = event->pos();
    QPointF pointInSceneCoordinates = mapToScene(pointInViewCoordinates);
    
    /* get file type */
    IRFileUtility fileUtility = IRFileUtility();
    auto fileformat = fileUtility.checkFileType(path);
    
    std::cout << "filename : " << path << " loading... : file format is " << fileformat.format << std::endl;
    struct IR::Frame objFrame = { { static_cast<float>(pointInSceneCoordinates.x()), static_cast<float>(pointInSceneCoordinates.y()) }, {150, 40} };

    
    switch (fileformat.type)
    {
        case IR_FILE::FILETYPE::AUDIO:
            createAudioObj(objFrame);
            break;
            
        case IR_FILE::FILETYPE::IMAGE:
            break;
        default:
            break;
            /*

        case IR_FILE::FILETYPE::IMAGE:
            break;
        case IR_FILE::FILETYPE::MOVIE:
            break;
        default:
            break;
             */
    }
}

void IRWorkspaceView::createAudioObj(IR::Frame objFrame)
{
    IR_Data::Type inputTypeArray [] = {
        IR_Data::IR_AY_FLT,
        IR_Data::IR_INT32, // begining
        IR_Data::IR_INT32 // end
    };
    
    IR_Data::Type outputTypeArray [] = {
        IR_Data::IR_AY_FLT
    };
    
    IR_Data::INOUTDATA inputDataType = IR_Data::INOUTDATA{3, inputTypeArray};
    IR_Data::INOUTDATA outputDataType = IR_Data::INOUTDATA{1, outputTypeArray};
    
    createObj(IR_Object::NONAME, objFrame, inputDataType, outputDataType);
    
}

void IRWorkspaceView::createObj(IR_Object::Name name, IR::Frame objFrame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output)
{
    kNodeObject *obj = new kNodeObject(IR_Object::NONAME, objFrame, input, output);
    
    static_cast<IRWorkspaceScene* >(scene())->createObj(obj);
    
    emit createObjSignal(name, objFrame);
    
}

void IRWorkspaceView::copyObj()
{
    //get selected obj
    std::vector<kNodeObject* >selectedObj = static_cast<IRWorkspaceScene* >(scene())->getSelectedObjects();
    if(selectedObj[0] != nullptr) {
        
        for(auto obj : selectedObj) {
            
        }
        
    }
    
}


void IRWorkspaceView::deleteObj()
{
    
}




