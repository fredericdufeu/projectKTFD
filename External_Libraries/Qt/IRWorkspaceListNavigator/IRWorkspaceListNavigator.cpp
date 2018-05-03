//
//  IRWorkspaceListNavigator.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#include "IRWorkspaceListNavigator.hpp"


IRWorkspaceListNavigator::IRWorkspaceListNavigator(QWidget *parent)
:QListWidget(parent)
{
    /* Disable sorting : the item should be put in created order.*/
    this->setSortingEnabled(false);
    //this->sortItems(Qt::AscendingOrder);

    this->setDragEnabled(true);
    //QString item = "workspace_1";
    
    //addNewItem(item);
    
    /* connect signal to slot selectionChanged(). The target of the signal is also "this" because this class inherits QListWidget itself.*/
    QObject::connect(this, SIGNAL(itemSelectionChanged()), this, SLOT(selectionChangeAction()));
    
}

IRWorkspaceListNavigator::~IRWorkspaceListNavigator()
{
    this->clear();
}


void IRWorkspaceListNavigator::addNewItem(QString item)
{
    std::cout << "addItem\n" << std::endl;
    this->addItem(new QListWidgetItem(item));



}

void IRWorkspaceListNavigator::selectionChangeAction()
{
    std::cout << "selected changed!! call Signal" << std::endl;
    QList<QListWidgetItem *> listItems = this->selectedItems();
    
    QString id = listItems[0]->text();
    
    //invoke signal
    emit selectionChangedSignal(id);
}
/*
void IRWorkspaceListNavigator::selectionChangedSignal()
{
    std::cout << "selectionChangedSignal called!!" << std::endl;

}*/
