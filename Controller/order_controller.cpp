//
// Created by Andrei Pop on 02.05.2025.
//
#include "order_controller.h"

namespace Controller {

    void OrderController::addOrder(const Domain::Order& order) const {
        order_repo.addOrder(order);
    }

    Domain::Order OrderController:: searchOrder (const int id) const {
        return order_repo.searchOrder(id);
    }

    std::vector<Domain::Order> OrderController:: findOrdersByEmployee(const std::string& email) const {
        return order_repo.findOrdersByEmployee(email);
    }

    std::vector<Domain::Order> OrderController:: findOrdersByCustomer(const std::string& email) const {
        return order_repo.findOrdersByCustomer(email);
    }

    std::vector<Domain::Order> OrderController:: findOrdersByStatus(const std::string& status) const {
        return order_repo.findOrdersByStatus(status);
    }

    std::vector<Domain::Order> OrderController:: findOrdersByYearAndMonth(const int year, const int month) const {
        return order_repo.findOrdersByYearAndMonth(year, month);
    }

    std::vector<Domain::Order> OrderController:: findOrdersByYear(const int year) const {
        return order_repo.findOrdersByYear(year);
    }

    std::vector<Domain::Order> OrderController:: findOrdersByDate(Domain::Date date) const {
        return order_repo.findOrdersByDate(date);
    }

    void OrderController:: modifyOrderStatus(const int number, const std::string& new_status) const {
        order_repo.modifyOrderStatus(number, new_status);
    }

    void OrderController :: modifyOrderNumber(const int number, const int new_number) const {
        order_repo.modifyOrderNumber(number, new_number);
    }

    void OrderController::modifyOrderProduct(const int number, const Domain::Product& new_product) const {
        order_repo.modifyOrderProduct(number, new_product);
    }

    void OrderController::modifyOrderQuantity(const int number, const int new_quantity) const {
        order_repo.modifyOrderQuantity(number, new_quantity);
    }

    void OrderController::giveOrderToAnotherEmployee(const int number, const std::string& email) const {
        order_repo.giveOrderToAnotherEmployee(number, email);
    }

    int OrderController::getTotalAmountByYear(const int year) const {
        return order_repo.getTotalAmountByYear(year);
    }

    int OrderController::getTotalAmountByMonth(const int year, const int month) const {
        return order_repo.getTotalAmountByMonth(year, month);
    }

}