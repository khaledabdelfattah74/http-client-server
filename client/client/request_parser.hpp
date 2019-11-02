//
//  request_parser.hpp
//  client
//
//  Created by Khaled Abdelfattah on 11/2/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef request_parser_hpp
#define request_parser_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "request.hpp"
#include "../../server/server/utilities.hpp"

using namespace std;

request* parse_client_request(string);
vector<request*> parse_client_requests(vector<string>);

#endif /* request_parser_hpp */
