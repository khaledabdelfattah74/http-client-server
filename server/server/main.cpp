//
//  main.cpp
//  server
//
//  Created by Khaled Abdelfattah on 10/24/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include <iostream>
#include "server_manager.hpp"
#include "utilities.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
//    string x = "hello\r\nfrom\r\nthe\r\nother\r\nside\r\n\r\n";
//    vector<string> lines = split(x, "\r\n");
//    for (string i : lines)
//        cout << i << endl;
//    cout << (*(lines.begin())) << endl;
//    cout << (*(lines.end() - 1)) << endl;
    string header = "header: value";
    size_t idx = header.find_first_of(':');
    cout << header.substr(0, idx) << endl;
    cout << header.substr(idx + 1) << endl;
    Server* server = new Server();
    server->initiate();
    return 0;
}
