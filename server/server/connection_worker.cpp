//
//  connection_worker.cpp
//  server
//
//  Created by Khaled Abdelfattah on 10/26/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "connection_worker.hpp"

void establish_connection(int client_socket_fd) {
    string hello = "Hello from server";
    char buffer[1024] = {0};
    read(client_socket_fd, buffer, 1024);
    printf("%s\n", buffer);
    char* response = handle_request(buffer);
    send(client_socket_fd, response, strlen(response), 0);
    printf("Hello message sent from server\n");
}
