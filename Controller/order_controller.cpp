//
// Created by Andrei Pop on 02.05.2025.
//
#include "order_controller.h"

namespace Controller {

    void OrderController::addOrder(const Domain::Order& order) {
        order_repo.addOrder(order);
    }

}