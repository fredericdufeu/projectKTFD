//
//  EditorWindowGraphicsView.hpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 24/04/2018.
//

#ifndef EditorWindowGraphicsView_hpp
#define EditorWindowGraphicsView_hpp

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include "EditorWindowGraphicsScene.hpp"

class CentralWidget;


class EditorWindowGraphicsView : public QGraphicsView
{
    Q_OBJECT
    
public:
    EditorWindowGraphicsView(EditorWindowGraphicsScene *scene, QWidget *parent);
    ~EditorWindowGraphicsView();
};


#endif /* EditorWindowGraphicsView_hpp */
