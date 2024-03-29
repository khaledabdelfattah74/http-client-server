//
//  server_manager.cpp
//  server
//
//  Created by Khaled Abdelfattah on 10/24/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "server_manager.hpp"
#include "request_handler.hpp"

void Server::initiate(int port_number) {
    int server_fd;
    struct sockaddr_in server_addr;
    int addr_len = sizeof(server_addr);
    server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if (server_fd < 0) {
        perror("Creation of socket failed");
        exit(EXIT_FAILURE);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_number);
    
    int binding_status = ::bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (binding_status < 0) {
        perror("Error in binding on the desired socket");
        exit(EXIT_FAILURE);
    }
    
    int listening_status = listen(server_fd, BACKLOG_COUNT);
    if (listening_status < 0) {
        perror("Error in listening");
        exit(EXIT_FAILURE);
    }
    
    printf("====== Server is running on port: %d======\n", server_addr.sin_port);
    
    while (true) {
        int new_socket_fd = accept(server_fd, (struct sockaddr *) &server_addr, (socklen_t *) &addr_len);
        if (new_socket_fd < 0) {
            perror("Error in accepting a connection");
            exit(EXIT_FAILURE);
        }
        /**
            Handling requests from clients. It will be in multi-threaded manner.
         */
        thread client_proc(establish_connection, new_socket_fd);
        client_proc.detach();
    }
}
