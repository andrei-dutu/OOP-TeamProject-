#ifndef CUSTOMER_UI_H
#define CUSTOMER_UI_H

#include "../Controller/customer_controller.h"
#include "../Controller/order_controller.h"
#include "../Controller/product_controller.h"
#include "../Domain/customer.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CustomerUI {
private:
    Controller::CustomerController& customerController;
    Controller::OrderController& orderController;
    string customerEmail;

    void changePassword() const;
    void listOrders() const;

public:
    CustomerUI(Controller::CustomerController& cCtrl, Controller::OrderController& oCtrl,  const string& email);

    void run();
};

#endif