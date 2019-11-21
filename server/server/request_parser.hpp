//
//  request_parser.hpp
//  server
//
//  Created by Khaled Abdelfattah on 10/25/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef request_parser_hpp
#define request_parser_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "request.hpp"
#include "utilities.hpp"

using namespace std;

request* parse_request(string request_body);

#endif /* request_parser_hpp */
