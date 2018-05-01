//
//  ProjectDataSet.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/30.
//

#include "ProjectData.hpp"


ProjectData::ProjectData()
{
    this->workspaceData = WorkSpaceDatabase();
}

ProjectData::~ProjectData()
{
    this->workspaceData.clearDatabase();
}

bool ProjectData::registerWorkspace(std::string id, WorkSpace* obj)
{
    return this->workspaceData.registerObjToDatabase(id,obj);
}

WorkSpace* ProjectData::retrieveWorkspace(std::string id)
{
    return this->workspaceData.retrieveObjFromDatabase(id);
}

bool ProjectData::removeWorkspace(std::string id)
{
    return this->workspaceData.removeObjFromDatabase(id);
}

void ProjectData::showWorkspace()
{
    this->workspaceData.showDatabase();
}



