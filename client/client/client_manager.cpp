//
//  client_manager.cpp
//  client
//
//  Created by Khaled Abdelfattah on 10/25/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "client_manager.hpp"

void Client::initiate(int port_number) {
    int client_fd;
    struct sockaddr_in client_addr;
    client_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if (client_fd < 0) {
        perror("Creation of socket failed");
        exit(EXIT_FAILURE);
    }
    
    struct hostent *server = gethostbyname("localhost");
    if (server == NULL) {
        perror("Can not find host");
        exit(EXIT_FAILURE);
    }
    
//    int status = inet_pton(AF_INET, "localhost", &client_addr.sin_addr);
//    if (status <= 0) {
//        perror("Invalid address");
//        exit(EXIT_FAILURE);
//    }
    
    memset(&client_addr, 0, sizeof(client_addr));
    
    bcopy((char *) server->h_addr, (char *)&client_addr.sin_addr.s_addr, server->h_length);
    
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(port_number);
    
    int connecting_status = connect(client_fd, (struct sockaddr *) &client_addr, sizeof(client_addr));
    if (connecting_status < 0) {
        perror("Error in connecting");
        exit(EXIT_FAILURE);
    }
    
    string hello = "Hello from client";
    char buffer[1024] = {0};
    send(client_fd, &hello, hello.length() + 1, 0);
    printf("Hello sent from client\n");
    read(client_fd, buffer, 1024);
    printf("%s\n", buffer);
    close(client_fd);
}
