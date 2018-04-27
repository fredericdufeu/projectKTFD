#include "readSoundFileAtPath.h"




#include <iostream>





void readSoundFileAtPath(const std::string &path, SoundFile &soundFile) // ASSUMES SOUNDFILE IS EMPTY
{
    // 1) OPEN SOUNDFILE
    
    SF_INFO soundFileInfo;
    
    soundFileInfo.format = 0; // required by libsndfile documentation
    SNDFILE *openedSoundFile = sf_open(path.c_str(), SFM_READ, &soundFileInfo);
    
    if (! openedSoundFile)
    {
        std::cout << "Error opening file " << path << "\n\n";
        return;
    }
    
    // 2) READ INTO FLOAT BUFFER
    
    soundFile.samples = new float[soundFileInfo.frames]; // note that frames is of type sf_count_t
    soundFile.numSamples = sf_read_float(openedSoundFile, soundFile.samples, soundFileInfo.frames) / soundFileInfo.channels; // note that return value is of type sf_count_t
    // soundFile.numSamples /= soundFileInfo.channels;
    
    soundFile.samplingRate = soundFileInfo.samplerate;
    soundFile.numChannels = soundFileInfo.channels;
    
    // 3) CLOSE
    
    sf_close(openedSoundFile);
}

