#pragma once
#include <iostream>

std::string 
indexResponse()
{
        std::string html = 
        "<!DOCTYPE html>"
        "<html>"
        "<head>"
            "<title>Hello </title>"
            "<meta charset='utf-8'>"
            "<style>"
                "body { font-family: Arial; margin: 50px; background-color: #f4f4f4; }"
                "h1 { color: #333; }"
                ".container { background: white; padding: 20px; border-radius: 8px; }"
            "</style>"
        "</head>"
        "<body>"
            "<div class='container'>"
                "<h1>🚀 Hello !</h1>"
                "<p>it works!!</p>"
                "<p>Port: 8080</p>"
                "<hr>"
                "<p><a href='/api/user/ID'>API Test</a></p>"
            "</div>"
        "</body>"
        "</html>";
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
        std::string html = 
        "<!DOCTYPE html>"
        "<html>"
        "<head>"
            "<title>Hello </title>"
            "<meta charset='utf-8'>"
            "<style>"
                "body { font-family: Arial; margin: 50px; background-color: #f4f4f4; }"
                "h1 { color: #333; }"
                ".container { background: white; padding: 20px; border-radius: 8px; }"
            "</style>"
        "</head>"
        "<body>"
            "<div class='container'>"
                "<h1>🚀 Hello !</h1>"
                "<p>it works!!</p>"
                "<p>Port: 8080</p>"
                "<hr>"
                "<p><a href='/api/user/ID'>API Test</a></p>"
            "</div>"
        "</body>"
        "</html>";
    std::string response =
        "HTTP/1.1 404 Not Found\r\n"
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
