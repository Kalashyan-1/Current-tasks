#ifndef CLIENT_
#define CLIENT_
#include <string>
#include "product.h"
#include <vector>
#include <iostream>
#include "supermarket.h"
class Client
{
private:
    std::string name;
    std::vector<Product*> cart;
    double wallet;
public:
    Client(const std::string& str, double w) : name {str}, wallet{w} {};
    std::vector<Product*> getProducts();
    void addProduct(Supermarket*, const std::string& prodName);
    void pay(int total);
};

#endif //CLIENT_