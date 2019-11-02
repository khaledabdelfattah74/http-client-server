//
//  request_parser.cpp
//  server
//
//  Created by Khaled Abdelfattah on 10/25/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "request_parser.hpp"

void parse_request_line(request *, string);
void parse_request_headers(request *, vector<string>);

request* parse_request(string request_body) {
    long long int seperate_line_index = request_body.find("\r\n\r\n");
    vector<string> headers = split(request_body.substr(0, seperate_line_index), "\r\n");
    
    request* parsed_request = new request();
    parse_request_line(parsed_request, headers[0]);
    parse_request_headers(parsed_request, vector<string>(headers.begin() + 1, headers.end()));

    if (seperate_line_index + 4 != string::npos) {
        long long int len = parsed_request->get_content_length(),
            idx = seperate_line_index + 4;
        parsed_request->body = new char[len];
        request_body.copy(parsed_request->body, len, idx);
    }
    return parsed_request;
}

void parse_request_line(request *req, string line) {
    vector<string> attributes = split(line, " ");
    if ((*attributes.begin()) == "GET")
        req->request_type = GET;
    else
        req->request_type = POST;
    if (attributes[1] == "/")
        req->file_path = "/index.html";
    else
        req->file_path = attributes[1];
    req->protocol = *(attributes.end() - 1);
}

void parse_request_headers(request *req, vector<string> headers) {
    for (string header : headers) {
        size_t coln_pos = header.find_first_of(':');
        if (!coln_pos)
            continue;
        string key = header.substr(0, coln_pos);
        string value = header.substr(coln_pos + 2);
        req->headers[key] = value;
    }
}
