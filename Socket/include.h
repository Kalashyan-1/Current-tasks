#ifndef INC_
#define INC_

#include <iostream>
#include <stdexcept>
#include <string.h>

#include <unistd.h> 
#include <sys/socket.h>
#include <netinet/in.h>

enum class IPV {
    IPv4 = AF_INET,
    IPv6 = AF_INET6
};

enum class SocketType {
    TCP = SOCK_STREAM,
    UDP = SOCK_DGRAM
};

#endif  //INC_