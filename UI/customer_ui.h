#ifndef CUSTOMER_UI_H
#define CUSTOMER_UI_H

#include "../Controller/customer_controller.h"
#include "../Controller/order_controller.h"
#include "../Domain/customer.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CustomerUI {
private:
      Controller::CustomerController& customerController;
      Controller::OrderController& orderController;

      void changePassword(const string& customerEmail) const;
      void makeReservation(const string& customerEmail);
      void listOrders(const string& customerEmail) const;

public:
      CustomerUI(Controller::CustomerController& cCtrl, Controller::OrderController& oCtrl);

      void showMenu(const string& customerEmail);
};

#endif
