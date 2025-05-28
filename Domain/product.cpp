//
// Created by Andrei Pop on 02.05.2025.
//
#include "product.h"
#include <string>

namespace Domain {

    /*Product::Product(const std::string& id, const std::string& name, double price, int stock)
            : id(id), name(name), price(price), stock(stock) {}*/
    void Product::setStock(int stock) {
        this->stock = stock;
    }

    std::string Product::getID() const {
        return id;
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
        id = newID;
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