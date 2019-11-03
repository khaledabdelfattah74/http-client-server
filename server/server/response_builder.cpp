//
//  response_builder.cpp
//  server
//
//  Created by Khaled Abdelfattah on 10/26/19.
//  Copyright © 2019 Khaled Abdelfattah. All rights reserved.
//

#include "response_builder.hpp"

map <string, string> EXTENSIONS = {
    {"png", "image/png"},
    {"gpg", "image/gpg"},
    {"html", "text/html"},
    {"txt", "text/plain"},
    {"", "text/plain"}
};

void set_response_content(ifstream&, response*);
string get_file_extension(string);

response* build_response(request* req) {
    response* response = new struct response();
    string path = "/Users/khaledabdelfattah/Documents/workspace/networks/HTTP-Client-Server/server/server/public" + req->file_path;
    if (req->request_type == GET) {
        response->request_type = GET;
        ifstream infile;
        infile.open(path, ios::in | ios::binary | ios::ate);
        if (!infile) {
            response->status = NOT_FOUND_STATUS;
            infile.close();
        } else {
            response->status = OK_STATUS;
            response->set_content_type(EXTENSIONS[get_file_extension(req->file_path)]);
            response->set_connection_status("keep-alive");
            set_response_content(infile, response);
            infile.close();
            response->build_response_body();
        }
    } else if (req->request_type == POST) {
        ofstream outfile;
        outfile.open(path, ios::out | ios::binary);
        outfile.write(req->body, req->get_content_length());
        outfile.close();
        response->status = OK_STATUS;
        response->build_response_body();
    }
    return response;
}

void set_response_content(ifstream& infile, response* response) {
    long long int length = infile.tellg();
    response->set_content_length(length);

    response->body = new char[length];
    infile.seekg (0, ios::beg);
    infile.read(response->body, length);
}

string get_file_extension(string file_name) {
    vector<string> tokens = split(file_name, ".");
    if (tokens.size() == 1)
        return "";
    else
        return tokens[1];
}
