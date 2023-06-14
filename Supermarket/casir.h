#ifndef CASIR_
#define CASIR_
#include "client.h"
#include <cmath>

class Casir {
private:
    std::string name;
public:
    Casir(const std::string& str) : name {str} {}
    int getProducts(std::vector<Product*>);
};


#endif   //CASIR_
