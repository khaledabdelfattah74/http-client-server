//
//  constants.hpp
//  client
//
//  Created by Khaled Abdelfattah on 11/2/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef constants_hpp
#define constants_hpp

#define PORT 80
#define LOCALHOST "localhost"
#define BUFFER_SIZE 262144
#define HTTP "HTTP/1.1"
#define CLIENT_GET "client_get"
#define CLIENT_POST "client_post"

enum REQUEST_TYPE {
    GET,
    POST
};

enum STATUS {
    OK,
    NOT_FOUND
};

#endif /* constants_hpp */
