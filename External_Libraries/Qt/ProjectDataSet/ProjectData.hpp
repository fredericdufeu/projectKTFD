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

#include <QWidget>

#include "WorkSpace.hpp"
#include "WorkSpaceDatabase.hpp"
#include "IRDataStructure.h"

class ProjectData
{
public:
    ProjectData();
    ~ProjectData();
    
    bool registerWorkSpace(std::string id, WorkSpace *obj);
    WorkSpace* retrieveWorkSpace(std::string id);
    bool removeWorkSpace(std::string id);
    void showWorkSpace();
    void clearWorkSpace();
    
    
    
    

private:
    //workspace
    
    WorkSpaceDatabase *workspaceData;
    
    QString RESOURCE_DIRECTORY = "/Resources";
    QString DATA_DIRECTORY = "/Data";
    QString AUDIO_DIRECTORY = "/Resources/audio";
    QString IMAGE_DIRECTORY = "/Resources/image";
    QString MOVIE_DIRECTORY = "/Resources/movie";

    
};


#endif /* ProjectDataSet_hpp */
