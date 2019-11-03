//
//  socket_manager.hpp
//  client
//
//  Created by Khaled Abdelfattah on 11/2/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef socket_manager_hpp
#define socket_manager_hpp

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include "constants.hpp"

using namespace std;

int build_socket(string host_name=LOCALHOST, int port_number=PORT);
long long int send_through_socket(int, char[], long long int);
void read_from_socket(int, char[]);

#endif /* socket_manager_hpp */
