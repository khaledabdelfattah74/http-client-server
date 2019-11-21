//
//  request.hpp
//  client
//
//  Created by Khaled Abdelfattah on 11/2/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#ifndef request_hpp
#define request_hpp

#include <map>
#include <string>
#include <fstream>
#include "constants.hpp"

using namespace std;

typedef struct request {
    int client_socket_fd;
    int port_number=PORT;
    long long int request_length;
    enum REQUEST_TYPE request_type;
    string file_path;
    string protocol;
    char* body;
    // map with key is the header type and value is the value of this header
    map<string, string> headers;
    
    long long int get_content_length() {
        long long int length = atoi(this->headers["Content-Length"].c_str());
        return length;
    }
    
    void set_content_length(long contetnt_length) {
        this->headers["Content-Length"] = to_string(contetnt_length);
    }
    
    void buid_request_body() {
        string headers = "";
        if (this->request_type == GET)
            headers += "GET ";
        else
            headers += "POST ";
        headers += ("/" + this->file_path + " ");
        headers += HTTP;
        headers += "\r\n";
        for (map<string, string>::iterator header = this->headers.begin(); header != this->headers.end();
             header++) {
            headers += (header->first + ": " + header->second + "\r\n");
        }
        if (this->request_type == GET) {
            headers += "\r\n";
            this->body = new char[headers.length()];
            headers.copy(this->body, headers.length());
            this->request_length = headers.size();
        } else {
            string path = "/Users/khaledabdelfattah/Documents/workspace/networks/HTTP-Client-Server/client/client/storage/" + this->file_path;
            ifstream infile;
            infile.open(path, ios::in | ios::binary | ios::ate);
            long long int length = infile.tellg();
            this->set_content_length(length);
            headers += "Content-Length: " + to_string(length) + "\r\n\r\n";
            infile.seekg (0, ios::beg);
            char file_content[length];
            infile.read(file_content, length);
            this->request_length = length + headers.length() + 2;
            this->body = new char[this->request_length];
            int i = 0;
            for (; i < headers.length(); i++)
                this->body[i] = headers[i];
            for (int j = 0; j < this->get_content_length(); i++, j++)
                this->body[i] = file_content[j];
            this->body[i++] = '\r';
            this->body[i] = '\n';
        }
    }
} request;


#endif /* request_hpp */
