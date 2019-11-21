//
//  request_handler.cpp
//  client
//
//  Created by Khaled Abdelfattah on 11/2/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "request_handler.hpp"

void handle_request(request* request) {
    int socket_fd = request->client_socket_fd;
    request->buid_request_body();
    send_through_socket(socket_fd, request->body, request->request_length);
}

void handle_requests(vector<request*> requests) {
    request* first_request = *requests.begin();
    int socket_fd = build_socket(first_request->headers["Host"], first_request->port_number);
    
    long long length = 0;
    for (request* request : requests) {
        request->buid_request_body();
        length += request->request_length;
    }
    char bodies[length];
    int i = 0;
    for (request* request : requests)
        for (int j = 0; j < request->request_length; j++, i++)
            bodies[i] = request->body[j];
    send(socket_fd, bodies, length, 0);
    
    read_responses(socket_fd);
}
