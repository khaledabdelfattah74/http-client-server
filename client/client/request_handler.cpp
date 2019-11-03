//
//  request_handler.cpp
//  client
//
//  Created by Khaled Abdelfattah on 11/2/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "request_handler.hpp"

response* handle_request(request* request) {
    int socket_fd = build_socket(request->headers["Host"], request->port_number);
    request->client_socket_fd = socket_fd;
    request->buid_request_body();
    send_through_socket(socket_fd, request->body, request->request_length);
    char buffer[BUFFER_SIZE];
    read_from_socket(socket_fd, buffer);
    printf("%s\n", buffer);
    response* respone = parse_response(buffer);
    return respone;
}

void handle_requests(vector<request*> requests) {
    for (request* request : requests) {
        response* response = handle_request(request);
        if (response->status == OK && request->request_type == GET) {
            string path = "/Users/khaledabdelfattah/Documents/workspace/networks/HTTP-Client-Server/client/client/storage/" + request->file_path;
            write_into_file(path, response->content, response->get_content_length());
        }
    }
}
