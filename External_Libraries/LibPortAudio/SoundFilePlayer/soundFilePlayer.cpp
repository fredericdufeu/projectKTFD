//
//  soundFilePlayer.cpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 24/04/2018.
//

#include "soundFilePlayer.h"
#include "SoundNodeObjectGraphicsItem.hpp"

#include <iostream>


// JUST BASIC DATA FOR TEST

struct PaData // note that this is C++ syntax and differs from the C example in PA doc
{
    SoundNodeObjectGraphicsItem *owner;
    bool isPlaying;
    SoundFile *soundFile;
    long position;
    
    void promptDone()
    {
        std::cout << "Done playing - don't forget to enter some value to stop playback" << std::endl;
    }

    /*
     float left_phase = 0.0f;
     float right_phase = 0.0f;
     // float frequencyLeft = 100.0f;
     // float frequencyRight = 67.0f;
     float incrementLeft = 0.002f;
     float incrementRight = 0.005f;
     
     float left_phase2 = 0.0f;
     float right_phase2 = 0.0f;
     // float frequencyLeft = 100.0f;
     // float frequencyRight = 67.0f;
     float incrementLeft2 = 0.0012f;
     float incrementRight2 = 0.0047f;
     */
};

// CALLBACK FUNCTION

static int paCallback(const void *, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
    PaData *data = static_cast<PaData *>(userData); // cast data to our personalised structure
    float *out = static_cast<float *>(outputBuffer);
    
    if (data->isPlaying && data->soundFile->numChannels > 0 && data->soundFile->numChannels < 3)
    {
        switch (data->soundFile->numChannels)
        {
            case 1:
                for (unsigned long i = 0; i < framesPerBuffer; i++)
                {
                    long index = data->position + i;
                    if (index < data->soundFile->numSamples)
                    {
                        *out++ = data->soundFile->samples[index];
                        *out++ = data->soundFile->samples[index];
                    }
                    else
                    {
                        data->isPlaying = false;
                        data->promptDone();
                        break;
                    }
                }
                break;
            case 2:
                for (unsigned long i = 0; i < framesPerBuffer; i++)
                {
                    long index = data->position + i;
                    if (index < data->soundFile->numSamples)
                    {
                        *out++ = data->soundFile->samples[2 * index];
                        *out++ = data->soundFile->samples[2 * index + 1];
                    }
                    else
                    {
                        data->isPlaying = false;
                        data->promptDone();
                    }
                }
                break;
        }
        data->position += framesPerBuffer;
        // data->postPos();
        data->owner->updatePlaybackPosition(data->position);
    }
    else
    {
        for (unsigned long i = 0; i < framesPerBuffer; i++)
        {
            *out++ = 0.0f;
            *out++ = 0.0f;
        }
    }
    
    return 0;
}


PaError streamSoundFile(SoundFile *soundFile, PaStream *stream, SoundNodeObjectGraphicsItem *owner)
{
    // *** 1) INITALISE OUR USER DATA
    
    PaError err;
    
    static PaData data;
    data.owner = owner;
    data.soundFile = soundFile;
    data.isPlaying = true;
    data.position = 0L;
    
    
    // *** 2) OPEN STREAM
    
    err = Pa_OpenDefaultStream(&stream, 0, 2, paFloat32, 44100, 256, paCallback, &data);
    if (err != paNoError)
        return err;
    
    // *** 3) START STREAM
    
    err = Pa_StartStream(stream);
    // std::cout << "Start Stream error code: " << err << std::endl;
    if (err != paNoError)
        return err;
    
    std::cout << "no error apparently in starting the stream" << std::endl;
    
    owner->playBackStream = stream; // this needed otherwise I am in trouble when stopping the stream in function below - need to clarify how passing by reference works and so on
    
    
    
    return err;
}


PaError stopSoundFileStream(PaStream *stream)
{
    // *** 4) STOP STREAM AND CLEANUP (CLOSE, TERMINATE)
    
    PaError err = Pa_StopStream(stream);
    if (err != paNoError)
        return err;

    err = Pa_CloseStream(stream);
    // std::cout << "Close Stream error code: " << err << std::endl;
    if (err != paNoError)
        return err;
    
    return err;
}
