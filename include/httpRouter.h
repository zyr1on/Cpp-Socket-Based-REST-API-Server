#pragma ocne

#include <unordered_map>
#include <functional>
#include <winsock2.h>
#include <iostream>

class HttpRouter
{
private:
    std::unordered_map<std::string, std::function<std::string()>> routes;

public:
    HttpRouter();
    void handleRequst(SOCKET client_socket, const std::string &exactPath);
};
