#ifndef DB_
#define DB_

#include <map>
#include <vector>
#include "product.h"

class DataBase {
private:
    std::map<std::string, std::pair<Product*, int>> data;
public:
    DataBase(std::vector<std::vector<Product*>>);
    void addProduct(Product*);
    std::map<std::string, std::pair<Product*, int>>& getData();
};

#endif //DB_
