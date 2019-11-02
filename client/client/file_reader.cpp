//
//  file_reader.cpp
//  client
//
//  Created by Khaled Abdelfattah on 11/1/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "file_reader.hpp"

vector<string> read_file(string path) {
    ifstream input_file(path);
    vector<string> lines;
    if (input_file.is_open()) {
        string line;
        while (getline(input_file, line)) {
            lines.push_back(line);
        }
        input_file.close();
    }
    return lines;
}

void write_into_file(string path, char* content, long long int size) {
    ofstream outfile;
    outfile.open(path, ios::out | ios::binary);
    outfile.write(content, size);
    outfile.close();
}
