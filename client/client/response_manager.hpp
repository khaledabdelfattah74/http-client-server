//
//  response_manager.hpp
//  client
//
//  Created by Khaled Abdelfattah on 11/20/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef response_manager_hpp
#define response_manager_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <algorithm>
#include <vector>
#include <string>
#include "file_reader.hpp"
#include "response_parser.hpp"
#include "response.hpp"

using namespace std;

void read_responses(int);
void handle_response(response*);

#endif /* response_manager_hpp */
