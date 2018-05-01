//
//  IRiMaSPreferences.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#ifndef IRiMaSPreferences_hpp
#define IRiMaSPreferences_hpp

#include <stdio.h>
#include <iostream>

#include "IRUtilities.hpp"

namespace IR {
    
    struct t_workspace{
        IR::Frame frame;
    };
    
    class PreferenceClass
    {
    public:
        PreferenceClass(int num)
        {
            if(num == 0){
                setupA();
            }
        }
        ~PreferenceClass();
        
        t_workspace p_workspace;
        
        
        void setupA();
        

    };
    
    
    
    
    
    
  

}


#endif /* IRiMaSPreferences_hpp */
