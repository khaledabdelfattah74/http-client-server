//
//  connection_worker.cpp
//  server
//
//  Created by Khaled Abdelfattah on 10/26/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "connection_worker.hpp"

void send_response_headers(int, response*);
void send_response_body(int, response*);

void establish_connection(int client_socket_fd) {
    char buffer[BUFFER_SIZE] = {0};
    read(client_socket_fd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);
    
    response* response = handle_request(buffer);
    send_response_headers(client_socket_fd, response);
    
    if (response->request_type == GET && response->status == OK_STATUS) {
        send_response_body(client_socket_fd, response);
    }
}

void send_response_headers(int client_socket_fd, response* response) {
    string headers = "";
    headers += response->status;
    for (map<string, string>::iterator header = response->headers.begin();
         header != response->headers.end(); header++) {
        headers += (header->first + ": " + header->second + "\n");
    }
    headers += "\r\n";
    send(client_socket_fd, headers.c_str(), headers.length(), 0);
}

void send_response_body(int client_socket_fd, response* response) {
    send(client_socket_fd, response->body, response->get_content_length(), 0);
}
