//
//  WorkSpaceDatabase.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#ifndef WorkSpaceDatabase_hpp
#define WorkSpaceDatabase_hpp

#include <stdio.h>
#include <iostream>
#include <map>

#include "IRDataType.h"
#include "IRObjectName.h"

#include "WorkSpace.hpp"

class WorkSpaceDatabase {
public:
    WorkSpaceDatabase();
    ~WorkSpaceDatabase();
    
    // register an Object to the database with id.
    // return false if failed.
    bool registerObjToDatabase(std::string id, WorkSpace* obj);
    // retrieve an Object registered in the database.
    // return a pointer of the Object if success, and NULL if failed.
    WorkSpace* retrieveObjFromDatabase(std::string id);
    // remove an Object regiestered in the database.
    // return false if failed.
    bool removeObjFromDatabase(std::string id);
    // print out all objects information registered to the database.
    void showDatabase();
    // clear all members.
    void clearDatabase();
    
private:
    //database map.
    std::map<std::string, WorkSpace*>database;
    
};


#endif /* WorkSpaceDatabase_hpp */
