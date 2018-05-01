//
//  IRiMaSPreferences.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#include "IRiMaSPreferences.hpp"


IR::PreferenceClass::~PreferenceClass()
{
    
}


void IR::PreferenceClass::setupA()
{
    const long sceneW = 5000;
    const long sceneH = 5000;
    
    struct IR::Frame f = {{-sceneW*0.5, -sceneH*0.5},{sceneW, sceneH}};
    this->p_workspace.frame = f;
    
}
    
    

