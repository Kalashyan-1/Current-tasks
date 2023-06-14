#ifndef CONC1_
#define CONC1_
#include "product.h"
class ConcrateProd1 : public Product {    
public:
    ConcrateProd1(const std::string& str, double d, Sale s) : Product(str, d, s) {};
    double getPrice() const override;
    std::string getName() const override;
    Sale getSale() const override;
};

#endif