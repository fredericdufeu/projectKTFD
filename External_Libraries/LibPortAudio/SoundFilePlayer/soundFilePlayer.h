//
//  soundFilePlayer.h
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 24/04/2018.
//

#ifndef soundFilePlayer_h
#define soundFilePlayer_h


#include "portaudio.h"

#include "SoundFile.hpp"
//
class SoundNodeObjectGraphicsItem;

// ALORS. COMMENT QU'ON S'ORGANISE???

struct PaData;


static int paCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData);

PaError streamSoundFile(SoundFile *soundFile, PaStream *stream, SoundNodeObjectGraphicsItem *owner);
PaError stopSoundFileStream(PaStream *stream);


#endif /* soundFilePlayer_h */
