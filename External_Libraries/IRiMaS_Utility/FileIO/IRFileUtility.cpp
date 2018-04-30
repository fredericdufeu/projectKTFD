//
//  IRFileUtility.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/27.
//

#include "IRFileUtility.hpp"

IRFileUtility::IRFileUtility()
{
    this->IR_FILE_TYPE_EXT =
    {
        {"",            IR_FILE::TYPE::NONE},
        {"wav",         IR_FILE::TYPE::EXT_AUDIO_WAV},
        {"aif",         IR_FILE::TYPE::EXT_AUDIO_AIF},
        {"mp3",         IR_FILE::TYPE::EXT_AUDIO_MP3},
        
        {"raw",         IR_FILE::TYPE::EXT_IMAGE_RAW},
        {"jpeg",        IR_FILE::TYPE::EXT_IMAGE_JPEG},
        {"jpg",         IR_FILE::TYPE::EXT_IMAGE_JPEG},
        {"gif",         IR_FILE::TYPE::EXT_IMAGE_GIF},
        
        {"mov",         IR_FILE::TYPE::EXT_MOVIE_MOV},
        {"mp4",         IR_FILE::TYPE::EXT_MOVIE_MP4},
    };
}

IRFileUtility::~IRFileUtility()
{
    
}

IR_FILE::TYPE IRFileUtility::checkFileType(std::string& filename)
{
    /* extract extension */
    std::string ext = getFileExtension(filename);
    
    /* convert string to extension id defined in IR_FILE::TYPE (IRFileTypeEnum.h)*/
    if(this->IR_FILE_TYPE_EXT.find(ext) == this->IR_FILE_TYPE_EXT.end()) {
        std::cout << "Error checkFileType() : Inappropriate file format. \n" << std::endl;
        return IR_FILE::TYPE::NONE;
    }
    /* convert id number to IR_FILE::TYPE */
    return static_cast<IR_FILE::TYPE>(this->IR_FILE_TYPE_EXT[ext]);
}

std::string IRFileUtility::getFileExtension(const std::string& s)
{
    size_t i = s.rfind('.', s.length());
    if(i != std::string::npos){
        return (s.substr(i+1,s.length() - i));
    }
    return ("");
}

