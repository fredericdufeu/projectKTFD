//
//  SoundFile.cpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 24/04/2018.
//

#include "SoundFile.hpp"


SoundFile::SoundFile()
{
    numSamples = 0;
    samples = nullptr;
    
    numChannels = 0;
    samplingRate = 0;
}


SoundFile::~SoundFile()
{
    if (samples != nullptr)
        delete [] samples;
}

