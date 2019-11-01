//
//  response.hpp
//  server
//
//  Created by Khaled Abdelfattah on 11/1/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef response_hpp
#define response_hpp

#include <stdio.h>
#include <map>
#include <string>

using namespace std;

typedef struct response {
    enum REQUEST_TYPE request_type;
    string status;
    map<string, string> headers;
    char* body;
    
    void set_request_type(enum REQUEST_TYPE type) {
        this->request_type = type;
    }
    
    void set_status(string status) {
        this->status = status;
    }
    
    void set_content_type(string content_type) {
        this->headers["Content-Type"] = content_type;
    }
    
    void set_content_length(long contetnt_length) {
        this->headers["Content-Length"] = to_string(contetnt_length);
    }
    
    void set_connection_status(string connection_status) {
        this->headers["Connection"] = connection_status;
    }
    
    void set_body_content(char* body) {
        this->body = body;
    }
    
    long long int get_content_length() {
        long long int length = atoi(this->headers["Content-Length"].c_str());
        return length;
    }
} response;

#endif /* response_hpp */
