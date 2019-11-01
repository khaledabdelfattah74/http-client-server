//
//  response_builder.cpp
//  server
//
//  Created by Khaled Abdelfattah on 10/26/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "response_builder.hpp"

void process_get_request(ifstream&, response*);

response* build_response(request* req) {
    response* response = new struct response();
    if (req->request_type == GET) {
        response->request_type = GET;
        ifstream infile;
        string path = "/Users/khaledabdelfattah/Documents/workspace/networks/HTTP-Client-Server/server/server/public" + req->file_path;
        infile.open(path, ios::in | ios::binary | ios::ate);
        if (!infile) {
            response->status = NOT_FOUND_STATUS;
            infile.close();
        } else {
            response->status = OK_STATUS;
            process_get_request(infile, response);
            infile.close();
        }
    } else if (req->request_type == POST) {
        
    }
    return response;
}

void process_get_request(ifstream& infile, response* response) {
    long long int length = infile.tellg();
    response->headers["Content-Length"] = to_string(length);
    response->headers["Content-Type"] = "image/png";
    response->headers["Connection"] = "Keep-Alive";

    response->body = new char[length];
    infile.seekg (0, ios::beg);
    infile.read(response->body, length);
}
