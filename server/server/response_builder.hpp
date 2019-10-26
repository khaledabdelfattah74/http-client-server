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
#include "request.hpp"

using namespace std;

char* build_response(request* req);

#endif /* response_builder_hpp */
