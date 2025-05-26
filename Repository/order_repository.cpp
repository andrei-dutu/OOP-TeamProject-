//
// Created by Andrei Pop on 15.05.2025.
//
#include "order_repository.h"
#include <exception>
#include "../Domain/order.h"

namespace Repository {

    void OrderRepository::addOrder(const Domain::Order& order) {
        order_storage.emplace_back(order);
    }

    std::vector<Domain::Order> OrderRepository::returnStorage() {
        return order_storage;
    }

    Domain::Order OrderRepository::searchOrder(const int id) const {
        int cnt = 0;
        for (Domain::Order order : order_storage)
            if (order.getOrderNumber() == id) {
                return order;
            }
        throw std::runtime_error("Order not found");
    }
    std::vector<Domain::Order> OrderRepository::findOrdersByEmployee(const std::string& email) const {
        std::vector<Domain::Order> aux;
        for (Domain::Order order : order_storage)
            if (order.getEmployeeEmail() == email)
                aux.emplace_back(order);
        if (! aux.empty())
            return aux;
        throw std::runtime_error("No orders for this employee");
    }

    std::vector<Domain::Order> OrderRepository::findOrdersByCustomer(const std::string& email) const {
        std::vector<Domain::Order> aux;
        for (Domain::Order order : order_storage)
            if (order.getCustomerEmail() == email)
                aux.emplace_back(order);
        if (! aux.empty())
            return aux;
        throw std::runtime_error("No orders for this customer");
    }

    std::vector<Domain::Order> OrderRepository::findOrdersByStatus(const std::string& status) const {

        std::vector<Domain::Order> aux;
        for (Domain::Order order : order_storage)
            if (order.getStatus() == status)
                aux.emplace_back(order);

        if (!aux.empty())
            return aux;

        throw std::runtime_error("No product with this status");

    }

    std::vector<Domain::Order> OrderRepository::findOrdersByYear(int year) const {
        std::vector<Domain::Order> aux;
        for (const Domain::Order& order : order_storage)
            if (order.getDate().year == year)
                aux.emplace_back(order);

        if (! aux.empty())
            return aux;
        throw std::runtime_error("No product int this year");
    }

    std::vector<Domain::Order> OrderRepository::findOrdersByYearAndMonth(int year, int month) const {

        std::vector<Domain::Order> aux;
        for (const Domain::Order& order : order_storage)
            if (order.getDate().year == year && order.getDate().month == month)
                aux.emplace_back(order);

        if (! aux.empty())
            return aux;
        throw std::runtime_error("No product int this month");
    }

    std::vector<Domain::Order> OrderRepository::findOrdersByDate(const Domain::Date date) const {

        std::vector<Domain::Order> aux;
        for (const Domain::Order& order : order_storage)
            if (order.getDate().year == date.year && order.getDate().month == date.month
                && order.getDate().day == date.day)
                aux.emplace_back(order);

        if (! aux.empty())
            return aux;
        throw std::runtime_error("No product with this date");
    }

    void OrderRepository::modifyOrderNumber(const int number, const int new_number) {

        for (Domain::Order& order : order_storage)
            if (order.getOrderNumber() == number) {
                order.setOrderNumber(new_number);
                return;
            }
        throw std::runtime_error("No product with this id");
    }

    void OrderRepository::modifyOrderQuantity(const int number, const int new_quantity) {

        for (Domain::Order& order : order_storage)
            if (order.getOrderNumber() == number) {
                order.setQuantity(new_quantity);
                return;
            }
        throw std::runtime_error("No product with this id");
    }

    void OrderRepository::modifyOrderStatus(const int number, const std::string& new_status) {

        for (Domain::Order& order : order_storage)
            if (order.getOrderNumber() == number) {
                order.setStatus(new_status);
                return;
            }
        throw std::runtime_error("No product with this number");

    }

    void OrderRepository::modifyOrderProduct(const int number, const Domain::Product& new_product) {

        for (Domain::Order& order : order_storage)
            if (order.getOrderNumber() == number) {
                order.setProduct(new_product);
                return;
            }

        throw std::runtime_error("No product with this number");
    }

    void OrderRepository::giveOrderToAnotherEmployee(const int number, const std::string& email) {
        for (Domain::Order& order : order_storage)
            if (order.getOrderNumber() == number) {
                order.setEmployeeEmail(email);
                return;
            }
        throw std::runtime_error("No product with this number");
    }


    int OrderRepository::getTotalAmountByYear(const int year) {
        int total = 0;
        for (Domain::Order& order : order_storage)
            if (order.getDate().year == year) {
                total = total + order.getTotalAmount();
            }
        if (total == 0)
            throw std::runtime_error("No product in this year");
        return total;
    }

    int OrderRepository::getTotalAmountByMonth(const int year, const int month) {
        int total = 0;
        for (Domain::Order& order : order_storage)
            if (order.getDate().year == year && order.getDate().month == month) {
                total = total + order.getTotalAmount();
            }
        if (total == 0)
            throw std::runtime_error("No product ");
        return total;
    }

}