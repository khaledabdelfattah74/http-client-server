//
//  request_handler.cpp
//  client
//
//  Created by Khaled Abdelfattah on 11/2/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "request_handler.hpp"

response* handle_request(request* request) {
    int socket_fd = request->client_socket_fd;
    request->buid_request_body();
    send_through_socket(socket_fd, request->body, request->request_length);
    char buffer[BUFFER_SIZE];
    read_from_socket(socket_fd, buffer);
    printf("%s\n", buffer);
    response* respone = parse_response(buffer);
    return respone;
}

void handle_requests(vector<request*> requests) {
    request* first_request = *requests.begin();
    int socket_fd = build_socket(first_request->headers["Host"], first_request->port_number);
    
    for (request* request : requests) {
        request->client_socket_fd = socket_fd;
        response* response = handle_request(request);
        if (response->status == OK && request->request_type == GET) {
            string path = "/Users/khaledabdelfattah/Documents/workspace/networks/HTTP-Client-Server/client/client/storage/" + request->file_path;
            write_into_file(path, response->content, response->get_content_length());
        }
    }
    close(socket_fd);
}
