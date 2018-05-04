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
    
    /* clear selection. */
    this->clearSelection();
    
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

bool IRWorkspaceListNavigator::isThereAnySelectedItems()
{
    /* check if there is at least one item selected. */
    for(int i=0;i<this->count();++i) if(this->isItemSelected(this->item(i))) { return true; break;}
    return false;
}


/* Event */
void IRWorkspaceListNavigator::keyPressEvent(QKeyEvent *event)
{
    QListWidget::keyPressEvent(event);
    std::cout << "WorkspaceListNavigator : key pressed! " << event->key() << " : " << Qt::Key_Delete << std::endl;
    switch (event->key())
    {
        case Qt::Key_Delete:
        case 16777219:
            keyDeleteEvent();
            break;
        case Qt::Key_Up:
            break;
        case Qt::Key_Down:
            break;
    }
}

void IRWorkspaceListNavigator::keyReleaseEvent(QKeyEvent *event)
{
    QListWidget::keyReleaseEvent(event);
}

/* Event Action */

void IRWorkspaceListNavigator::keyDeleteEvent()
{
    
    
    std::cout << "keyDeleteEvent()" << std::endl;
   
    QList<QListWidgetItem*> items = this->selectedItems();
    foreach(QListWidgetItem *item, items){
        delete this->takeItem(this->row(item));
    }
}

void IRWorkspaceListNavigator::keyUpEvent()
{
    if(isThereAnySelectedItems() == true) {
        
        
    }
}

void IRWorkspaceListNavigator::keyDownEvent()
{
    
}

