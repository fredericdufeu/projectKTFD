//
//  WorkSpaceDatabase.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/01.
//

#include "WorkSpaceDatabase.hpp"


WorkSpaceDatabase::WorkSpaceDatabase()
{
    
}

WorkSpaceDatabase::~WorkSpaceDatabase()
{
    
}

bool WorkSpaceDatabase::registerObjToDatabase(std::string id, WorkSpace* obj)
{
    if(this->database.find(id) != this->database.end()) {
        std::cout << "Error : registerObjToDatabase(): id " << id << " already exists.\n" << std::endl;
        return false;
    }else{
        this->database[id] = obj;
        std::cout << "registerObjToDatabase(); id " << id << " registered.\n" << std::endl;
        return true;
    }
}

WorkSpace* WorkSpaceDatabase::retrieveObjFromDatabase(std::string id)
{
    if(this->database.find(id) != this->database.end()){
        std::cout << "retrieveObjFromDatabase(); id " << id << " retrieved.\n" << std::endl;
        return this->database[id];
    }else{
        std::cout << "Error : retrieveObjFromDatabase(): id " << id << " does not exist.\n" << std::endl;
        return nullptr;
    }
}

bool WorkSpaceDatabase::removeObjFromDatabase(std::string id)
{
    if(this->database.find(id) == this->database.end()){
        std::cout << "removeObjFromDatabase(); id " << id << " does not exist.\n" << std::endl;
        return false;
    }else{
        //erase item if it exists.
        this->database.erase(id);
        return true;
    }
}

void WorkSpaceDatabase::showDatabase()
{
    for(auto itr = this->database.begin(); itr != this->database.end(); ++itr) {
        std::cout << "key = " << itr->first << " : val = " << itr->second << "\n"<< std::endl;
    }
}

void WorkSpaceDatabase::deleteAllWorkSpace()
{
    for(auto itr = this->database.begin(); itr != this->database.end(); ++itr) {
        delete itr->second;
    }
}

void WorkSpaceDatabase::clearDatabase()
{
    this->database.clear();
}

