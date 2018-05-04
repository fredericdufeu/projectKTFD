//
//  ProjectDataSet.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/30.
//

#include "ProjectData.hpp"


ProjectData::ProjectData()
{
    this->workspaceData = new WorkSpaceDatabase();
}

ProjectData::~ProjectData()
{

}

bool ProjectData::registerWorkSpace(std::string id, WorkSpace *obj)
{
    return this->workspaceData->registerObjToDatabase(id,obj);
}

WorkSpace* ProjectData::retrieveWorkSpace(std::string id)
{
    return this->workspaceData->retrieveObjFromDatabase(id);
}

bool ProjectData::removeWorkSpace(std::string id)
{
    return this->workspaceData->removeObjFromDatabase(id);
}

void ProjectData::showWorkSpace()
{
    this->workspaceData->showDatabase();
}

void ProjectData::clearWorkSpace()
{
    this->workspaceData->clearDatabase();
}
