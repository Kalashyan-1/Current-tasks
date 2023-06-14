#ifndef SUPERMARKET_
#define SUPERMARKET_
#include "dataBase.h"
class Supermarket
{
protected:
    DataBase products;
public:
    Supermarket(std::vector<std::vector<Product*>> vec) : products(vec) {}
    virtual void addProduct(Product* p) = 0;
    DataBase& getProducts() {return products;}
};


#endif //SUPERMARKET_