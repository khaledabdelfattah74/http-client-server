//
//  constants.hpp
//  server
//
//  Created by Khaled Abdelfattah on 10/25/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef constants_hpp
#define constants_hpp

#define BUFFER_SIZE 4096

#define OK_STATUS "HTTP/1.1 200 OK\r\n"
#define NOT_FOUND_STATUS "HTTP/1.1 404 Not Found\r\n"

enum REQUEST_TYPE {
    GET,
    POST
};

#endif /* constants_hpp */
