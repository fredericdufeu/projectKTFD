//
//  IRObjectName.h
//  NodeObjectSystem2
//
//  Created by Keitaro Takahashi on 2018/04/25.
//  Copyright © 2018 Keitaro Takahashi. All rights reserved.
//

#ifndef IRObjectName_h
#define IRObjectName_h

#include <iostream>

namespace IR_Object {
    
    class Name {
        std::string name;
    public:
        Name(){ this->name = ""; }
        
        Name(std::string name){
            this->name = name;
        }
        
        //copy constructor
        Name(const Name &obj) {
            SetName(obj.name);
        }
        
        
        inline Name &operator=(const Name &obj) {
            SetName(obj.name);
            return *this;
        }
        
        inline Name &operator=(const std::string name) {
            SetName(name);
            return *this;
        }
        
        inline ~Name(){
            
        }
        
        Name &SetName(const std::string name) {
            this->name = name;
            return *this;
        }
        
        std::string getValue() const {
            return this->name;
        }
        void setValue(const std::string value) {
            this->name = value;
        }

    };
    
    
    using Id = std::string;
}

extern std::ostream& operator<<(std::ostream& lhs, const IR_Object::Name& rhs);


#endif /* IRObjectName_h */
