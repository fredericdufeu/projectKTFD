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


#include "IRUtilities.hpp"
#include "kEditorWindowView.hpp"
#include "kEditorWindowScene.hpp"

class kEditorWindow : public QWidget
{
    Q_OBJECT
    
public:
    kEditorWindow(QWidget *parent);
    ~kEditorWindow();
private:
    QWidget *parent;
    
    QHBoxLayout *layout;
    kEditorWindowView *view;
    kEditorWindowScene *scene;
    
};


#endif /* EditorWindow_hpp */
