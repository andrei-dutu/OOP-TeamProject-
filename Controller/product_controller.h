//
// Created by Andrei Pop on 02.05.2025.
//

#ifndef PRODUCT_CONTROLLER_H
#define PRODUCT_CONTROLLER_H
#include "../Repository/product_repository.h"
#include "../Domain/product.h"
#include <vector>
#include <string>
namespace Controller {
    class ProductController {
    private:
        Repository::ProductRepository repository;

        bool validateProductId(const std::string& id) const;
        bool validateProductData(const std::string& name, double price, int stock) const;


    public:
        ProductController();
        bool createProduct(const std::string& id, const std::string& name, double price, int stock);

        std::vector<Domain::Product> getAvailableProducts() const;


        bool increaseStock(const std::string& productId, int amount);
        bool decreaseStock(const std::string& productId, int amount);;


        void initializeSampleData();
        const std::vector<Domain::Product>& getAllProducts() const;


    };
}

#endif //PRODUCT_CONTROLLER_H
