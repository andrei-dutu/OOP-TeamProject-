//
// Created by Andrei Pop on 02.05.2025.
//

#ifndef PRODUCT_REPOSITORY_H
#define PRODUCT_REPOSITORY_H

#include <vector>
#include "../Domain/product.h"
namespace Repository {
    class ProductRepository {
    private:
        std::vector<Domain::Product> products;

    public:
        void addProduct(const Domain::Product& product);
        bool removeProduct(const std::string& id);
        Domain::Product* findProductById(const std::string& id);
        const std::vector<Domain::Product>& getAllProducts() const;

        void initializeSampleData();
    };



}

#endif //PRODUCT_REPOSITORY_H
