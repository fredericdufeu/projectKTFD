//
//  IRFileTypeEnum.h
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/27.
//

#ifndef IRFileTypeEnum_h
#define IRFileTypeEnum_h

#include <iostream>
#include <string>
#include <map>


namespace IR_FILE
{
    enum TYPE
    {
        /* undefined */
        NONE                = 0,
        
        /* audio */
        EXT_AUDIO_WAV       = 101,
        EXT_AUDIO_AIF       = 102,
        EXT_AUDIO_MP3       = 111,

        /* image */
        EXT_IMAGE_RAW       = 201,
        EXT_IMAGE_JPEG      = 202,
        EXT_IMAGE_GIF       = 203,
        
        /* movie */
        EXT_MOVIE_MOV       = 301,
        EXT_MOVIE_MP4       = 302,

    };
    
    
    
};





#endif /* IRFileTypeEnum_h */
