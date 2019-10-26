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
    vector<string> lines = split(request_body, "\r\n");
    request* parsed_request = new request();
    parse_request_line(parsed_request, lines[0]);
    vector<string> headers(lines.begin() + 1, lines.end());
    parse_request_headers(parsed_request, headers);
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
