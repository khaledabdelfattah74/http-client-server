//
//  client_manager.hpp
//  client
//
//  Created by Khaled Abdelfattah on 10/25/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef client_manager_hpp
#define client_manager_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "socket_manager.hpp"
#include "file_reader.hpp"
#include "request_parser.hpp"
#include "request_handler.hpp"

using namespace std;

class Client {
public:
    void initiate(string host_name=LOCALHOST, int port_number=PORT);
};

#endif /* client_manager_hpp */
