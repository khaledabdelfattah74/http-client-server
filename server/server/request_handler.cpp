//
//  request_handler.cpp
//  server
//
//  Created by Khaled Abdelfattah on 10/25/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "request_handler.hpp"

response* handle_request(request* request) {
    response* response = build_response(request);
    return response;
}
