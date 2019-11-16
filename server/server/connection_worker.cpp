//
//  connection_worker.cpp
//  server
//
//  Created by Khaled Abdelfattah on 10/26/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "connection_worker.hpp"

void send_response_body(int, response*);
int get_socket_status(int, struct timeval);

void establish_connection(int client_socket_fd) {
    char buffer[BUFFER_SIZE];
    struct timeval time_value;
    time_value.tv_sec = 60;
    time_value.tv_usec = 0;
    
    while (true) {
        int status = get_socket_status(client_socket_fd, time_value);
        if (status == -1) {
            perror("Error in socket buffer");
        } else if (!status) {
            printf("No data received in 60 seconds\n");
            break;
        } else {
            read(client_socket_fd, buffer, BUFFER_SIZE);
            printf("%s\n", buffer);
            if (!strlen(buffer))
                break;
            
            response* response = handle_request(buffer);
            send_response_body(client_socket_fd, response);
            memset(buffer, 0, BUFFER_SIZE);
        }
    }
    printf("Closing client socket\n");
    close(client_socket_fd);
}

void send_response_body(int client_socket_fd, response* response) {
    send(client_socket_fd, response->body, response->response_length, 0);
}

int get_socket_status(int socket_fd, struct timeval time_value) {
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(socket_fd, &rfds);
    int socket_status = select(socket_fd + 1, &rfds, NULL, NULL, &time_value);
    return socket_status;
}
