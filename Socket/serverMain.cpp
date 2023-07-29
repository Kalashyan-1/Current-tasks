// #include "server.hpp"

#include "webServer.hpp"

int main() {
    // Server server(8080);
    // server.CreatSocket(IPV::IPv4, SocketType::TCP);
    // server.Bind();
    // server.Listen(1);
    // server.Accept();
    // server.Run();

    WebServer server(8080);
    server.CreatSocket(IPV::IPv4, SocketType::TCP);
    server.Bind();
    server.Listen(1);
    server.Accept();
    server.Run();
}