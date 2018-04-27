//
//  GlobalDatabase.hpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 24/04/2018.
//

#ifndef GlobalDatabase_hpp
#define GlobalDatabase_hpp

#include <stdio.h>


// #include "SoundFile.hpp"
#include "SoundNodeObject.hpp"




class GlobalDataBase
{
public:
    GlobalDataBase();
    ~GlobalDataBase();
    
    // NodeObject nodes[128];
    
    
    
    SoundNodeObject soundNodes[128]; // public and fixed size for now
    short numSoundNodes;
};


#endif /* GlobalDatabase_hpp */
