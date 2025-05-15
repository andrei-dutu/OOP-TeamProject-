//
// Created by Andrei Pop on 02.05.2025.
//

#ifndef ORDER_CONTROLLER_H
#define ORDER_CONTROLLER_H
#include "../Repository/order_repository.h"

namespace Controller {

    class OrderController {

    private:

        Repository::OrderRepository& order_repo;

    public:

        OrderController(Repository::OrderRepository& order_repo) : order_repo(order_repo){}
        void addOrder(const Domain::Order& order);

    };
}

#endif //ORDER_CONTROLLER_H
