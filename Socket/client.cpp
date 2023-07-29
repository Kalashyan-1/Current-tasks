#include "client.hpp"

Client::Client(const std::string& serverIP, unsigned int Port) : server_IP{serverIP}, port{Port} {}

Client::~Client() noexcept {
    close(sock);
}

void Client::CreatSocket(IPV version, SocketType type) {
    if ((sock = socket(static_cast<int>(version), static_cast<int>(type), 0)) == 0) {
            throw std::runtime_error("Socket creation failed");
    }
    SetUP(version);
}

void Client::SetUP(IPV version) {
     if (version == IPV::IPv4) {
        struct sockaddr_in *addr_in = (struct sockaddr_in *)&address;
         addr_in->sin_family = static_cast<int>(IPV::IPv4);
         addr_in->sin_port = htons(port);

        if (inet_pton(static_cast<int>(IPV::IPv4), server_IP.c_str(), &addr_in->sin_addr) <= 0) {
            throw std::runtime_error("\nInvalid address or Address not supported\n");
        }
    } else {
        struct sockaddr_in6 *addr_in6 = (struct sockaddr_in6 *)&address;
        addr_in6->sin6_family = static_cast<int>(IPV::IPv6); 
        addr_in6->sin6_port = htons(port);

        if (inet_pton(static_cast<int>(IPV::IPv6), server_IP.c_str(), &addr_in6->sin6_addr) <= 0) {
            throw std::runtime_error("\nInvalid address or Address not supported\n");
        }
    }
}

void Client::Connect() {
    if (connect(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
        throw std::runtime_error("\nConnection Failed\n");
    }
}
void Client::Run() {
    std::cout << "BBBBB";
    exec();
}

void Client::exec() {
    int valread;
    std::string str;
    char buffer[1024];
     while (1) {
        std::cout << "Enter a message to send to the server (or 'exit' to quit):\n ";
        std::getline(std::cin, str);

        send(sock, str.c_str(), str.size(), 0);

        if (str == "exit") {
            break;
        }

       
        str.clear();
        memset(buffer, 0, sizeof(buffer));

        valread = read(sock, buffer, sizeof(buffer));
        std::cout << "Srever: " << buffer << std::endl;

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        memset(buffer, 0, sizeof(buffer));
    }
}