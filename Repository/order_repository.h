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
        std::vector<Domain::Order> findOrdersByCustomer(std::string email);
        std::vector<Domain::Order> findOrdersByStatus(std::string status);
        std::vector<Domain::Order> findOrdersByYear(std::string email);
        void modifyOrderStatus(std::string new_status);
        void modifyOrderNumber(int new_number);
        void modifyOrderProduct(Domain::Product new_product);
        void modifyOrderQuantity(int new_quantity);
        void giveOrderToAnotherEmployee(int order_id, std::string email);
        int getTotalAmountByYear(int year);
        int getTotalAmountByMonth(int Month);

    };
}

#endif //ORDER_REPOSITORY_H
