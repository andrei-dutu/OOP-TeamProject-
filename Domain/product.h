//
// Created by Andrei Pop on 02.05.2025.
//

#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

namespace Domain {

    class Product {

    private:

        std::string id;
        std::string name;
        double price;
        int stock;

    public:

        Product(const std::string& id, const std::string& name, double price, int stock);

        std::string getId() const { return id; }
        std::string getName() const { return name; }
        double getPrice() const { return price; }
        int getStock() const { return stock; }

        void setName(const std::string& name) { this->name = name; }
        void setPrice(double price);
        void setStock(int stock);


    };
}

#endif //PRODUCT_H
