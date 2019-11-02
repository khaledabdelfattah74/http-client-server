//
//  response.hpp
//  client
//
//  Created by Khaled Abdelfattah on 11/2/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef response_hpp
#define response_hpp

#include <map>
#include <string>
#include "constants.hpp"

using namespace std;

#define OK_STATUS "HTTP/1.1 200 OK"
#define NOT_FOUND_STATUS "HTPP/1.1 404 Not Found"

typedef struct response {
    enum STATUS status;
    map<string, string> headers;
    char* content;
    
    response() {}
    
    long long int get_content_length() {
        long long int length = atoi(this->headers["Content-Length"].c_str());
        return length;
    }
    
    void set_content_length(long contetnt_length) {
        this->headers["Content-Length"] = to_string(contetnt_length);
    }
} response;

#endif /* response_hpp */
