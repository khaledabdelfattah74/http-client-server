//
//  response_manager.cpp
//  client
//
//  Created by Khaled Abdelfattah on 11/20/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "response_manager.hpp"

void process_responses(string, long long);
int get_socket_status(int, struct timeval);

void read_responses(int socket_fd) {
    char buffer[BUFFER_SIZE] = {0};
    struct timeval timer;
    timer.tv_sec = 5;
    timer.tv_usec = 0;
    string responses_body = "";
    long long length = 0;
    
    while (true) {
        int s = get_socket_status(socket_fd, timer);
        if (s == -1) {
            perror("Error in socket buffer");
        } else if (!s) {
            break;
        } else {
            read(socket_fd, buffer, BUFFER_SIZE);
            if (buffer[0] == '\0' && buffer[1] == 0)
                break;
            printf("%s", buffer);
            for (char x : buffer)
                responses_body += x;
            memset(buffer, 0, BUFFER_SIZE);
            length += BUFFER_SIZE;
        }
    }
    
    process_responses(responses_body, length);
    
    close(socket_fd);
}

bool check_headers_end(string responses, int idx) {
    bool is_end = (responses[idx] == '\n');
    is_end &= (idx - 1 >= 0 && responses[idx - 1] == '\r');
    is_end &= (idx - 2 >= 0 && responses[idx - 2] == '\n');
    is_end &= (idx - 3 >= 0 && responses[idx - 3] == '\r');
    return is_end;
}

void process_responses(string responses_body, long long length) {
    string response_body = "";
    for (int i = 0; i < length; i++) {
        if (check_headers_end(responses_body, i)) {
            response* response = parse_response(response_body);
            if (response->status == OK && response->get_content_length()) {
                response->content = new char[response->get_content_length()];
                i++;
                for (int k = 0; k < response->get_content_length(); k++, i++)
                    response->content[k] = responses_body[i];
                
                string path = "/Users/khaledabdelfattah/Documents/workspace/networks/HTTP-Client-Server/client/client/storage" + response->headers["File-Path"];
                write_into_file(path, response->content, response->get_content_length());
            }
            response_body = "";
            continue;
        }
        response_body += responses_body[i];
    }
}

int get_socket_status(int socket_fd, struct timeval time_value) {
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(socket_fd, &rfds);
    int socket_status = select(socket_fd + 1, &rfds, NULL, NULL, &time_value);
    return socket_status;
}
