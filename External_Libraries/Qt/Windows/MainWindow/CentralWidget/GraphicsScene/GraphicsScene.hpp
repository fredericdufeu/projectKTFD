//
//  GraphicsScene.hpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 23/04/2018.
//

#ifndef GraphicsScene_hpp
#define GraphicsScene_hpp

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QPainterPath>


class GraphicsView;

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
    
public:
    GraphicsScene();
    ~GraphicsScene();
    
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    
    GraphicsView *getView();
    
private:
    // QPainterPath *selectionPainterPath;
};

#endif /* GraphicsScene_hpp */
