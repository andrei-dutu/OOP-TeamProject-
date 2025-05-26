//
// Created by Andrei Pop on 02.05.2025.
//
#include "product.h"

namespace Domain {
    std::string Product::getID() const {
        return ID;
    }

    std::string Product::getName() const {
        return name;
    }

    int Product::getPrice() const {
        return price;
    }

    int Product::getStock() const {
        return stock;
    }

    void Product::setID(const std::string& newID) {
        ID = newID;
    }

    void Product::setName(const std::string& newName) {
        name = newName;
    }

    void Product::setPrice(int newPrice) {
        price = newPrice;
    }

    void Product::setStock(int newStock) {
        stock = newStock;
    }
}