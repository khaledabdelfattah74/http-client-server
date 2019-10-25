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
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string>

using namespace std;

#define PORT 80

class Client {
public:
    void initiate(int port_number=PORT);
};

#endif /* client_manager_hpp */
