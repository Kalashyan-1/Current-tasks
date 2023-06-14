#include "dataBase.h"
#include "concrateProd1.h"
#include "concrateProd2.h"
#include "concrateSupermarket.h"
#include "client.h"
#include "casir.h"

int main() {
    std::vector<std::vector<Product*>> initialProducts;
    ConcrateProd1 p1("name1", 2000, Sale::BuyThreeGetOneFree);
    ConcrateProd1 p2("name2", 3000, Sale::BuyTwoGetOneFree);
    initialProducts.push_back({&p1});
    initialProducts.push_back({&p2});
    ConcrateSupermarket supermarket(initialProducts);
    Client client("name", 20000);
    Casir casir("name");
    client.addProduct(&supermarket, "productName");
    client.pay(casir.getProducts(client.getProducts()));
}