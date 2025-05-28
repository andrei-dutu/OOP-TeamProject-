#include "customer_ui.h"
#include <stdexcept>

using namespace std;

CustomerUI::CustomerUI(Controller::CustomerController& cCtrl, Controller::OrderController& oCtrl, const string& email)
    : customerController(cCtrl), orderController(oCtrl), customerEmail(email) {}

void CustomerUI::changePassword() const {
    Customer* customer = customerController.findByEmail(customerEmail);
    if (!customer) {
        cout << "Customer not found.\n";
        return;
    }

    string newPassword;
    cout << "Enter new password: ";
    getline(cin, newPassword);

    Customer updatedCustomer = *customer;
    updatedCustomer.setPassword(newPassword);

    if (customerController.updateCustomer(customer->getId(), updatedCustomer)) {
        cout << "Password updated successfully.\n";
    } else {
        cout << "Failed to update password.\n";
    }
}

void CustomerUI::listOrders() const {
    try {
        vector<Domain::Order> orders = orderController.findOrdersByCustomer(customerEmail);
        cout << "Your Orders:\n";
        for (const Domain::Order& order : orders) {
            cout << "Order #" << order.getOrderNumber()
                 << " | Status: " << order.getStatus()
                 << " | Date: " << order.getDate().day << "."
                                << order.getDate().month << "."
                                << order.getDate().year
                 << " | Total: " << order.getTotalAmount() << " EUR\n";
        }
    } catch (const exception&) {
        cout << "You have no orders.\n";
    }
}

//void CustomerUI::makeReservation() {
// Placeholder pentru logica de rezervare
// cout << "[Reservation placeholder] Reservation created for customer " << customerEmail << ".\n";
//}
void CustomerUI::run() {
    int choice;
    do {
        cout << "\n===== Customer Menu =====\n";
        cout << "1. Change Password\n";
        cout << "2. Make a Reservation\n";
        cout << "3. List My Orders\n";
        cout << "0. Logout\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                changePassword();
                break;
            case 2:
                //makeReservation();
                break;
            case 3:
                listOrders();
                break;
            case 0:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }

    } while (choice != 0);
}