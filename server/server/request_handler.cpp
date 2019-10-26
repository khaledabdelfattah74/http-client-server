//
//  request_handler.cpp
//  server
//
//  Created by Khaled Abdelfattah on 10/25/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "request_handler.hpp"

char* handle_request(string request_body) {
    request* req = parse_request(request_body);
    char *response = build_response(req);
    return response;
}
