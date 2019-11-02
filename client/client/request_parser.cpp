//
//  request_parser.cpp
//  client
//
//  Created by Khaled Abdelfattah on 11/2/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "request_parser.hpp"

request* parse_client_request(string client_request) {
    request* request = new struct request();
    vector<string> attributes = split(client_request, " ");
    vector<string>::iterator iter = attributes.begin();
    if (*iter == CLIENT_GET)
        request->request_type = GET;
    else if (*iter == CLIENT_POST)
        request->request_type = POST;
    
    iter++;
    request->file_path = *iter;
    iter++;
    request->headers["Host"] = *iter;
    iter++;
    if (iter != attributes.end())
        request->port_number = atof((*iter).c_str());
    
    request->headers["Connection"] = "Keep-Alive";
    request->headers["User-Agent"] = "HTTP-Client";
    
    return request;
}

vector<request*> parse_client_requests(vector<string> client_requests) {
    vector<request*> requests;
    for (string client_request : client_requests)
        requests.push_back(parse_client_request(client_request));
    return requests;
}
