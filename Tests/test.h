//
// Created by Andrei Pop on 29.05.2025.
//

#ifndef TEST_H
#define TEST_H
#include "../Controller/customer_controller.h"
#include "../Controller/employee_controller.h"
#include "../Controller/order_controller.h"
#include "../Controller/product_controller.h"
class Test {
private:
    Controller::CustomerController &cc;
    Controller::EmployeeController &ec;
    Controller::OrderController &oc;
    Controller::ProductController &pc;
public:
    Test(Controller::CustomerController cc, Controller::EmployeeController &ec, Controller::OrderController &oc, Controller::ProductController &pc) :
    cc(cc), ec(ec), oc(oc), pc(pc){};
};
#endif //TEST_H
