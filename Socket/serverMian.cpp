#include "server.hpp"

int main() {
    Server server(8080);
    server.CreatSocket(IPV::IPv4, SocketType::UDP);
    server.Bind();
    server.Listen(1);
    server.Accept();
    server.Run();
}