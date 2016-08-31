//
//  server.cpp
//  tcp_server
//
//  Created by jarvis on 8/31/16.
//  Copyright © 2016 jarvis. All rights reserved.
//

#include "server.hpp"

tcp_server::tcp_server(int port)
{
    if ((socket_fd = socket(PF_INET , SOCK_STREAM, IPPROTO_TCP)) < 0) {
        throw "socket() failed";
    }
    
    memset(&_server, 0, sizeof(_server));
    _server.sin_family = AF_INET;
    _server.sin_addr.s_addr = htonl(INADDR_ANY);
    _server.sin_port = htons(port);
    
    if (bind(socket_fd, (sockaddr*)&_server, sizeof(_server)) < 0) {
        throw "bind() failed";
    }
    
    if(listen(socket_fd, 5) < 0 ) {
        throw "listen() failed";
    }
}

int tcp_server::recv_message()
{
    while (1) {
        socklen_t sin_size = sizeof(struct sockaddr_in);
        if ((client_fd = accept(socket_fd, (struct sockaddr*)&_remote, &sin_size))== -1) {
            // throw "Accept Error!";
            continue;
        }
        printf("Received a connection from %s\n",(char*) inet_ntoa(_remote.sin_addr));
        if( !fork() ) {
            char buffer[MAXSIZE];
            memset(buffer, 0, MAXSIZE);
            if((recv(client_fd,buffer,MAXSIZE, 0)) < 0) {
                throw("Read() error!");
            } else {
                printf("Received message: %s\n",buffer);
                break;
            }
        }
        close(client_fd);
        
    }
    
    return 0;
}
