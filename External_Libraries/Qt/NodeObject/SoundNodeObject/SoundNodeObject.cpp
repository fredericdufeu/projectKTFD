#include "readSoundFileAtPath.h"


#include "SoundNodeObject.hpp"


SoundNodeObject::SoundNodeObject()
: NodeObject()
{
    
}


SoundNodeObject::SoundNodeObject(const std::string path)
: NodeObject(path)
{
    soundFile = new SoundFile;
    readSoundFileAtPath(path, soundFile);
    
    graphicsItem = new SoundNodeObjectGraphicsItem(0, 0, soundFile);
}


SoundNodeObject::~SoundNodeObject()
{
    delete soundFile;
    delete graphicsItem;
}

