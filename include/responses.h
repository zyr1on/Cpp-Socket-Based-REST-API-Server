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
        "<title>404 - Page Not Found</title>"
        "<meta charset='utf-8'>"
        "<style>"
            "body { font-family: Arial; margin: 50px; background-color: #f4f4f4; text-align: center; }"
            "h1 { color: #e74c3c; font-size: 72px; margin: 0; }"
            "h2 { color: #333; margin: 10px 0; }"
            ".container { background: white; padding: 40px; border-radius: 8px; box-shadow: 0 2px 10px rgba(0,0,0,0.1); }"
            ".error-code { color: #bdc3c7; font-size: 120px; font-weight: bold; margin: 0; line-height: 1; }"
            "a { color: #3498db; text-decoration: none; font-weight: bold; }"
            "a:hover { text-decoration: underline; }"
            ".back-btn { background: #3498db; color: white; padding: 12px 24px; border-radius: 5px; display: inline-block; margin-top: 20px; }"
            ".back-btn:hover { background: #2980b9; color: white; text-decoration: none; }"
        "</style>"
    "</head>"
    "<body>"
        "<div class='container'>"
            "<div class='error-code'>404</div>"
            "<h1>Oops!</h1>"
            "<h2>Page Not Found</h2>"
            "<p>The page you're looking for doesn't exist or has been moved.</p>"
            "<hr>"
            "<p><a href='/' class='back-btn'>Go Back Home</a></p>"
            "<p style='margin-top: 20px; color: #7f8c8d; font-size: 14px;'>"
                "Available endpoints: <a href='/'>Home</a> | <a href='/api/user/ID'>API Test</a>"
            "</p>"
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
