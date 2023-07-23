#ifndef CLIENT_
#define CLIENT_

#include <iostream>
#include <string>
#include "include.h"
#include <arpa/inet.h>

class Client {
public:
    Client(const std::string&, unsigned int);
    ~Client();

    void CreatSocket(IPV, SocketType);
    void Connect();
    void Run();

private:   
    void SetUP(IPV);
private:
    int sock;
    std::string server_IP;
    unsigned int port;
    struct sockaddr_storage address;
};

#endif  //CLIENT_