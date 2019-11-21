//
//  client_manager.cpp
//  client
//
//  Created by Khaled Abdelfattah on 10/25/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "client_manager.hpp"

void Client::initiate(string host_name, int port_number) {
    vector<string> client_requests = read_from_file("/Users/khaledabdelfattah/Documents/workspace/networks/HTTP-Client-Server/client/client/input_file.txt");
    // Parsing requests
    map<pair<string, int>, vector<request*>> requests = parse_client_requests(client_requests);
    // Handling requests
    for (map<pair<string, int>, vector<request*>>::iterator itr = requests.begin();
         itr != requests.end(); itr++) {
        handle_requests(itr->second);
    }
}
