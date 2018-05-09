//
//  NodeDatabaseClass.hpp
//  NodeObjectSystem2
//
//  Created by Keitaro Takahashi on 2018/04/26.
//  Copyright © 2018 Keitaro Takahashi. All rights reserved.
//

#ifndef NodeDatabaseClass_hpp
#define NodeDatabaseClass_hpp

#include <stdio.h>
#include <iostream>
#include <map>

#include "IRDataType.h"
#include "IRObjectName.h"

#include "NodeObjectClass.hpp"

class NodeDatabase {
    
public:
    NodeDatabase();
    ~NodeDatabase();
    
    // register an Object to the database with id.
    // return false if failed.
    bool registerObjToDatabase(std::string id, kNodeObject* obj);
    // retrieve an Object registered in the database.
    // return a pointer of the Object if success, and NULL if failed.
    kNodeObject* retrieveObjFromDatabase(std::string id);
    // remove an Object regiestered in the database.
    // return false if failed.
    bool removeObjFromDatabase(std::string id);
    // print out all objects information registered to the database.
    void showDatabase();
    
    std::map<std::string, kNodeObject*> getDatabase();

    //clear all members
    void clearDatabase();
    
    //show selected objects
    void showSelectedObj();
    
private:
    //database map.
    std::map<std::string, kNodeObject*>database;
    
    //deallocate all node pointer
    void deleteAllNode();
    
};


#endif /* NodeDatabaseClass_hpp */
