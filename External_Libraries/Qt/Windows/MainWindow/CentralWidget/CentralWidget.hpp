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
#include "CentralWidget.hpp"

// NOW, WHAT IF MY CENTRAL WIDGET NEEDS TO DO STUFF ON A MAINWINDOW?
// OBVIOUSLY WON'T INCLUDE, BUT FORWARD DECLARE

class MainWidgetController : public QWidget
{
    Q_OBJECT
    
public:
    MainWidgetController(QWidget *parent);
    ~MainWidgetController();
   

    ProjectData *getProjectData();
    
    
private:
    
    /* Project Data contains all essential data for a project. */
    ProjectData *p_data;
    
    
    
    QHBoxLayout *layout;
    
    bool isFileNavigatorHidden;
    bool isNodeObjInspectorHidden;

};





#endif /* CentralWidget_hpp */
