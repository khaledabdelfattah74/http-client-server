//
//  client_manager.cpp
//  client
//
//  Created by Khaled Abdelfattah on 10/25/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "client_manager.hpp"

void Client::initiate(string host_name, int port_number) {
    int client_fd = build_socket(host_name, port_number);
    vector<string> client_requests = read_file("/Users/khaledabdelfattah/Documents/workspace/networks/HTTP-Client-Server/client/client/input_file.txt");
    // Parsing requests
    vector<request*> requests = parse_client_requests(client_requests);
    // Handling requests
    handle_requests(requests);
    
    close(client_fd);
}
