#ifndef soundFileLoader_h
#define soundFileLoader_h



#include <string>

#include "sndfile.h" // THIS IS LIBSNDFILE
#include "SoundFile.hpp"



void readSoundFileAtPath(const std::string path, SoundFile *soundFile);



#endif /* soundFileLoader_h */

