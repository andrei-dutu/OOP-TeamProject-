#ifndef CUSTOMER_CONTROLLER_H
#define CUSTOMER_CONTROLLER_H

#include "../Repository/customer_repository.h"

class CustomerController {

private:
    CustomerRepository& repository;

public:
    CustomerController(CustomerRepository& repo);

    vector<Customer>& getAllCustomers();
    void addCustomer(const Customer& customer);
    bool updateCustomer(int id, const Customer& updatedCustomer);
    bool deleteCustomer(int id);
    Customer* findByEmail(const string& email);
    int getCustomerCount() const;
    int getActiveCustomerCount() const;
    vector<Customer>& findByProduct(string& productName);
};

#endif
