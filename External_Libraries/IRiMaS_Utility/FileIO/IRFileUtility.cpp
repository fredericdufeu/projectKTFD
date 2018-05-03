//
//  IRFileUtility.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/04/27.
//

#include "IRFileUtility.hpp"

IRFileUtility::IRFileUtility()
{
    this->IR_FILE_FORMAT_EXT =
    {
        {"",            IR_FILE::FILEFORMAT::NONE},
        {"wav",         IR_FILE::FILEFORMAT::EXT_AUDIO_WAV},
        {"aif",         IR_FILE::FILEFORMAT::EXT_AUDIO_AIF},
        {"mp3",         IR_FILE::FILEFORMAT::EXT_AUDIO_MP3},
        
        {"raw",         IR_FILE::FILEFORMAT::EXT_IMAGE_RAW},
        {"jpeg",        IR_FILE::FILEFORMAT::EXT_IMAGE_JPEG},
        {"jpg",         IR_FILE::FILEFORMAT::EXT_IMAGE_JPEG},
        {"gif",         IR_FILE::FILEFORMAT::EXT_IMAGE_GIF},
        
        {"mov",         IR_FILE::FILEFORMAT::EXT_MOVIE_MOV},
        {"mp4",         IR_FILE::FILEFORMAT::EXT_MOVIE_MP4},
    };
    
    this->IR_FILE_TYPE_EXT =
    {
        {0,         IR_FILE::FILETYPE::NOTYPE},
        {1,         IR_FILE::FILETYPE::AUDIO},
        {2,         IR_FILE::FILETYPE::IMAGE},
        {3,         IR_FILE::FILETYPE::MOVIE},
        {4,         IR_FILE::FILETYPE::SCORE},

    };
}

IRFileUtility::~IRFileUtility()
{
    
}

IR_FILE::FILEIDENTITY IRFileUtility::checkFileType(std::string& filename)
{
    /* extract extension */
    std::string ext = getFileExtension(filename);
    
    /* convert string to extension id defined in IR_FILE::TYPE (IRFileTypeEnum.h)*/
    if(this->IR_FILE_FORMAT_EXT.find(ext) == this->IR_FILE_FORMAT_EXT.end()) {
        std::cout << "Error checkFileType() : Inappropriate file format. \n" << std::endl;
        return IR_FILE::FILEIDENTITY{ IR_FILE::FILEFORMAT::NONE, IR_FILE::FILETYPE::NOTYPE};
    }
    
    int fileTypeIndex = static_cast<int>(this->IR_FILE_FORMAT_EXT[ext])/100;
    IR_FILE::FILETYPE type = checkFileType(fileTypeIndex);
    /* convert id number to IR_FILE::TYPE */
    return IR_FILE::FILEIDENTITY{static_cast<IR_FILE::FILEFORMAT>(this->IR_FILE_FORMAT_EXT[ext]), type};
}

std::string IRFileUtility::getFileExtension(const std::string& s)
{
    size_t i = s.rfind('.', s.length());
    if(i != std::string::npos){
        return (s.substr(i+1,s.length() - i));
    }
    return ("");
}

IR_FILE::FILETYPE IRFileUtility::checkFileType(int fileTypeIndex)
{
    if(this->IR_FILE_TYPE_EXT.find(fileTypeIndex) == this->IR_FILE_TYPE_EXT.end()) {
        std::cout << "Error checkFileType() : Inappropriate file format. \n" << std::endl;
        return IR_FILE::FILETYPE::NOTYPE;
    }
    
    return static_cast<IR_FILE::FILETYPE>(this->IR_FILE_TYPE_EXT[fileTypeIndex]);
}

