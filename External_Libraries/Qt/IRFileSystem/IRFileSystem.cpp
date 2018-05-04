//
//  IRFileSystem.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/04.
//

#include "IRFileSystem.hpp"


IRFileSystem::IRFileSystem()
{
    /* initialize ProjectDirectory with empty */
    this->ProjectDirectory = "";
    
    
}


IRFileSystem::~IRFileSystem()
{
    
}

bool IRFileSystem::createProjectDirectory()
{
    QString url = getSaveDirUrlByDialog();
    
    if(url.isEmpty()){return false;}
    
    createDir(url);
    
    QString ResourceFolder = url + "/Resources";
    QString AudioFolder = ResourceFolder + "/audio";
    QString ImageFolder = ResourceFolder + "/image";
    QString MovieFolder = ResourceFolder + "/movie";
    QString DataFolder = url + "/Data";
    
    createDir(ResourceFolder);
    createDir(DataFolder);
    
    createDir(AudioFolder);
    createDir(ImageFolder);
    createDir(MovieFolder);


    
    
    
    
    
}

QString IRFileSystem::getProjectDirectory()
{
    return this->ProjectDirectory;
}
