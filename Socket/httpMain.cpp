#include "httpRequest.hpp"
#include "httpRequest.cpp"
#include "client.cpp"

int main() {
    std::string serv_ip = "127.0.0.1";
    std::string request = "GET / HTTP/1.1\r\n"
                         "Host: " + serv_ip + "\r\n"
                         "Connection: close\r\n"
                         "\r\n";

    HttpRequest req(8080, serv_ip);
    req.CreatSocket(IPV::IPv4, SocketType::TCP);
    req.Connect();
    req.getReq(request);
    req.Run();
}