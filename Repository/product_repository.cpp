//
// Created by Andrei Pop on 02.05.2025.
//
#include "product_repository.h"
#include <algorithm>
namespace Repository {
    void ProductRepository::addProduct(const Domain::Product& product) {
        products.push_back(product);
    }
    bool ProductRepository::removeProduct(const std::string& id) {
        auto it = std::remove_if(products.begin(), products.end(),
            [&id](const Domain::Product& p) { return p.getId() == id; });

        if (it != products.end()) {
            products.erase(it, products.end());
            return true;
        }
        return false;
    }
    Domain::Product* ProductRepository::findProductById(const std::string& id) {
        auto it = std::find_if(products.begin(), products.end(),
            [&id](const Domain::Product& p) { return p.getId() == id; });

        return it != products.end() ? &(*it) : nullptr;
    }

    const std::vector<Domain::Product>& ProductRepository::getAllProducts() const {
        return products;
    }
    void ProductRepository::initializeSampleData() {
        products = {
            Domain::Product("P100", "Laptop", 999.99, 10),
            Domain::Product("P200", "Smartphone", 699.99, 15),
            Domain::Product("P300", "Tablet", 349.99, 5),
            Domain::Product("P400", "Monitor", 249.99, 8),
            Domain::Product("P500", "Keyboard", 49.99, 20)
        };
    }



}