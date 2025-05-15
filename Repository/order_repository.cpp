//
// Created by Andrei Pop on 15.05.2025.
//
#include "order_repository.h"
#include <exception>
#include "../Domain/order.h"

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
            if (order.getEmployeeEmail() == email)
                aux.emplace_back(order);
        if (! aux.empty())
            return aux;
        throw std::exception();
    }

    std::vector<Domain::Order> OrderRepository::findOrdersByCustomer(std::string email) {
        std::vector<Domain::Order> aux;
        for (Domain::Order order : order_repo)
            if (order.getCustomerEmail() == email)
                aux.emplace_back(order);
        if (! aux.empty())
            return aux;
        throw std::exception();
    }

    std::vector<Domain::Order> OrderRepository::findOrdersByStatus(const std::string& status) {

        std::vector<Domain::Order> aux;
        for (Domain::Order order : order_repo)
            if (order.getStatus() == status)
                aux.emplace_back(order);

        if (!aux.empty())
            throw std::runtime_error("No product with this status");
    }

    std::vector<Domain::Order> OrderRepository::findOrdersByYear(int year) {
        std::vector<Domain::Order> aux;
        for (const Domain::Order& order : order_repo)
            if (order.getDate().year == year)
                aux.emplace_back(order);

        if (! aux.empty())
            return aux;
        throw std::runtime_error("No product int this year");
    }

    std::vector<Domain::Order> OrderRepository::findOrdersByYearAndMonth(int year, int month) {

        std::vector<Domain::Order> aux;
        for (const Domain::Order& order : order_repo)
            if (order.getDate().year == year && order.getDate().month == month)
                aux.emplace_back(order);

        if (! aux.empty())
            return aux;
        throw std::runtime_error("No product int this month");
    }

    std::vector<Domain::Order> OrderRepository::findOrdersByDate(Domain::Date date) {

        std::vector<Domain::Order> aux;
        for (const Domain::Order& order : order_repo)
            if (order.getDate().year == date.year && order.getDate().month == date.month
                && order.getDate().day == date.day)
                aux.emplace_back(order);

        if (! aux.empty())
            return aux;
        throw std::runtime_error("No product with this date");
    }

    void OrderRepository::modifyOrderNumber(int new_number, int number) {

        for (Domain::Order& order : order_repo)
            if (order.getOrderNumber() == number) {
                order.setOrderNumber(new_number);
                break;
            }
        throw std::runtime_error("No product with this id");
    }

    void OrderRepository::modifyOrderQuantity(int number, int new_quantity) {

        for (Domain::Order& order : order_repo)
            if (order.getOrderNumber() == number) {
                order.setQuantity(new_quantity);
                break;
            }
        throw std::runtime_error("No product with this id");
    }

    void OrderRepository::modifyOrderStatus(int number, const std::string& new_status) {

        for (Domain::Order& order : order_repo)
            if (order.getOrderNumber() == number) {
                order.setStatus(new_status);
                break;
            }
        throw std::runtime_error("No product with this number");
    }

    void OrderRepository::modifyOrderProduct(int number, Domain::Product new_product) {

        for (Domain::Order& order : order_repo)
            if (order.getOrderNumber() == number) {
                order.setProduct(new_product);
                break;
            }

        throw std::runtime_error("No product with this number");
    }

    void OrderRepository::giveOrderToAnotherEmployee(int number, std::string email) {
        for (Domain::Order& order : order_repo)
            if (order.getOrderNumber() == number) {
                order.setEmployeeEmail(email);
                break;
            }
        throw std::runtime_error("No product with this number");
    }


    int OrderRepository::getTotalAmountByYear(int year) {
        int total = 0;
        for (Domain::Order& order : order_repo)
            if (order.getDate().year == year) {
                total = total + order.getTotalAmount();
            }
        if (total == 0)
            throw std::runtime_error("No product in this year");
        return total;
    }

    int OrderRepository::getTotalAmountByMonth(int year, int month) {
        int total = 0;
        for (Domain::Order& order : order_repo)
            if (order.getDate().year == year && order.getDate().month == month) {
                total = total + order.getTotalAmount();
            }
        if (total == 0)
            throw std::runtime_error("No product ");
        return total;
    }


}