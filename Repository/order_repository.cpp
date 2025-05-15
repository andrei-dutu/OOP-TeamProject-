//
// Created by Andrei Pop on 02.05.2025.
//
#include "order_repository.h"
#include <exception>

namespace Repository {

    void OrderRepository::addOrder(const Domain::Order& order) {
        order_repo.emplace_back(order);
    }

    Domain::Order OrderRepository::searchOrder(const int id) const {
        for (Domain::Order order : order_repo)
            if (order.getOrderNumber() == id)
                return order;
        throw std::exception();
    }

    std::vector<Domain::Order> OrderRepository::findOrdersByEmployee(const std::string& email) const {
        std::vector<Domain::Order> aux;
        for (Domain::Order order : order_repo)
            if (order.getCustomerEmail() == email)
                aux.emplace_back(order);
        if (! aux.empty())
            return aux;
        throw std::exception();
    }



}