//
//  kEditorWindowScene.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/30.
//

#ifndef kEditorWindowScene_hpp
#define kEditorWindowScene_hpp

#include <stdio.h>
#include <iostream>
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>

#include "IRWorkspaceScene.hpp"
#include "IRUtilities.hpp"

class kEditorWindowScene : public IRWorkspaceScene
{
    Q_OBJECT
    
public:
    kEditorWindowScene(QWidget *parent);
    ~kEditorWindowScene();
private:
    QWidget *parent;
};


#endif /* kEditorWindowScene_hpp */
