//
//  CentralWidget.cpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 23/04/2018.
//


#include "CentralWidget.hpp"


MainWidgetController::MainWidgetController(QWidget *parent)
: QWidget(parent)
{
    /* create project data */
    this->p_data = new ProjectData();
}

MainWidgetController::~MainWidgetController()
{
    
}


ProjectData* MainWidgetController::getProjectData()
{
    return this->p_data;
}
