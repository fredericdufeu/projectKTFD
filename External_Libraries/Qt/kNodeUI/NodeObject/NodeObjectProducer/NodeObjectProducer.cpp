//
//  NodeObjectProducer.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/11.
//

#include "NodeObjectProducer.hpp"

NodeObjectProducer::NodeObjectProducer()
{
}

NodeObjectProducer::~NodeObjectProducer()
{
    
}

bool NodeObjectProducer::produceObjFromDropFile(IR_FILE::FILEIDENTITY fileIdentity)
{
    bool flag = NodeObjectAssigner(fileIdentity);
    return flag;
}


bool NodeObjectProducer::NodeObjectAssigner(IR_FILE::FILEIDENTITY fileIdentity)
{
    switch (fileIdentity.type)
    {
        case IR_FILE::FILETYPE::AUDIO:
            //createAudioObj(objFrame);
            //createWaveformObj(objFrame); // Call createWaveformObj();
            return true;
            break;
        case IR_FILE::FILETYPE::IMAGE:
            return true;
            break;
        case IR_FILE::FILETYPE::MOVIE:
            return true;
            break;
        case IR_FILE::FILETYPE::SCORE:
            return true;
            break;
        default:
            return false;
            break;
    }
}


