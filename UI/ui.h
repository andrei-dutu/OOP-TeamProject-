//
// Created by Andrei Pop on 02.05.2025.
//

#ifndef UI_H
#define UI_H
#include "../Controller/customer_controller.h"
#include "../Controller/employee_controller.h"
#include "../Controller/order_controller.h"

namespace UI {
    enum class UserType { None, Customer, Employee };

    struct LoginResult {
        UserType type;
        void* user;
    };

    class ui {
    private:
        Controller::EmployeeController& employee_controller;
        Controller::CustomerController& customer_controller;
        Controller::OrderController& order_controller;
        std::string email;
    public:
        ui(Controller::EmployeeController& ec, Controller::CustomerController& cs, Controller::OrderController& oc)
            : employee_controller(ec), customer_controller(cs), order_controller(oc){}

        LoginResult login();
        void run();
    };
}

#endif //UI_H
