//
//  NodeDatabaseClass.cpp
//  NodeObjectSystem2
//
//  Created by Keitaro Takahashi on 2018/04/26.
//  Copyright © 2018 Keitaro Takahashi. All rights reserved.
//

#include "NodeDatabase.hpp"


NodeDatabase::NodeDatabase()
{
    
}

NodeDatabase::~NodeDatabase()
{
    
}


bool NodeDatabase::registerObjToDatabase(std::string id, kNodeObject* obj)
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

kNodeObject* NodeDatabase::retrieveObjFromDatabase(std::string id)
{
    if(this->database.find(id) != this->database.end()){
        std::cout << "retrieveObjFromDatabase(); id " << id << " retrieved.\n" << std::endl;
        return this->database[id];
    }else{
        std::cout << "Error : retrieveObjFromDatabase(): id " << id << " does not exist.\n" << std::endl;
        return nullptr;
    }
}

bool NodeDatabase::removeObjFromDatabase(std::string id)
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

void NodeDatabase::showDatabase()
{
    for(auto itr = this->database.begin(); itr != this->database.end(); ++itr) {
        std::cout << "key = " << itr->first << " : val = " << itr->second << "\n"<< std::endl;
    }
}

void NodeDatabase::deleteAllNode()
{
    for(auto itr = this->database.begin(); itr != this->database.end(); ++itr) {
        delete itr->second;
    }
}

void NodeDatabase::clearDatabase()
{
    deleteAllNode();
    this->database.clear();
}

void NodeDatabase::showSelectedObj()
{
    for (auto x : this->database) {
        std::cout << x.first << " : " << x.second << "\n";
        kNodeObject *o = static_cast<kNodeObject *>(x.second);
        if(o->isSelected()) {
            std::cout << " selected : "<< x.first << " : " << x.second << "\n";
        }
    }
}

std::map<std::string, kNodeObject*> NodeDatabase::getDatabase()
{
    return this->database;
}
