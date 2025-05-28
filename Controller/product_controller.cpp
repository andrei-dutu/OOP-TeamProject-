//
// Created by Andrei Pop on 02.05.2025.
//
#include "../Controller/product_controller.h"
#include <algorithm>
#include <cctype>
#include "../Domain/product.h"
namespace Controller {
    ProductController::ProductController() {
        initializeSampleData();
    }
    bool ProductController::validateProductId(const std::string& id)  {
        if (id.empty()) return false;

        if (!std::all_of(id.begin(), id.end(), [](char c) {
            return std::isalnum(c);
        })) return false;

        return repository.findProductById(id) == nullptr;
    }
    bool ProductController::validateProductData(const std::string& name, double price, int stock) const {
        return !name.empty() &&
               price >= 0 &&
               stock >= 0;
    }
    bool ProductController::createProduct(const std::string& id, const std::string& name,
                                    double price, int stock) {
        if (!validateProductId(id) || !validateProductData(name, price, stock)) {
            return false;
        }

        repository.addProduct(Domain::Product(id, name, price, stock));
        return true;
    }
    std::vector<Domain::Product> ProductController::getAvailableProducts() const {
        auto products = getAllProducts();

        products.erase(
            std::remove_if(products.begin(), products.end(),
                [](const Domain::Product& p) { return p.getStock() <= 0; }),
            products.end()
        );

        std::sort(products.begin(), products.end(),
            [](const Domain::Product& a, const Domain::Product& b) {
                return a.getPrice() < b.getPrice();
            });

        return products;
    }
    bool ProductController::increaseStock(const std::string& productId, int amount) {
        if (amount <= 0) return false;

        if (auto* product = repository.findProductById(productId)) {
            product->setStock(product->getStock() + amount);
            return true;
        }
        return false;
    }
    bool ProductController::decreaseStock(const std::string& productId, int amount) {
        if (amount <= 0) return false;

        if (auto* product = repository.findProductById(productId)) {
            if (product->getStock() >= amount) {
                product->setStock(product->getStock() - amount);
                return true;
            }
        }
        return false;
    }



    void ProductController::initializeSampleData() {
        repository.initializeSampleData();
    }
    const std::vector<Domain::Product>& ProductController::getAllProducts() const {
        return repository.getAllProducts();
    }

}