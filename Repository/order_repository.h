//
// Created by Andrei Pop on 02.05.2025.
//

#ifndef ORDER_REPOSITORY_H
#define ORDER_REPOSITORY_H
#include <vector>
#include "../Domain/order.h"

namespace Repository {

    class OrderRepository {

    private:

        std::vector<Domain::Order> order_repo;

    public:
        void addOrder(const Domain::Order& order);
        Domain::Order searchOrder(int id) const;
        std::vector<Domain::Order> findOrdersByEmployee(const std::string& email) const;
        std::vector<Domain::Order> findOrdersByCustomer(const std::string& email) const;
        std::vector<Domain::Order> findOrdersByStatus(const std::string& status) const;
        std::vector<Domain::Order> findOrdersByYearAndMonth(int year, int month) const;
        std::vector<Domain::Order> findOrdersByYear(int year) const;
        std::vector<Domain::Order> findOrdersByDate(Domain::Date date) const;
        void modifyOrderStatus(int number, const std::string& new_status);
        void modifyOrderNumber(int number, int new_number);
        void modifyOrderProduct(int number, const Domain::Product& new_product);
        void modifyOrderQuantity(int number, int new_quantity);
        void giveOrderToAnotherEmployee(int number, const std::string& email);
        int getTotalAmountByYear(int year);
        int getTotalAmountByMonth(int year, int month);

    };
}

#endif //ORDER_REPOSITORY_H
