//
//  NodeObject.hpp
//  IRiMaSToolBox
//
//  Created by Frédéric Dufeu on 24/04/2018.
//

#ifndef NodeObject_hpp
#define NodeObject_hpp


#include <iostream>
#include <string>


class NodeObject
{
public:
    NodeObject();
    NodeObject(const std::string path);
    ~NodeObject();
    
    std::string getOriginalFilePath() const;
    
private:
    std::string originalFilePath;
    
};



#endif /* NodeObject_hpp */
