//
//  ProjectWindow.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#ifndef ProjectWindow_hpp
#define ProjectWindow_hpp

#include <stdio.h>
#include <iostream>
#include <QtWidgets>
#include "WorkSpace.hpp"

class IRProjectWindow : public QWidget
{
    Q_OBJECT
    
public:
    IRProjectWindow(QWidget *parent = 0);
    IRProjectWindow();
    
private:
    void closeEvent(QCloseEvent *event) override;
    
    
    WorkSpace *workspace;
    QHBoxLayout *layout;

    
};

#endif /* ProjectWindow_hpp */
