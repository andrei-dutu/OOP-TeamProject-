#ifndef CUSTOMER_UI_H
#define CUSTOMER_UI_H

#include "../Domain/customer.h"
#include "../Repository/customer_repository.h"
#include "../Repository/order_repository.h"

#include <iostream>
#include <string>

using namespace std;

class CustomerUI {
private:
      /*Repository::*/CustomerRepository& customerRepository;
      Repository::OrderRepository& orderRepository;

      void changePassword(const string& customerEmail) const;
      void makeReservation(const string& customerEmail);
      void listOrders(const string& customerEmail);

public:
      CustomerUI(/*Repository::*/CustomerRepository& cRepo, Repository::OrderRepository& oRepo);

      void showMenu(const string& customerEmail);
};

#endif
