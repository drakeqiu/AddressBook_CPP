//
//  server.cpp
//  tcp_server
//
//  Created by jarvis on 8/31/16.
//  Copyright © 2016 jarvis. All rights reserved.
//

#include "Server.hpp"

Server::Server(const int listener):_listener(listener)
{
    initialize();
}
Server::~Server(){}

void Server::initialize()
{
    memset(&_server, 0, sizeof(_server));
    _server.sin_family = AF_INET;
    _server.sin_addr.s_addr = htonl(INADDR_ANY);
    _server.sin_port = htons(_listener);
    
    
    if ((socket_fd = socket(PF_INET , SOCK_STREAM, IPPROTO_TCP)) < 0) {
        printf("Create Socket Failed!\n");
        exit(1);
    }
    
    if (bind(socket_fd, (sockaddr*)&_server, sizeof(_server)) < 0) {
        printf("Server Bind Port: %d Failed\n", _listener);
        exit(1);
    }
    
    if(listen(socket_fd, 5) < 0 ) {
        printf("Server Listener Failed!\n");
        exit(1);
    }
}

int Server::start()
{
    while (1) {
        socklen_t sin_size = sizeof(struct sockaddr_in);
        if ((client_fd = accept(socket_fd, (struct sockaddr*)&_remote, &sin_size))== -1) {
            // throw "Accept Error!";
            continue;
        }
        printf("Received a connection from %s\n",(char*) inet_ntoa(_remote.sin_addr));
        char buffer[4096] = {0};
        if( !fork() ) {
        // handling request here
            send(client_fd, "ab>", sizeof("ab>"), 0);
            recv(client_fd, buffer, sizeof(buffer), 0);
            printf("%s\n", buffer);
            
            exit(0);
        }
        
        close(client_fd);

    }
    
    return 0;
}
