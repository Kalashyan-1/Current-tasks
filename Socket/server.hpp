#ifndef SERVER_
#define SERVER_

#include "include.h"

class Server {
public:
    Server(unsigned int);
    ~Server();

    void CreatSocket(IPV version, SocketType type);
    void Bind();
    void Listen(unsigned int);
    void Accept();
    void Run();

private:
    void SetUP(IPV version);
    void RunTCP();
    void RunUDP();
private:
    SocketType type;
    IPV version;
    unsigned int port;
    int server_fd;
    int new_socket;
    struct sockaddr_storage serv_address;
};

#endif