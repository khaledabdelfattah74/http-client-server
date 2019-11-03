//
//  response_builder.hpp
//  server
//
//  Created by Khaled Abdelfattah on 10/26/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef response_builder_hpp
#define response_builder_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include "request.hpp"
#include "response.hpp"
#include "utilities.hpp"
#include "constants.hpp"

using namespace std;

response* build_response(request* req);

#endif /* response_builder_hpp */
