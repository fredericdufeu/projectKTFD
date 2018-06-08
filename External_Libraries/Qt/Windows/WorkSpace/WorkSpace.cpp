//
//  WorkSpace.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#include "WorkSpace.hpp"


WorkSpace::WorkSpace(QWidget *parent)
: QWidget(parent)
{
    
    std::cout << "workspace made" << std::endl;
    
    this->database = new NodeDatabase();
    
    this->layout = new QHBoxLayout(this);
    this->workspaceScene = new IRWorkspaceScene(this);
    this->workspaceView = new IRWorkspaceView(this->workspaceScene, this);
    this->layout->addWidget(this->workspaceView,5);
    /*
    this->InspectorScene = new IRGraphicsScene(this);
    this->InspectorView = new IRGraphicsView(this->InspectorScene,this);
    this->layout->addWidget(this->InspectorView,1);
     */
    
    this->layout->setSpacing(4);
    this->layout->setContentsMargins(4, 4, 4, 4);   
    
    QObject::connect(this->workspaceScene, SIGNAL(createObjSignal(kNodeObject*)), this, SLOT(createObj(kNodeObject*)));
    QObject::connect(this->workspaceScene, SIGNAL(deleteObjSignal(std::string)), this, SLOT(deleteObj(std::string)));
    QObject::connect(this->workspaceScene, SIGNAL(copyObjSignal(kNodeObject*)), this, SLOT(copyObj(kNodeObject*)));
    QObject::connect(this->workspaceScene, SIGNAL(copyDeleteObjSignal(std::vector<kNodeObject*>)), this, SLOT(copyDeleteObj(std::vector<kNodeObject*>)));
    QObject::connect(this->workspaceScene, SIGNAL(pasteObjSignal()), this, SLOT(pasteObj(kNodeObject*)));
    QObject::connect(this->workspaceScene, SIGNAL(duplicateObjSignal()), this, SLOT(duplicateObj()));
    QObject::connect(this->workspaceScene, SIGNAL(selectAllObjSignal()), this, SLOT(selectAllObj()));
    QObject::connect(this->workspaceScene, SIGNAL(unselectAllObjSignal()), this, SLOT(unselectAllObj()));
    QObject::connect(this->workspaceScene, SIGNAL(areaSelectionSignal(IR::Frame)), this, SLOT(areaSelection(IR::Frame)));
    QObject::connect(this->workspaceScene, SIGNAL(openEditorWindowSignal(std::string)), this, SLOT(openEditorWindow(std::string)));

}

WorkSpace::~WorkSpace()
{
    
}



IRWorkspaceView *WorkSpace::getView() const
{
    return this->workspaceView;
}

IRWorkspaceScene *WorkSpace::getScene() const
{
    return this->workspaceScene;
}


//#
//# These functions are called when SIGNALs generated in IRWorkspaceScene
//#

void WorkSpace::createObj(kNodeObject *obj)
{
    std::cout << "WorkSpace createObj called!\n";
    //create editor window
    QString title = QString::fromStdString(obj->getObjectName().getValue());
    kEditorWindow *win = new kEditorWindow(title, 0);
    this->database->registerObjToDatabase(obj->getUniqueId(), obj, win);
    //show database
    this->database->showDatabase();
}
void WorkSpace::deleteObj(std::string id)
{
    std::cout << "WorkSpace deleteObj called!\n";

    this->database->removeObjFromDatabase(id);
    //show database
    this->database->showDatabase();
}
void WorkSpace::copyObj()
{
    
}
void WorkSpace::copyDeleteObj()
{
    
}
void WorkSpace::pasteObj()
{
    
}
void WorkSpace::duplicateObj()
{
    
}
void WorkSpace::selectAllObj()
{
    for(auto item: this->database->getDatabase()) {
        item.second->setSelected(true);
    }
}
void WorkSpace::unselectAllObj()
{
    for(auto item: this->database->getDatabase()) {
        item.second->setSelected(false);
    }
}

void WorkSpace::openEditorWindow(std::string id)
{
    kEditorWindow* editor = this->database->retrieveEditorWinFromDatabase(id);
    if(editor != nullptr) {
        //show window
        editor->show();
        editor->raise(); // mac
        editor->activateWindow(); // windows??
    }else { std::cout << "editor window null\n"; }
}

void WorkSpace::areaSelection(IR::Frame selectedFrame)
{
    std::cout << "areaSelection\n";
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
}
