//
//  ProjectDataSet.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/30.
//

#ifndef ProjectDataSet_hpp
#define ProjectDataSet_hpp

#include <stdio.h>
#include <iostream>

#include "WorkSpace.hpp"
#include "WorkSpaceDatabase.hpp"
#include "IRDataStructure.h"

class ProjectData
{
public:
    ProjectData();
    ~ProjectData();
    
    // register an Object to the database with id.
    // return false if failed.
    bool registerWorkspace(std::string id, WorkSpace* obj);
    // retrieve an Object registered in the database.
    // return a pointer of the Object if success, and NULL if failed.
    WorkSpace* retrieveWorkspace(std::string id);
    // remove an Object regiestered in the database and deallocate it.
    // return false if failed.
    bool removeWorkspace(std::string id);
    // print out all objects information registered to the database.
    void showWorkspace();
    

private:
    //workspace
    
    WorkSpaceDatabase workspaceData;

    
    
    
};


#endif /* ProjectDataSet_hpp */
