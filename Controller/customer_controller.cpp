#include "customer_controller.h"
namespace Controller {
    CustomerController::CustomerController(CustomerRepository& repo) : repository(repo) {}

    vector<Customer>& CustomerController::getAllCustomers() {
        return repository.getCustomers();
    }

    void CustomerController::addCustomer(const Customer& customer) {
        if (repository.findByEmail(customer.getEmail()) != nullptr) {
            throw runtime_error("Customer with this email already exists.");
        }
        repository.addCustomer(customer);
    }

    bool CustomerController::updateCustomer(int id, const Customer& updatedCustomer) {
        if (!repository.updateCustomer(id, updatedCustomer)) {
            throw runtime_error("Customer with ID " + to_string(id) + " not found for update.");
        }
        return true;
    }

    bool CustomerController::deleteCustomer(int id) {
        if (!repository.deleteCustomer(id)) {
            throw runtime_error("Customer with ID " + to_string(id) + " not found for deletion.");
        }
        return true;
    }


    Customer* CustomerController::findByEmail(const string& email) {
        Customer* found = repository.findByEmail(email);
        /*if (!found) {
            throw runtime_error("Customer with email '" + email + "' not found.");
        }*/
        return found;
    }

    int CustomerController::getCustomerCount() const {
        return repository.getCustomerCount();
    }
}
