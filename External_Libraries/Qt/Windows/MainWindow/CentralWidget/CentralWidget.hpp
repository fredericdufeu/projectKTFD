//
//  CentralWidget.hpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 23/04/2018.
//

#ifndef CentralWidget_hpp
#define CentralWidget_hpp

#include <QtWidgets>

#include "IRiMaSFoundation.h"

// NOW, WHAT IF MY CENTRAL WIDGET NEEDS TO DO STUFF ON A MAINWINDOW?
// OBVIOUSLY WON'T INCLUDE, BUT FORWARD DECLARE




class MainWidgetController : public QWidget
{
    Q_OBJECT
    
public:
    MainWidgetController(QWidget *parent, ProjectData *data);
    ~MainWidgetController();
   

    ProjectData *p_data;
    
    
private:
    QHBoxLayout *layout;
    
    bool isFileNavigatorHidden;
    bool isNodeObjInspectorHidden;

};





#endif /* CentralWidget_hpp */
