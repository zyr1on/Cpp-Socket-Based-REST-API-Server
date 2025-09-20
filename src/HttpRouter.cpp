#include "HttpRouter.h"
#include "responses.h"

HttpRouter::HttpRouter()
{
    routes["GET /"] = indexResponse;
    routes["GET /index.html"] = indexResponse;
    routes["GET /api/user/ID"] = userIDResponse;
}
void HttpRouter::handleRequst(SOCKET client_socket, const std::string &exactPath)
{
    auto it = routes.find(exactPath);
    if (it != routes.end())
    {
        std::string response = it->second();
        send(client_socket, response.c_str(), response.size(), 0);
    }
    else
        send(client_socket, notFoundResponse().c_str(), notFoundResponse().size(), 0);
};
