//
//  server.hpp
//  tcp_server
//
//  Created by jarvis on 8/31/16.
//  Copyright © 2016 jarvis. All rights reserved.
//

#ifndef server_hpp
#define server_hpp

#include <stdio.h>

#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXSIZE 4096

class Server
{
private:
    int socket_fd, client_fd;
    int _listener;
    sockaddr_in _server;
    sockaddr_in _remote;
    void initialize();
public:
    Server(const int = 8001);
    virtual ~Server();
    int start();
};

#endif /* server_hpp */
