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
    
    void mousePressEvent(QMouseEvent *mouseEvent) override;
    
    CentralWidget *parentCentralWidget;
    
    IR::Point getMPos() const;
    IR::Point getMPosScene() const;
    
private:
    IR::Point mPos;
    IR::Point mPosScene;
};



#endif /* GraphicsView_hpp */
