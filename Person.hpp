//
//  Person.hpp
//  tcp_server
//
//  Created by jarvis on 8/31/16.
//  Copyright © 2016 jarvis. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <string>

class Person
{
private:
    std::string _name;
    std::string _mobile;
    std::string _address;
public:
    Person(const std::string &name = "", const std::string &mobile = "", const std::string &address = "");
    virtual ~Person();
};
#endif /* Person_hpp */
