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


class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
    
public:
    GraphicsScene();
    ~GraphicsScene();
};

#endif /* GraphicsScene_hpp */
