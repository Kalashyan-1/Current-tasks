#include "httpRequest.hpp"

HttpRequest::HttpRequest(std::size_t Port, const std::string& str) : Client(str, Port) {}

HttpRequest::~HttpRequest() noexcept {}

void HttpRequest::CreatSocket(IPV version, SocketType type) {
    if (type == SocketType::UDP) {   
        throw std::runtime_error("Socket creation failed");
    }

    if ((sock = socket(static_cast<int>(version), static_cast<int>(type), 0)) == 0) {
            throw std::runtime_error("Socket creation failed");
    }
    SetUP(version);
}

void HttpRequest::getReq(const std::string& str) {
    request = str;
    // send(sock, request.c_str(), request.size(), 0);
    if (send(sock, request.c_str(), request.size(), 0) < 0) {
        throw std::runtime_error("Send failed");
    }
}


void HttpRequest::exec() {
    std::cout << "AAAAA";
    std::ofstream outfile("response.html", std::ios::out | std::ios::binary);
    char buffer[1024];
    int bytes_received;
    while ((bytes_received = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        outfile.write(buffer, bytes_received);
    }
    outfile.close();
    system("open response.html");
}