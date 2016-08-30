//
//  main.cpp
//  AddressBook_CPP
//
//  Created by jarvis on 8/31/16.
//  Copyright © 2016 jarvis. All rights reserved.
//

#include <iostream>
#include "server.hpp"

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        printf("lack of arguments!\n");
        return 1;
    }
    tcp_server server(atoi(argv[1]));
    server.recv_message();
    return 0;
}
