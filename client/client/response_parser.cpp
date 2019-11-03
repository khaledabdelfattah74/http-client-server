//
//  response_parser.cpp
//  client
//
//  Created by Khaled Abdelfattah on 11/2/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "response_parser.hpp"

void parse_response_status(response*, string);
void parse_response_headers(response*, vector<string>);
void parse_response_content(response*, char*, long long int, long long int);

response* parse_response(char* body) {
    response* response = new struct response();
    string body_str = body;
    long long int seperate_line_index = body_str.find("\r\n\r\n");
    vector<string> headers = split(body_str.substr(0, seperate_line_index), "\r\n");
    
    parse_response_status(response, headers[0]);
    parse_response_headers(response, vector<string>(headers.begin() + 1, headers.end()));
    
    if (response->status == OK && seperate_line_index + 4 != string::npos) {
        long long int length = response->get_content_length(),
            idx = seperate_line_index + 4;
        parse_response_content(response, body, idx, length);
    }
    return response;
}

void parse_response_status(response* response, string status) {
    if (status == OK_STATUS)
        response->status = OK;
    else if (status == NOT_FOUND_STATUS)
        response->status = NOT_FOUND;
}

void parse_response_headers(response* response, vector<string> headers) {
    for (string header : headers) {
        size_t coln_pos = header.find_first_of(':');
        if (!coln_pos)
            continue;
        string key = header.substr(0, coln_pos);
        string value = header.substr(coln_pos + 2);
        response->headers[key] = value;
    }
}

void parse_response_content(response* response, char* body,
                            long long int start_idx, long long int length) {
    response->content = new char[length];
    for (int i = 0; i < length; i++)
        response->content[i] = body[start_idx + i];
}
