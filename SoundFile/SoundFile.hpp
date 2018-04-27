//
//  SoundFile.hpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 24/04/2018.
//

#ifndef SoundFile_hpp
#define SoundFile_hpp

class SoundFile
{
public:
    SoundFile();
    ~SoundFile();
    
    long numSamples;
    float *samples;
    
    long numChannels;
    long samplingRate;
};




#endif /* SoundFile_hpp */
