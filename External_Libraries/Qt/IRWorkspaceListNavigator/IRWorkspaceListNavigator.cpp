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
    QString item = "workspace_1";
    
    //QLineEdit *line = new QLineEdit(item,this);
    //this->addItem(line->text());
    
    //QLstWidgetItem *wItem = new QListWidgetItem(&item);
    //this->addItem(new QListWidgetItem("workspace 1"));

    
    
    //this->lineEdit = new QLineEdit(item, this);
    //this->lineEdit->setReadOnly(true);
    //this->addItem(lineEdit->text());
    
    
    addNewItem(item);
    
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
    std::cout << "selected changed!!" << std::endl;
}
