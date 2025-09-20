#pragma once
#include <iostream>

std::string 
indexResponse()
{
    std::string html = "<html><body><h1>Merhaba Windows!</h1></body></html>";
    std::string response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Lenght: " +std::to_string(html.size()) + "\r\n"
        "Connection: close\r\n"
        "\r\n" + html;
    return response;
}

std::string 
notFoundResponse()
{
    std::string html = "<html><body><h1>Not Found!</h1></body></html>";
    std::string response =
        "HTTP/1.1 404 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Lenght: " +
        std::to_string(html.size()) + "\r\n"
        "Connection: close\r\n"
        "\r\n" + html;
    return response;
}

std::string 
userIDResponse()
{
    return "HTTP/1.1 200 OK\r\n"
           "Content-Type: application/json"
           "\r\n"
           "\r\n"
           "{\"user\":{\"id\":1}}";
}
