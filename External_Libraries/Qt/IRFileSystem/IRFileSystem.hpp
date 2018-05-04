//
//  IRFileSystem.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/04.
//

#ifndef IRFileSystem_hpp
#define IRFileSystem_hpp

#include <stdio.h>
#include <iostream>
#include <QDirSystem.hpp>

class IRFileSystem : public QDirSystem
{
public:
    IRFileSystem();
    ~IRFileSystem();
    
    /* create Project Directory by Dialog Window. */
    bool createProjectDirectory();
    
    QString getProjectDirectory();
    
private:
    
    QString ProjectDirectory;
    
};

#endif /* IRFileSystem_hpp */
