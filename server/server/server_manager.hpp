//
//  server_manager.hpp
//  server
//
//  Created by Khaled Abdelfattah on 10/24/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef server_manager_hpp
#define server_manager_hpp

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>

using namespace std;

#define PORT 80
#define BACKLOG_COUNT 1000

class Server {
public:
    void initiate(int port_number=PORT);
};

#endif /* server_manager_hpp */
