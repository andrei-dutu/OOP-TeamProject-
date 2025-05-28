#include "employee_controller.h"
namespace Controller {

EmployeeController::EmployeeController(EmployeeRepository& repo) : repository(repo) {}

vector<Employee>& EmployeeController::getAllEmployees() {
    return repository.getEmployees();
}

void EmployeeController::addEmployee(const Employee& employee) {
    if (repository.findByEmail(employee.getEmail()) != nullptr) {
        throw runtime_error("Employee with this email already exists.");
    }
    repository.addEmployee(employee);
}

bool EmployeeController::updateEmployee(int id, const Employee& updatedEmployee) {
    if (!repository.updateEmployee(id, updatedEmployee)) {
        throw runtime_error("Employee with ID " + to_string(id) + " not found for update.");
    }
    return true;
}

bool EmployeeController::deleteEmployee(int id) {
    if (!repository.deleteEmployee(id)) {
        throw runtime_error("Employee with ID " + to_string(id) + " not found for deletion.");
    }
    return true;
}

Employee* EmployeeController::findByEmail(const string& email) {
    Employee* found = repository.findByEmail(email);
    if (!found) {
        throw runtime_error("Employee with email '" + email + "' not found.");
    }
    return found;
}

}