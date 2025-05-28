#include "product.h"
#include <string>

namespace Domain {
    Product::Product(const std::string& id, const std::string& name, double price, int stock)
            : id(id), name(name), price(price), stock(stock) {}
    void Product::setStock(int stock) {
        this->stock = stock;
    }


}