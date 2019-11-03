//
//  socket_manager.cpp
//  client
//
//  Created by Khaled Abdelfattah on 11/2/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "socket_manager.hpp"

int build_socket(string host_name, int port_number) {
    int client_fd;
    struct sockaddr_in client_addr;
    client_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if (client_fd < 0) {
        perror("Creation of socket failed");
        exit(EXIT_FAILURE);
    }
    
    struct hostent *server = gethostbyname(host_name.c_str());
    if (server == NULL) {
        perror("Can not find host");
        exit(EXIT_FAILURE);
    }
    
    memset(&client_addr, 0, sizeof(client_addr));
    bcopy((char *) server->h_addr, (char *)&client_addr.sin_addr.s_addr, server->h_length);
    
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(port_number);
    
    int connecting_status = connect(client_fd, (struct sockaddr *) &client_addr, sizeof(client_addr));
    if (connecting_status < 0) {
        perror("Error in connecting");
        exit(EXIT_FAILURE);
    }
    return client_fd;
}

long long int send_through_socket(int socket_fd, char buffer[], long long int size) {
    return send(socket_fd, buffer, size, 0);
}

void read_from_socket(int socket_fd, char buffer[]) {
    read(socket_fd, buffer, BUFFER_SIZE);
}
