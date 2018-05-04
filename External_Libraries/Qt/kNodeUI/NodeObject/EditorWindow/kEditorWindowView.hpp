//
//  kEditorWindowView.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/04.
//

#ifndef kEditorWindowView_hpp
#define kEditorWindowView_hpp

#include <stdio.h>
#include <iostream>

#include <QtWidgets>

class kEditorWindowView : public QGraphicsView
{
    Q_OBJECT
public:
    kEditorWindowView(QGraphicsScene *scene, QWidget *parent);
    ~kEditorWindowView();
    
};

#endif /* kEditorWindowView_hpp */
