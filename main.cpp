//
//  main.cpp
//  AddressBook_CPP
//
//  Created by jarvis on 8/31/16.
//  Copyright © 2016 jarvis. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "Server.hpp"

int main(int argc, const char * argv[]) {
    int port = 33000;
    if (argc == 2) {
        port = atoi(argv[1]);
    }
    Server server(port);
    server.start();
    return 0;
}
