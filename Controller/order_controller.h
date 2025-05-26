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
        void addOrder(const Domain::Order& order);
        Domain::Order searchOrder(int id) const;
        std::vector<Domain::Order> findOrdersByEmployee(const std::string& email) const;
        std::vector<Domain::Order> findOrdersByCustomer(const std::string& email);
        std::vector<Domain::Order> findOrdersByStatus(const std::string& status);
        std::vector<Domain::Order> findOrdersByYearAndMonth(int year, int month);
        std::vector<Domain::Order> findOrdersByYear(int year);
        std::vector<Domain::Order> findOrdersByDate(Domain::Date date);
        void modifyOrderStatus(int number, const std::string& new_status);
        void modifyOrderNumber(int number, int new_number);
        void modifyOrderProduct(int number, Domain::Product new_product);
        void modifyOrderQuantity(int number, int new_quantity);
        void giveOrderToAnotherEmployee(int number, std::string email);
        int getTotalAmountByYear(int year);
        int getTotalAmountByMonth(int year, int month);

    };
}

#endif //ORDER_CONTROLLER_H
