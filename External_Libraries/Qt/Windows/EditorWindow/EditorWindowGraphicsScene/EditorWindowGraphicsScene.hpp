//
//  EditorWindowGraphicsScene.hpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 24/04/2018.
//

#ifndef EditorWindowGraphicsScene_hpp
#define EditorWindowGraphicsScene_hpp

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>


class EditorWindowGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
    
public:
    EditorWindowGraphicsScene();
    ~EditorWindowGraphicsScene();
};

#endif /* EditorWindowGraphicsScene_hpp */
