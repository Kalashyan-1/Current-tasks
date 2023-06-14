#ifndef PRODUCT_
#define PRODUCT_

#include <string>

enum Sale {
    BuyTwoGetOneFree,
    BuyThreeGetOneFree,
    NONE
};

class Product {
protected:
    std::string name;
    double price;
    Sale sale;
public:
    Product(const std::string& n, double p, Sale s) : name {n}, price {p}, sale {s} {};
    virtual double getPrice() const =0;
    virtual std::string getName() const = 0;
    virtual Sale getSale() const = 0;
};
#endif //PRODUCT_