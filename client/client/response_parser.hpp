//
//  response_parser.hpp
//  client
//
//  Created by Khaled Abdelfattah on 11/2/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef response_parser_hpp
#define response_parser_hpp

#include <stdio.h>
#include <string>
#include "../../server/server/utilities.hpp"
#include "response.hpp"

using namespace std;

response* parse_response(string);

#endif /* response_parser_hpp */
