//
//  IRGraphicsView.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#ifndef IRGraphicsView_hpp
#define IRGraphicsView_hpp

#include <stdio.h>
#include <iostream>
#include <QtWidgets>


class IRGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    IRGraphicsView(QGraphicsScene *scene, QWidget *parent);
    ~IRGraphicsView();
    
    
    virtual void dragEnterEvent(QDragEnterEvent *event) override;
    virtual void dragMoveEvent(QDragMoveEvent *event) override;
    virtual void dropEvent(QDropEvent *event) override;

};

#endif /* IRGraphicsView_hpp */
