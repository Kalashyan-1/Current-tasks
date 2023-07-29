#ifndef WEB_SERVER_HPP_
#define WEB_SERVER_HPP_

#include "server.hpp"

class WebServer : public Server {
public:
    WebServer(unsigned int Port);
    ~WebServer() noexcept;

    void CreatSocket(IPV version, SocketType type = SocketType::TCP) override;

private:
   void hendleExecutiuon() override;
};


#endif //WEB_SERVER_HPP_