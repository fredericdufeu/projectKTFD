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


bool NodeDatabase::registerObjToDatabase(std::string id, kNodeObject* obj, kEditorWindow *win)
{
    if(this->database.find(id) != this->database.end() || this->editor.find(id) != this->editor.end()) {
        std::cout << "Error : registerObjToDatabase(): id " << id << " already exists.\n" << std::endl;
        return false;
    }else{
        this->database[id] = obj;
        this->editor[id] = win;
        std::cout << "registerObjToDatabase(); id " << id << " registered.\n" << this->editor[id] << std::endl;
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

kEditorWindow * NodeDatabase::retrieveEditorWinFromDatabase(std::string id)
{
    std::cout << "editor window retrieved " << this->editor[id] << std::endl;
    if(this->editor.find(id) != this->editor.end()){
        std::cout << "retrieveEditorWinFromDatabase(); id " << id << " retrieved.\n" << std::endl;
        return this->editor[id];
    }else{
        std::cout << "Error : retrieveEditorWinFromDatabase(): id " << id << " does not exist.\n" << std::endl;
        return nullptr;
    }
}

bool NodeDatabase::removeObjFromDatabase(std::string id)
{
    if(this->database.find(id) == this->database.end() || this->editor.find(id) == this->editor.end()){
        std::cout << "removeObjFromDatabase(); id " << id << " does not exist.\n" << std::endl;
        return false;
    }else{
        //erase item if it exists.
        this->database.erase(id);
        this->editor.erase(id);
        return true;
    }
}

void NodeDatabase::showDatabase()
{
    for(auto itr = this->database.begin(); itr != this->database.end(); ++itr) {
        std::cout << "Node Key = " << itr->first << " : NodeObject = " << itr->second << "\n"<< std::endl;
    }
    for(auto itr = this->editor.begin(); itr != this->editor.end(); ++itr) {
        std::cout << "Editor Key = " << itr->first << " : EditorObject = " << itr->second << "\n"<< std::endl;
    }
}

void NodeDatabase::deleteAllNode()
{
    for(auto itr = this->database.begin(); itr != this->database.end(); ++itr) {
        delete itr->second;
    }
    for(auto itr = this->editor.begin(); itr != this->editor.end(); ++itr) {
        delete itr->second;
    }
}

void NodeDatabase::clearDatabase()
{
    deleteAllNode();
    this->database.clear();
    this->editor.clear();
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

std::map<std::string, kEditorWindow*> NodeDatabase::getEditorWindowDatabase()
{
    return this->editor;
}
