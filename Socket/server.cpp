#include "server.hpp"


Server::Server(unsigned int Port) :  port{Port}, server_fd {0} {}

Server::~Server() {
    close(new_socket);
    close(server_fd);
}

void Server::CreatSocket(IPV v, SocketType t) {
    type = t;
    version = v;
    if ((server_fd = socket(static_cast<int>(v), static_cast<int>(t), 0)) == 0) {
            throw std::runtime_error("Socket creation failed");
    }
    SetUP(v);
}

void Server::SetUP(IPV version) {
    if (version == IPV::IPv4) {
        struct sockaddr_in *addr_in = (struct sockaddr_in *)&serv_address;
        addr_in->sin_family = AF_INET;
        addr_in->sin_addr.s_addr = INADDR_ANY;
        addr_in->sin_port = htons(port);
    } else {
        struct sockaddr_in6 *addr_in6 = (struct sockaddr_in6 *)&serv_address;
        addr_in6->sin6_family = AF_INET6;  // Change to AF_INET6
        addr_in6->sin6_addr = in6addr_any; // Use IN6ADDR_ANY_INIT for IPv6
        addr_in6->sin6_port = htons(port);
    }
}

void Server::Bind() {
     if (bind(server_fd, (struct sockaddr *)&serv_address, sizeof(serv_address)) < 0) {
        throw std::runtime_error("Bind failed");
    }
}


void Server::Listen(unsigned int) {
    if (type == SocketType::TCP) {
        if (listen(server_fd, 3) < 0) {
            throw std::runtime_error("Listen failed");
        }
    }
}


void Server::Accept() {
    if (type == SocketType::TCP) {
        socklen_t addrlen = sizeof(serv_address);
        if ((new_socket = accept(server_fd, (struct sockaddr *)&serv_address, (socklen_t *)&addrlen)) < 0) {
            throw std::runtime_error("Accept failed");
        }
    }
}

void Server::Run() {
    hendleExecutiuon();
}

void Server::hendleExecutiuon() {
    if (type == SocketType::TCP) {
        RunTCP();
    } else {
        RunUDP();
    }
}

void Server::RunTCP() {
    char buffer[1024] {0};
     int valRead;
     std::string str;
     while (1) {
        memset(buffer, 0, sizeof(buffer));
        valRead = recv(new_socket, buffer, sizeof(buffer), 0);
        if (valRead <= 0) {break;}
        std::cout << "Client: " << buffer << std::endl;

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        memset(buffer, 0, sizeof(buffer));

        printf("Enter a message to send to the client (or 'exit' to quit):\n ");
        getline(std::cin, str);
        send(new_socket, str.c_str(), str.size(), 0);

        if (str == "exit") {
            break;
        }

        str.clear();
    }
}

void Server::RunUDP() {
    char buffer[1024] {0};
     int valRead;
     std::string str;
     socklen_t addrlen = sizeof(serv_address);
     while (1) {
        valRead = recvfrom(server_fd, buffer, sizeof(buffer), 0, (struct sockaddr *)&serv_address, &addrlen);
        if (valRead <= 0) {
            break;
        }
        std::cout << "Client: " << buffer << std::endl;

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        memset(buffer, 0, sizeof(buffer));

        std::cout << "Enter a message to send to the client (or 'exit' to quit):\n ";
        getline(std::cin, str);
        sendto(server_fd, str.c_str(), str.size(), 0, (struct sockaddr *)&serv_address, addrlen);

        if (str == "exit") {
            break;
        }
        str.clear();
    }
}