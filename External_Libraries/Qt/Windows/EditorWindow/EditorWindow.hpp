//
//  EditorWindow.hpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 24/04/2018.
//

#ifndef EditorWindow_hpp
#define EditorWindow_hpp

#include <iostream>
#include <QWidget>
#include <QHBoxLayout>
#include "EditorWindowGraphicsView.hpp"
#include "EditorWindowGraphicsScene.hpp"
#include <QTextEdit>

class EditorWindow : public QWidget
{
    Q_OBJECT
    
public:
    EditorWindow(QWidget *parent);
    ~EditorWindow();
    
// nothing private for now
    QHBoxLayout *layout;
    
    EditorWindowGraphicsView *view;
    EditorWindowGraphicsScene *scene;
    
    QTextEdit *inspector;
};

#endif /* EditorWindow_hpp */
