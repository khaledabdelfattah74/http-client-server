//
//  response.hpp
//  server
//
//  Created by Khaled Abdelfattah on 11/1/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef response_hpp
#define response_hpp

#include <map>
#include <string>

using namespace std;

typedef struct response {
    enum REQUEST_TYPE request_type;
    string status;
    map<string, string> headers;
    char* body;
} response;

#endif /* response_hpp */
