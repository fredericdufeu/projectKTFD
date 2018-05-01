//
//  IRGraphicsScene.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#ifndef IRGraphicsScene_hpp
#define IRGraphicsScene_hpp

#include <stdio.h>
#include <iostream>
#include <QtWidgets>

class IRGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    IRGraphicsScene();
    ~IRGraphicsScene();
};

#endif /* IRGraphicsScene_hpp */
