//
//  GraphicsView.hpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 23/04/2018.
//

#ifndef GraphicsView_hpp
#define GraphicsView_hpp

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include "GraphicsScene.hpp"
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>

#include "IRUtilities.hpp"

class CentralWidget;


class GraphicsView : public QGraphicsView
{
    Q_OBJECT
    
public:
    GraphicsView(GraphicsScene *scene, QWidget *parent);
    ~GraphicsView();
    
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override; // empty function but needed to accept the drop
    void dropEvent(QDropEvent *event) override;
    
    CentralWidget *parentCentralWidget;
    
private:
    IR::Point mPos;
    QWidget *parent;
    
};



#endif /* GraphicsView_hpp */
