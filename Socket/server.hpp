#ifndef SERVER_
#define SERVER_

#include "include.h"
#include <sstream>

class Server {
public:
    Server(unsigned int);
    ~Server();

    virtual void CreatSocket(IPV version, SocketType type = SocketType::TCP);
    void Bind();
    void Listen(unsigned int);
    void Accept();
    void Run();

private:
    virtual void hendleExecutiuon();
    void RunTCP();
    void RunUDP();

protected:
    void SetUP(IPV version);

protected:
    SocketType type;
    IPV version;
    unsigned int port;
    int server_fd;
    int new_socket;
    struct sockaddr_storage serv_address;
};

#endif