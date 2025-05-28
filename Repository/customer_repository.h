#ifndef CUSTOMER_REPOSITORY_H
#define CUSTOMER_REPOSITORY_H

#include <vector>
#include <iostream>
#include "../Domain/customer.h"

using namespace std;

class CustomerRepository {

private:
    vector<Customer> customers;

public:
    CustomerRepository();

    vector<Customer>& getCustomers();
    void addCustomer(const Customer& customer);
    bool updateCustomer(int id, const Customer& updatedCustomer);
    bool deleteCustomer(int id);
    Customer* findByEmail(const string& email);
    int getCustomerCount() const;
};

#endif
