#include "HttpRouter.h"
#include <ws2tcpip.h>
#include <jwt-cpp/jwt.h>

#pragma commenct(lib, "ws2_32.lib")

SOCKET initSocket();
constexpr auto stringNotFound = std::string::npos;

HttpRouter router;

int main(int argc, char const *argv[])
{
    SOCKET server_fd = initSocket();
    while (true)
    {
        SOCKET client_socket = accept(server_fd, NULL, NULL);
        if (client_socket == INVALID_SOCKET)
        {
            std::cerr << "Accept Failed\n";
            continue;
        }
        char buffer[4096] = {0};
        int valread = recv(client_socket, buffer, sizeof(buffer), 0);
        if (valread > 0)
        {
            std::string request(buffer, valread); // comes from client to server with recv()

            size_t firtSpace = request.find(' ');
            size_t secondSpace = request.find(' ', firtSpace + 1);

            std::string path = request.substr(firtSpace + 1, secondSpace - (firtSpace + 1));
            std::string method = request.substr(0, firtSpace);
            std::string last = method + " " + path;
            std::cout << last << std::endl;

            router.handleRequst(client_socket, last);
        }
        closesocket(client_socket);
    }

    closesocket(server_fd);
    WSACleanup();

    return 0;
}

SOCKET initSocket() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup Failed\n";
        return 1;
    }
    SOCKET server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == INVALID_SOCKET)
    {
        std::cerr << "Socket creating failed\n";
        return 1;
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_fd, (sockaddr *)&address, sizeof(address)) == SOCKET_ERROR)
    {
        std::cerr << "Bind failed\n";
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }
    if (listen(server_fd, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cerr << "Listen failed\n";
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }
    std::cout << "Server woke up at: http://localhost:8080\n";
    return server_fd;
}
