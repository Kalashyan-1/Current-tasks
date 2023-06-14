#include "dataBase.h"


DataBase::DataBase(std::vector<std::vector<Product*>> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        data[vec[i][0]->getName()] = {vec[i][0], vec[i].size()};
    }
}

void DataBase::addProduct(Product* p) {
    auto it = data.find(p->getName());
     if (it != data.end()) {
        it->second.second++;
    } else {
        data[p->getName()] = {p, 0};
    }
}

std::map<std::string, std::pair<Product*, int>>& DataBase::getData(){
    return data;
}
