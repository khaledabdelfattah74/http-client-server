//
//  request_handler.hpp
//  client
//
//  Created by Khaled Abdelfattah on 11/2/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef request_handler_hpp
#define request_handler_hpp

#include <stdio.h>
#include <vector>
#include "request.hpp"
#include "socket_manager.hpp"
#include "response_parser.hpp"
#include "file_reader.hpp"
#include "response_manager.hpp"

using namespace std;

void handle_request(request*);
void handle_requests(vector<request*>);

#endif /* request_handler_hpp */
