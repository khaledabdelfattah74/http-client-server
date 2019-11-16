//
//  connection_worker.hpp
//  server
//
//  Created by Khaled Abdelfattah on 10/26/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef connection_worker_hpp
#define connection_worker_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "request_handler.hpp"

using namespace std;

void establish_connection(int client_socket_fd);

#endif /* connection_worker_hpp */
