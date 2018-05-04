//
//  QDirSystem.hpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/04.
//

#ifndef QDirSystem_hpp
#define QDirSystem_hpp

#include <stdio.h>
#include <iostream>
#include <QtWidgets>

class QDirSystem
{
public:
    QDirSystem();
    ~QDirSystem();
    
    
    QString getSaveDirUrlByDialog();
    
    QString getDirUrlByDialog();
    
    bool createDirByDialog();
    
    bool createDir(QString url);
    bool removeDir(QString url);
    bool moveDir(QString from, QString to);
    
};

#endif /* QDirSystem_hpp */
