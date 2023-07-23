#include "client.hpp"

int main() {
    Client c("127.0.0.1", 8080);
    c.CreatSocket(IPV::IPv4, SocketType::UDP);
    c.Connect();
    c.Run();
}