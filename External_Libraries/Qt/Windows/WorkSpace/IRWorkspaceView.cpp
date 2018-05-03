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
    
    
    IR_Data::Type inputTypeArray [] = {
        IR_Data::IR_AY_FLT
    };
    
    IR_Data::Type outputTypeArray [] = {
        IR_Data::IR_AY_FLT
    };
    
    IR_Data::INOUTDATA inputDataType = IR_Data::INOUTDATA{1, inputTypeArray};
    IR_Data::INOUTDATA outputDataType = IR_Data::INOUTDATA{1, outputTypeArray};

    kNodeObject *obj = createObj(IR_Object::NONAME, objFrame, inputDataType,outputDataType);
    scene()->addItem(obj);
    scene()->update();
    
    
    
    
}

kNodeObject *IRWorkspaceView::createObj(IR_Object::Name name, IR::Frame objFrame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output)
{
    kNodeObject *obj = new kNodeObject(IR_Object::NONAME, objFrame, input, output);
    
    emit createObjSignal(name, objFrame);
    
    return obj;
}

void IRWorkspaceView::deleteObj()
{
    emit deleteObjSignal();
}

void IRWorkspaceView::copyObj(kNodeObject *node)
{
    emit copyObjSignal(node);
}

void IRWorkspaceView::pasteObj(IR::Frame objFrame)
{
    emit pasteObjSignal(objFrame);
}

void IRWorkspaceView::duplicateObj()
{
    emit duplicateObjSignal();
}





