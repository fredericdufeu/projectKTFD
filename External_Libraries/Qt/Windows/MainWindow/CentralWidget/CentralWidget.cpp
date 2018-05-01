//
//  CentralWidget.cpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 23/04/2018.
//


#include "CentralWidget.hpp"


MainWidgetController::MainWidgetController(QWidget *parent, ProjectData *data)
: QWidget(parent)
{
    this->data = p_data;
}

MainWidgetController::~MainWidgetController()
{
    
}
