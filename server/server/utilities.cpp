//
//  utilities.cpp
//  server
//
//  Created by Khaled Abdelfattah on 10/26/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "utilities.hpp"

string& left_trim(string& str, const string& delimaters) {
    str.erase(0, str.find_first_not_of(delimaters));
    return str;
}

string& right_trim(string& str, const string& delimaters) {
    str.erase(str.find_last_not_of(delimaters) + 1);
    return str;
}

string& trim(string& str, const string& delimaters) {
    left_trim(str);
    right_trim(str);
    return str;
}

string erase_char (string* str, char c) {
    str->erase(remove(str->begin(), str->end(), c), str->end());
    return *str;
}

string remove_trailing_spaces (string str) {
    string new_str = "";
    istringstream stream(str);
    string temp_str;
    while (stream >> temp_str) {
        new_str += temp_str;
        new_str += ' ';
    }
    trim(new_str);
    return new_str;
}

string concatenate_lines (vector<string> lines) {
    string concatenated_string = "";
    for (string line : lines) {
        concatenated_string += remove_trailing_spaces(line);
        concatenated_string += " ";
    }
    trim(concatenated_string);
    return concatenated_string;
}

vector<string> split(string input, const char *delimiter) {
    vector<string> lines;
    char *cstr = new char[input.length() + 1];
    strcpy(cstr, input.c_str());
    char* pch = strtok(cstr, delimiter);
    while (pch != NULL) {
        string s(pch);
        remove_trailing_spaces(s);
        lines.push_back(s);
        pch = strtok(NULL, delimiter);
    }
    return lines;
}
