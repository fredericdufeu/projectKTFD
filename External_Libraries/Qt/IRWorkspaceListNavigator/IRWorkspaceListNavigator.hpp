//
//  IRWorkspaceListNavigator.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#ifndef IRWorkspaceListNavigator_hpp
#define IRWorkspaceListNavigator_hpp

#include <stdio.h>
#include <iostream>

#include <QtWidgets>

class IRWorkspaceListNavigator : public QListWidget
{
    Q_OBJECT
public:
    IRWorkspaceListNavigator(QWidget *parent);
    ~IRWorkspaceListNavigator();
    
    void addNewItem(QString item);
    void removeItem();
    
    bool isThereAnySelectedItems();

    
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    
    
    void keyUpEvent();
    void keyDownEvent();
    void keyDeleteEvent();
    

    
signals:
    void selectionChangedSignal(QString);
    
public slots:
    void selectionChangeAction();
    
    
};

#endif /* IRWorkspaceListNavigator_hpp */
