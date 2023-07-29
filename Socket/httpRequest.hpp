#ifndef HTTP_REC_HPP_
#define HTTP_REC_HPP_

#include "client.hpp"
#include <fstream>

class HttpRequest : public Client{
public:
    HttpRequest(std::size_t Port, const std::string& IP);
    ~HttpRequest() noexcept;
    void getReq(const std::string&);
    void CreatSocket(IPV, SocketType) override;

private:
    virtual void exec() override;

private:    
    std::string  request;
};

#endif  // HTTP_REC_HPP_
