#include "customer_repository.h"

using namespace std;

CustomerRepository::CustomerRepository() : customers {
        {1, "Ion", "Popescu", "ion.popescu@test.ro", "pass123", {"Romania", "Bucuresti", "Strada Libertatii", 10}, "", false},
        {2, "Maria", "Smith", "maria.smith@test.com", "maria456", {"USA", "New York", "5th Avenue", 123}, "", false},
        {3, "Andrei", "Georgescu", "andrei.georgescu@test.ro", "andrei789", {"Romania", "Cluj-Napoca", "Strada Eroilor", 5}, "", false},
        {4, "Elena", "Garcia", "elena.garcia@test.es", "elena000", {"Spain", "Madrid", "Calle Gran Via", 45}, "", false},
        {5, "Vasile", "Marinescu", "vasile.marinescu@test.ro", "vasile999", {"Romania", "Brasov", "Strada Republicii", 15}, "", false},
        {6, "Ioana", "Müller", "ioana.mueller@test.de", "ioana321", {"Germany", "Berlin", "Alexanderplatz", 7}, "", false},
        {7, "George", "Stan", "george.stan@test.ro", "george654", {"Romania", "Craiova", "Strada Unirii", 7}, "", false},
    } {}

vector<Customer>& CustomerRepository::getCustomers() {
    return customers;
}

void CustomerRepository::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

bool CustomerRepository::updateCustomer(int id, const Customer& updatedCustomer) {
    for (int i = 0; i < customers.size(); i++) {
        if (id == customers[i].getId()) {
            customers[i] = updatedCustomer;
            return true;
        }
    }
    return false;
}

bool CustomerRepository::deleteCustomer(int id) {
    for (int i = 0; i < customers.size(); i++) {
        if (id == customers[i].getId()) {
            customers.erase(customers.begin() + i);
            return true;
        }
    }
    return false;
}

Customer* CustomerRepository::findByEmail(const string& email) {
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].getEmail() == email) {
            return &customers[i];
        }
    }
    return nullptr; //nu s-a gasit clientul
}

int CustomerRepository::getCustomerCount() const
{
    return customers.size();
}
