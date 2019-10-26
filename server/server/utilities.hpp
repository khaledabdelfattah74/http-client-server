//
//  utilities.hpp
//  server
//
//  Created by Khaled Abdelfattah on 10/26/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef utilities_hpp
#define utilities_hpp

#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

string& left_trim (string& str, const string& delimaters = "\t\n\v\f\r ");
string& right_trim (string& str, const string& delimaters = "\t\n\v\f\r ");
string& trim (string& str, const string& delimaters = "\t\n\v\f\r ");
string erase_char (string* str, char ch);
string remove_trailing_spaces (string);
string concatenate_lines (vector<string>);
vector<string> split(string input, const char *delimiter);

#endif /* utilities_hpp */
