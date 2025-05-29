#include <iostream>
#include "Tests/test.h"
#include "Repository/customer_repository.h"
#include "Repository/employee_repository.h"
#include "Repository/order_repository.h"
#include "Repository/product_repository.h"

int main() {
    CustomerRepository customer_repo;
    EmployeeRepository employee_repo;
    Repository::OrderRepository order_repo;
    Repository::ProductRepository product_repo;
    Controller::ProductController product_controller(product_repo);
    Controller::OrderController order_controller(order_repo);
    Controller::EmployeeController employee_controller(employee_repo);
    Controller::CustomerController customer_controller(customer_repo);


}