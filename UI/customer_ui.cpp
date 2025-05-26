#include "customer_ui.h"
#include <stdexcept>

using namespace std;

CustomerUI::CustomerUI(CustomerRepository& cRepo, Repository::OrderRepository& oRepo)
    : customerRepository(cRepo), orderRepository(oRepo) {}

void CustomerUI::changePassword(const string& customerEmail) {
    Customer* customer = customerRepository.findByEmail(customerEmail);
    if (!customer) {
        cout << "Customer not found.\n";
        return;
    }

    string newPassword;
    cout << "Enter new password: ";
    getline(cin, newPassword);

    customer->setPassword(newPassword);
    cout << "Password updated successfully.\n";
}

void CustomerUI::listOrders(const string& customerEmail) {
    try {
        vector<Domain::Order> orders = orderRepository.findOrdersByCustomer(customerEmail);
        cout << "Your Orders:\n";
        for (const Domain::Order& order : orders) {
            cout << "Order #" << order.getOrderNumber()
                 << " | Status: " << order.getStatus()
                 << " | Date: " << order.getDate().day << "."
                                << order.getDate().month << "."
                                << order.getDate().year
                 << " | Total: " << order.getTotalAmount() << " EUR\n";
        }
    } catch (const std::exception&) {
        cout << "You have no orders.\n";
    }
}

void CustomerUI::makeReservation(const string& customerEmail) {
    // Placeholder for reservation logic
    cout << "[Reservation placeholder] Reservation created for customer " << customerEmail << ".\n";

}


void CustomerUI::showMenu(const string& customerEmail) {
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
                changePassword(customerEmail);
            break;
            case 2:
                makeReservation(customerEmail);
            break;
            case 3:
                listOrders(customerEmail);
            break;
            case 0:
                cout << "Logging out...\n";
            break;
            default:
                cout << "Invalid option. Please try again.\n";
        }

    } while (choice != 0);
}