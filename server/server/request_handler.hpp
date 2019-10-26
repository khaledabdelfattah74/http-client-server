//
//  request_handler.hpp
//  server
//
//  Created by Khaled Abdelfattah on 10/25/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef request_handler_hpp
#define request_handler_hpp

#include <stdio.h>
#include <string>
#include "request_parser.hpp"
#include "response_builder.hpp"
#include "request.hpp"

using namespace std;

char *handle_request(string request_body);

#endif /* request_handler_hpp */
