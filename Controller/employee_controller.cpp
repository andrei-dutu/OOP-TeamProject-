#include "customer_controller.h"

CustomerController::CustomerController(CustomerRepository& repo) : repository(repo) {}

vector<Customer>& CustomerController::getAllCustomers() {
    return repository.getCustomers();
}

void CustomerController::addCustomer(const Customer& customer) {
    repository.addCustomer(customer);
}

bool CustomerController::updateCustomer(int id, const Customer& updatedCustomer) {
    return repository.updateCustomer(id, updatedCustomer);
}

bool CustomerController::deleteCustomer(int id) {
    return repository.deleteCustomer(id);
}

Customer* CustomerController::findByEmail(const string& email) {
    return repository.findByEmail(email);
}

int CustomerController::getCustomerCount() const {
    return repository.getCustomerCount();
}

