#ifndef CONC2_
#define CONC2_
#include "product.h"
class ConcrateProd2 : public Product {    
public:
    ConcrateProd2(const std::string& str, double d, Sale s) : Product(str, d, s) {};
    double getPrice() const override;
    std::string getName() const override;
    Sale getSale() const override;
};

#endif //CONC2_