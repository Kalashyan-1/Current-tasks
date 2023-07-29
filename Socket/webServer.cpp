#include "webServer.hpp"

 const std::string RESPONSE_TEMPLATE = 
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "\r\n"
        "<!DOCTYPE html>\r\n"
        "<html>\r\n"
        "<head><title>Simple Web Server</title></head>\r\n"
        "<body><h1>Hello, World!</h1></body>\r\n"
        "</html>\r\n";

WebServer::WebServer(unsigned int Port) : Server(Port){}

WebServer::~WebServer() noexcept {}

void WebServer::CreatSocket(IPV v, SocketType t) {
    if (t == SocketType::UDP) {
        throw std::runtime_error("This querry works only with TCP\n");
    }
    type = t;
    version = v;
    if ((server_fd = socket(static_cast<int>(v), static_cast<int>(t), 0)) == 0) {
            throw std::runtime_error("Socket creation failed");
    }
    SetUP(v);
}

void WebServer::hendleExecutiuon() {
    char buffer[1024] = {0};
    recv(new_socket, buffer, sizeof(buffer), 0);

    std::istringstream request(buffer);
    std::string method, path, protocol;
    request >> method >> path >> protocol;

    // Respond with a simple HTML document
    if (method == "GET") {
        send(new_socket, RESPONSE_TEMPLATE.c_str(), RESPONSE_TEMPLATE.size(), 0);
    } else {
        std::string error_response =
            "HTTP/1.1 400 Bad Request\r\n"
            "Content-Type: text/plain\r\n"
            "\r\n"
            "Bad Request: Only GET method is supported\r\n";
        send(new_socket, error_response.c_str(), error_response.size(), 0);
    }
}