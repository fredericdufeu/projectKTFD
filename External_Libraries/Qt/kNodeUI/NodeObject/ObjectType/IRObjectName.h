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
#include <vector>
#include <sstream>
#include <string>

namespace IR_Object {
    
    class Name {
        std::string name;
        std::vector<std::string> param;
        
    public:
       
        Name();
        
        Name(const char* name);
      
        Name(const std::string name);
       
        //copy constructor
        Name(const Name &obj);
        
        ~Name();

        
        // normal
        Name &operator=(const Name &obj);
        
        // std::string
        Name &operator=(const std::string name);
        
        //const char*
        Name &operator=(const char* name);
        
        
        Name &SetName(const std::string name);
        
        std::string getValue() const;
        
        void setValue(const std::string value);
        
    private:
        std::vector<std::string> splitBySpace(const std::string &s);

    };
    
    
    using Id = std::string;
}

extern std::ostream& operator<<(std::ostream& lhs, const IR_Object::Name& rhs);


#endif /* IRObjectName_h */
