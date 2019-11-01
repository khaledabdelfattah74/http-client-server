//
//  request.hpp
//  server
//
//  Created by Khaled Abdelfattah on 10/25/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef request_hpp
#define request_hpp

#include <map>
#include <string>
#include "constants.hpp"

using namespace std;

typedef struct request {
    int client_socket_fd;
    enum REQUEST_TYPE request_type;
    string file_path;
    string protocol;
    string body;
    // map with key is the header type and value is the value of this header
    map<string, string> headers;
} request;

#endif /* request_hpp */
