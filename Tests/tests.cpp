//
// Created by Andrei Pop on 29.05.2025.
//
#include "tests.h"
#include <cassert>
#include <iostream>

void Test::testProductController() {

    bool created = pc.createProduct("P10", "Mouse", 25.0, 30);
    assert(created);
    auto products = pc.getAllProducts();
    bool found = false;
    for (const auto& p : products) {
        if (p.getId() == "P10") found = true;
    }
    assert(found);
    std::cout << "ProductController test passed!\n";
}

void Test::runAllTests() {
    testProductController();
}
