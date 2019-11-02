//
//  file_reader.hpp
//  client
//
//  Created by Khaled Abdelfattah on 11/1/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef file_reader_hpp
#define file_reader_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "response.hpp"

using namespace std;

vector<string> read_file(string);
void write_into_file(string, char*, long long int);

#endif /* file_reader_hpp */
