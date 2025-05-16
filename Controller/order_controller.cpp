//
// Created by Andrei Pop on 02.05.2025.
//
#include "order_controller.h"

namespace Controller {

    void OrderController::addOrder(const Domain::Order& order) {
        order_repo.addOrder(order);
    }

    Domain::Order OrderController:: searchOrder (int id) const {
        return order_repo.searchOrder(id);
    }

    std::vector<Domain::Order> OrderController:: findOrdersByEmployee(const std::string& email) const {
        return order_repo.findOrdersByEmployee(email);
    }

    std::vector<Domain::Order> OrderController:: findOrdersByCustomer(const std::string& email) {
        return order_repo.findOrdersByCustomer(email);
    }

    std::vector<Domain::Order> OrderController:: findOrdersByStatus(const std::string& status) {
        return order_repo.findOrdersByStatus(status);
    }

    std::vector<Domain::Order> OrderController:: findOrdersByYearAndMonth(int year, int month) {
        return order_repo.findOrdersByYearAndMonth(year, month);
    }

    std::vector<Domain::Order> OrderController:: findOrdersByYear(int year) {
        return order_repo.findOrdersByYear(year);
    }

    std::vector<Domain::Order> OrderController:: findOrdersByDate(Domain::Date date) {
        return order_repo.findOrdersByDate(date);
    }

    void OrderController:: modifyOrderStatus(int number, const std::string& new_status) {
        order_repo.modifyOrderStatus(number, new_status);
    }

    void OrderController :: modifyOrderNumber(int number, int new_number) {
        order_repo.modifyOrderNumber(number, new_number);
    }

    void OrderController::modifyOrderProduct(int number, Domain::Product new_product) {
        order_repo.modifyOrderProduct(number, new_product);
    }

    void OrderController::modifyOrderQuantity(int number, int new_quantity) {
        order_repo.modifyOrderQuantity(number, new_quantity);
    }

    void OrderController::giveOrderToAnotherEmployee(int number, std::string email) {
        order_repo.giveOrderToAnotherEmployee(number, email);
    }

    int OrderController::getTotalAmountByYear(int year) {
        return order_repo.getTotalAmountByYear(year);
    }

    int OrderController::getTotalAmountByMonth(int year, int month) {
        return order_repo.getTotalAmountByMonth(year, month);
    }

}