//
//  connection_worker.cpp
//  server
//
//  Created by Khaled Abdelfattah on 10/26/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "connection_worker.hpp"

void send_response_body(int, response*);

void establish_connection(int client_socket_fd) {
    char buffer[BUFFER_SIZE];
    read(client_socket_fd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);
    if (!strlen(buffer))
        return;

    response* response = handle_request(buffer);
    send_response_body(client_socket_fd, response);
}

void send_response_body(int client_socket_fd, response* response) {
    send(client_socket_fd, response->body, response->response_length, 0);
}
