#include "client.h"

void Client::addProduct(Supermarket* sup, const std::string& prodName) {
    auto it = sup->getProducts().getData().find(prodName);
    if (it != sup->getProducts().getData().end()) {
         cart.push_back(it->second.first);
    } 
}

std::vector<Product*> Client::getProducts() {
    auto tmp = cart;
    cart.clear();
    return tmp;
}

void Client::pay(int total) {
    if (wallet < total) {
        std::cout << "Client can not pay";
    } else {
        std::cout << "Payed Successfully";
        wallet -= total;
    }
}
