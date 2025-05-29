#include <iostream>
#include "Tests/tests.h"
#include "Repository/customer_repository.h"
#include "Repository/employee_repository.h"
#include "Repository/order_repository.h"
#include "Repository/product_repository.h"
#include "Controller/product_controller.h"
#include "Controller/order_controller.h"
#include "Controller/employee_controller.h"
#include "Controller/customer_controller.h"

int main() {

    CustomerRepository customer_repo;
    EmployeeRepository employee_repo;
    Repository::OrderRepository order_repo;
    Repository::ProductRepository product_repo;


    Controller::ProductController product_controller(product_repo);
    Controller::OrderController order_controller(order_repo);
    Controller::EmployeeController employee_controller(employee_repo);
    Controller::CustomerController customer_controller(customer_repo);


    Test test(customer_controller, employee_controller, order_controller, product_controller);

    test.runAllTests();

    std::cout << "S-a rulat\n";
    return 0;
}