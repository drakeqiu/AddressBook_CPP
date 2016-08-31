//
//  Handler.hpp
//  AddressBook_CPP
//
//  Created by jarvis on 9/1/16.
//  Copyright © 2016 jarvis. All rights reserved.
//

#ifndef Handler_hpp
#define Handler_hpp

#include <stdio.h>

class Handler
{
public:
    void start();
    Handler();
    virtual ~Handler();
private:
    void initialize();
};

#endif /* Handler_hpp */
