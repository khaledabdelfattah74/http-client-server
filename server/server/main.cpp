//
//  main.cpp
//  server
//
//  Created by Khaled Abdelfattah on 10/24/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include <iostream>
#include "server_manager.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Server* server = new Server();
    server->initiate();
    return 0;
}
