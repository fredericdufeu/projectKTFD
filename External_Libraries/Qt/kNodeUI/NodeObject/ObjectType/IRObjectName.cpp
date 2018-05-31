//
//  IRObjectName.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/10.
//

#include "IRObjectName.h"

namespace IR_Object {
    

    Name::Name(){ SetName(""); }
    
    Name::Name(const char* name){
        SetName(std::string(name));
    }
    
    Name::Name(const std::string name){
        SetName(name);
    }
    
    //copy constructor
    Name::Name(const Name &obj) {
        SetName(obj.name);
    }
    
    Name::~Name(){
        
    }
    
    // normal
    Name &Name::operator=(const Name &obj) {
        SetName(obj.name);
        return *this;
    }
    
    // std::string
    Name &Name::operator=(const std::string name) {
        SetName(name);
        return *this;
    }
    
    //const char*
    Name &Name::operator=(const char* name) {
        if(name != nullptr){
            SetName(std::string(name));
        }else {SetName("");}
        return *this;
    }
    
    Name &Name::SetName(const std::string name) {
        this->param = splitBySpace(name);
        this->name = name;
        
        for(auto item: this->param) {
            std::cout << item << "\n";
        }
        return *this;
    }
    
    std::string Name::getValue() const {
        return this->name;
    }
    
    std::vector<std::string> Name::getParam() const{
        return this->param;
    }
    
    
    void Name::setValue(const std::string value) {
        SetName(value);
    }
    
    std::vector<std::string> Name::splitBySpace(const std::string &s) {
        
        std::vector<std::string> elems;
        std::stringstream ss(s);
        std::string item;
        while(getline(ss,item,' ')) {
            if(!item.empty()){
                elems.push_back(item);
            }
        }
        return elems;
    }
    
    QString Name::toQString(){
        return QString::fromStdString(this->name);
    }
    
}

std::ostream& operator<<(std::ostream& lhs, const IR_Object::Name& rhs)
{
    const std::string st = rhs.getValue();
    lhs << st;
    return lhs;
    
    }
