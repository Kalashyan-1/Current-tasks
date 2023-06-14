#include "casir.h"

int Casir::getProducts(std::vector<Product*> prods) {
    double res = 0;
    std::vector<std::pair<Product*, int>> three1;
    std::vector<std::pair<Product*, int>> two1;
      
    for (int i = 0; i < prods.size(); ++i) {
        switch (prods[i]->getSale())
        {
        case BuyThreeGetOneFree:
            if (three1.size() == 0) {
                three1.push_back({prods[i],0});
                break;
            }
            for (int i = 0; i < three1.size(); ++i) {
                if (prods[i]->getName() == three1[i].first->getName() && three1[i].second < 4) {
                    three1[i].second++;
                } else if (three1[i].second == 4) {
                    three1.push_back({prods[i],0});
                }
            }
            break;
        case BuyTwoGetOneFree:
            if (two1.size() == 0) {
                two1.push_back({prods[i],0});
                break;
            }
            for (int i = 0; i < two1.size(); ++i) {
                if (prods[i]->getName() == two1[i].first->getName() && two1[i].second < 3) {
                    two1[i].second++;
                } else if (two1[i].second == 3) {
                    two1.push_back({prods[i],0});
                }
            }
            break;
        case NONE:
            res += prods[i]->getPrice();
            break;
        default:
            break;
        }
    }

    for (int i = 0; i < three1.size(); ++i) {
        if (three1[i].second == 4) {
            res += three1[i].first->getPrice() * 3;
            break;
        }
    }

    for (int i = 0; i < two1.size(); ++i) {
        if (two1[i].second == 3) {
            res += three1[i].first->getPrice() * 2;
            break;
        }
    }
    return static_cast<int>(std::ceil(res));
}