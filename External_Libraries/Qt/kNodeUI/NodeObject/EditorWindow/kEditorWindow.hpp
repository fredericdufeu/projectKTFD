//
//  EditorWindow.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/30.
//

#ifndef EditorWindow_hpp
#define EditorWindow_hpp

#include <stdio.h>
#include <iostream>
#include <QObject>
#include <QWidget>

#include "kEditorWindowView.hpp"
#include "kEditorWindowScene.hpp"

#include "IRUtilities.hpp"

class kNodeObject;

class kEditorWindow : public QWidget
{
    Q_OBJECT
    
public:
    kEditorWindow(QString &windowTitle, QWidget *parent);
    ~kEditorWindow();
private:
    QWidget *parent;
    
    QHBoxLayout *layout;
    kEditorWindowView *view;
    kEditorWindowScene *scene;
    
};


#endif /* EditorWindow_hpp */
