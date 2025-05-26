//
// Created by Andrei Pop on 02.05.2025.
//

#ifndef UI_H
#define UI_H
#include "../Controller/customer_controller.h"
#include "../Controller/employee_controller.h"

namespace UI {
    class UI {
    private:
        Controller::EmployeeController& employee_controller;
        Controller::CustomerController& customer_controller;
    public:
        UI(Controller::EmployeeController ec, Controller::CustomerController cs) : employee_controller(ec),
        customer_controller(cs){}
        void run();
    };
}

#endif //UI_H
