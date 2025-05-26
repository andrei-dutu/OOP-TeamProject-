#include <iostream>
#include "UI/ui.h"

#include "Repository/customer_repository.h"
#include "Repository/employee_repository.h"
#include "Repository/order_repository.h"
#include "Repository/product_repository.h"

int main() {
    CustomerRepository customer_repo;
    EmployeeRepository employee_repo;
    Controller::EmployeeController employee_controller(employee_repo);
    Controller::CustomerController customer_controller(customer_repo);
    UI::ui ui(employee_controller, customer_controller);
    ui.run();
    return 0;
}
