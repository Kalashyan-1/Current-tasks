#ifndef CONC_SUP_
#define CONC_SUP_
#include "supermarket.h"
class ConcrateSupermarket : public Supermarket {
public:
    ConcrateSupermarket(std::vector<std::vector<Product*>> vec) : Supermarket(vec) {}
    void addProduct(Product* p) {products.addProduct(p);}
};


#endif //CONC_SUP_