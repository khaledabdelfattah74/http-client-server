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
vector<request*> process_requests(string, long long);

void establish_connection(int client_socket_fd) {
    char buffer[BUFFER_SIZE] = {0};
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
            struct timeval timer;
            timer.tv_sec = 3;
            timer.tv_usec = 0;
            string requests = "";
            long long length = 0;
            
            while (true) {
                int s = get_socket_status(client_socket_fd, timer);
                if (s == -1) {
                    perror("Error in socket buffer");
                } else if (!s) {
                    break;
                } else {
                    read(client_socket_fd, buffer, BUFFER_SIZE);
                    if (buffer[0] == '\0' && buffer[1] == 0)
                        goto close_connection;
                    printf("%s\n", buffer);
                    for (char x : buffer)
                        requests += x;
                    memset(buffer, 0, BUFFER_SIZE);
                    length += BUFFER_SIZE;
                }
            }
                        
            vector<request*> reqs = process_requests(requests, length);
            length = 0;
            vector<response*> responses;
            for (request* request : reqs) {
                response* response = handle_request(request);
                responses.push_back(response);
                length += response->response_length;
            }
            
            char bodies[length];
            int i = 0;
            for (response* response : responses)
                for (int j = 0; j < response->response_length; i++, j++)
                    bodies[i] = response->body[j];
            send(client_socket_fd, bodies, length, 0);

        }
    }
    
close_connection:
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

bool check_headers_end(string requests, int idx) {
    bool is_end = (requests[idx] == '\n');
    is_end &= (idx - 1 >= 0 && requests[idx - 1] == '\r');
    is_end &= (idx - 2 >= 0 && requests[idx - 2] == '\n');
    is_end &= (idx - 3 >= 0 && requests[idx - 3] == '\r');
    return is_end;
}

vector<request*> process_requests(string requests, long long length) {
    string request_body = "";
    vector<request*> reqs;
    for (int i = 0; i < length; i++) {
        if (check_headers_end(requests, i)) {
            request* req = parse_request(request_body);
            if (req->request_type == POST) {
                req->body = new char[req->get_content_length()];
                i++;
                for (int k = 0; k < req->get_content_length(); k++, i++)
                    req->body[k] = requests[i];
            }
            reqs.push_back(req);
            request_body = "";
            continue;
        }
        request_body += requests[i];
    }
    return reqs;
}
