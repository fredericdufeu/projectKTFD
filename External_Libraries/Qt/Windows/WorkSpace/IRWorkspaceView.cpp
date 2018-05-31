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
    this->setMouseTracking(true);
}

IRWorkspaceView::~IRWorkspaceView()
{
    
}

void IRWorkspaceView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
    //IRWorkspaceScene *sc = static_cast<IRWorkspaceScene* >(scene());
    //sc->mouseMoveSceneEvent(event);
    
}

void IRWorkspaceView::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
    std::cout << "dragEnterEvent \n"<< std::endl;
}

void IRWorkspaceView::dragMoveEvent(QDragMoveEvent *event)
{
    this->mPos.x = event->pos().x();
    this->mPos.y = event->pos().y();
}

//# Drop Event
void IRWorkspaceView::dropEvent(QDropEvent *event)
{
    event->acceptProposedAction();
    std::cout << "drop Event \n"<< std::endl;
    
    // File Path received from dropped file.
    std::string path(event->mimeData()->text().toStdString());
    
    // get a view coordinate of the dropped file.
    QPoint pointInViewCoordinates = event->pos();
    // convert View coordinate to scene coordinate
    QPointF pointInSceneCoordinates = mapToScene(pointInViewCoordinates);
    
    // get a file type
    IRFileUtility fileUtility = IRFileUtility();
    auto fileformat = fileUtility.checkFileType(path);
    
    std::cout << "filename : " << path << " loading... : file format is " << fileformat.format << std::endl;
    struct IR::Frame objFrame = { { static_cast<float>(pointInSceneCoordinates.x()), static_cast<float>(pointInSceneCoordinates.y()) }, {150, 40} };

    //# call appripriate method depending on the file format.
    //# this process is only the case when any files are droped in a workspace.
    switch (fileformat.type)
    {
        case IR_FILE::FILETYPE::AUDIO:
            //createAudioObj(objFrame);
            createWaveformObj(objFrame); // Call createWaveformObj();
            break;
        case IR_FILE::FILETYPE::IMAGE:
            break;
        case IR_FILE::FILETYPE::MOVIE:
            break;
        case IR_FILE::FILETYPE::SCORE:
            
        default:
            break;

    }
}
// ## ==============================================================
// ##
// ## This method is just for testing Waveform Node Object. ENJOY!
// ##
// ## ==============================================================

void IRWorkspaceView::createWaveformObj(IR::Frame objFrame)
{
    IR_Data::Type inputTypeArray [] = {
        IR_Data::IR_URL, // url of an audio file
        IR_Data::IR_INT32, // begining sample index of the audio data (0 <= begin < end )
        IR_Data::IR_INT32 // ending sample index of the audio data ( end < samples )
    };
    
    IR_Data::Type outputTypeArray [] = {
        IR_Data::IR_AY_FLT // audio data array
    };
    
    IR_Data::INOUTDATA inputDataType = IR_Data::INOUTDATA{3, inputTypeArray};
    IR_Data::INOUTDATA outputDataType = IR_Data::INOUTDATA{1, outputTypeArray};
    
    // give a name of the node object
    IR_Object::Name name = "IRWaveform sample.wav 44100 88200";
    // create object
    createObj(name, objFrame, inputDataType, outputDataType);
    
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
    

    IR_Object::Name name = "This is IRiMaS Node Object!!";
    
    createObj(name, objFrame, inputDataType, outputDataType);
    
}

void IRWorkspaceView::createObj(IR_Object::Name name, IR::Frame objFrame, IR_Data::INOUTDATA input, IR_Data::INOUTDATA output)
{
    //kNodeObject *obj = new kNodeObject(name, objFrame, input, output);
    static_cast<IRWorkspaceScene* >(scene())->createObj(name,objFrame,input,output);
    
    emit createObjSignal(name, objFrame);
    
}


