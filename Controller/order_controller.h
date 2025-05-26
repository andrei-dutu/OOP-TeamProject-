//
// Created by Andrei Pop on 02.05.2025.
//

#ifndef ORDER_CONTROLLER_H
#define ORDER_CONTROLLER_H
#include "../Repository/order_repository.h"
#include "../Domain/order.h"

namespace Controller {

    class OrderController {

    private:

        Repository::OrderRepository& order_repo;

    public:

        OrderController(Repository::OrderRepository& order_repo) : order_repo(order_repo){}
        void addOrder(const Domain::Order& order) const;
        Domain::Order searchOrder(int id) const;
        std::vector<Domain::Order> findOrdersByEmployee(const std::string& email) const;
        std::vector<Domain::Order> findOrdersByCustomer(const std::string& email) const;
        std::vector<Domain::Order> findOrdersByStatus(const std::string& status) const;
        std::vector<Domain::Order> findOrdersByYearAndMonth(int year, int month) const;
        std::vector<Domain::Order> findOrdersByYear(int year) const;
        std::vector<Domain::Order> findOrdersByDate(Domain::Date date) const;
        void modifyOrderStatus(int number, const std::string& new_status) const;
        void modifyOrderNumber(int number, int new_number) const;
        void modifyOrderProduct(int number, const Domain::Product& new_product) const;
        void modifyOrderQuantity(int number, int new_quantity) const;
        void giveOrderToAnotherEmployee(int number, const std::string& email) const;
        int getTotalAmountByYear(int year) const;
        int getTotalAmountByMonth(int year, int month) const;

    };
}

#endif //ORDER_CONTROLLER_H
