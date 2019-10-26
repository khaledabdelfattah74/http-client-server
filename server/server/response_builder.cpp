//
//  response_builder.cpp
//  server
//
//  Created by Khaled Abdelfattah on 10/26/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "response_builder.hpp"

char* build_response(request* req) {
    char *response = "HTTP/1.1 200 OK\r\n\r\n";
    return response;
}
