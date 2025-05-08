//
// Created by Andrei Pop on 02.05.2025.
//

#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

namespace Domain {

    class Product {

    private:

        std::string ID;
        std::string name;
        int price;
        int stock;

    public:

        Product(std::string& ID, std::string& name, int price, int stock) : ID(ID), name(name), price(price), stock(stock) {}
        std::string getID;
        std::string getName;
        int getPrice();
        int getStock();

    };
}

#endif //PRODUCT_H
