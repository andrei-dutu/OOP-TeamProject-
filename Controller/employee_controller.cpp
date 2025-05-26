#include "employee_controller.h"
#include"Domain/order.h"
#include"Domain/employee.h"
#include <stdexcept>

using namespace Controller;
using namespace domain;

EmployeeController::EmployeeController(repository::EmployeeRepository& employee_repo,
                                       repository::OrderRepository& order_repo)
    : employee_repo(employee_repo), order_repo(order_repo) {}

bool EmployeeController::add_employee(const std::string& surname,
                                      const std::string& first_name,
                                      const std::string& email,
                                      const std::string& position,
                                      const Domain::Date& birthdate,
                                      int salary) {
    return employee_repo.add(Employee(surname, first_name, email, position, birthdate, salary));
}
void EmployeeController::complete_order(int order_id, const std::string& employee_name) {
    Order& order = order_repo.find_by_id(order_id);

    if (order.get_status() == "Completed") {
        throw std::runtime_error("Order is already completed.");
    }

    if (order.get_employee_name() != employee_name) {
        throw std::runtime_error("You are not assigned to this order.");
    }

    order.set_status("Completed");
    order_repo.update_order(order);  // Dacă e necesar să fie salvat explicit
}
