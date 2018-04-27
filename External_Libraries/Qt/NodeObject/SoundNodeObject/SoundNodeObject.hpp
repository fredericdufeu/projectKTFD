//
//  SoundNodeObject.hpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 24/04/2018.
//

#ifndef SoundNodeObject_hpp
#define SoundNodeObject_hpp

#include <stdio.h>
#include <string>
#include "NodeObject.hpp"
#include "SoundFile.hpp"

#include "GraphicsView.hpp"
#include "SoundNodeObjectGraphicsItem.hpp"


class SoundNodeObject : public NodeObject
{
public:
    SoundNodeObject();
    SoundNodeObject(const std::string path);
    ~SoundNodeObject();
    
    SoundFile *soundFile;
    
    SoundNodeObjectGraphicsItem *graphicsItem;
};



#endif /* SoundNodeObject_hpp */
