#include <iostream>

#include "Controller/order_controller.h"
#include "UI/ui.h"

#include "Repository/customer_repository.h"
#include "Repository/employee_repository.h"
#include "Repository/order_repository.h"
#include "Repository/product_repository.h"

int main() {
    CustomerRepository customer_repo;
    EmployeeRepository employee_repo;
    Repository::OrderRepository order_repo;
    Controller::OrderController order_controller(order_repo);
    Controller::EmployeeController employee_controller(employee_repo);
    Controller::CustomerController customer_controller(customer_repo);
    UI::ui ui(employee_controller, customer_controller, order_controller);
    ui.run();
    return 0;
}
