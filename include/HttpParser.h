#pragma once

#include<string>
#include<unordered_map>
#include<iostream>
#include<sstream>

struct ParsedRequest {
    std::string method;
    std::string path;
    std::string body;
    std::unordered_map<std::string,std::string> headers;
    void clear(){
        method.clear();
        path.clear();
        body.clear();
        headers.clear();
    }
}; 

class HttpParser{
public:
    static void parseRequest(const std::string& rawRequest,ParsedRequest& parsed) {
        parsed.clear();
        std::istringstream stream(rawRequest);
        std::string line;
        if(std::getline(stream,line)){
            std::istringstream firstLine(line);
            firstLine >> parsed.method >> parsed.path;
        }
        while(std::getline(stream,line) && line != "\r" && !line.empty() ){
            size_t colonPos = line.find(":");
            if(colonPos != std::string::npos){
                std::string key = line.substr(0,colonPos);
                std::string value = line.substr(colonPos + 2);
                if(!value.empty() && value.back() == '\r') {
                    value.pop_back();
                }
                parsed.headers[key] = value;
            }
        } 
    }
};
