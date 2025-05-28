#include "customer_ui.h"
#include <stdexcept>

using namespace std;

CustomerUI::CustomerUI(Controller::CustomerController& cCtrl, Controller::OrderController& oCtrl)
    : customerController(cCtrl), orderController(oCtrl) {}

void CustomerUI::changePassword(const string& customerEmail) const {
    Customer* customer = customerController.findByEmail(customerEmail);
    if (!customer) {
        cout << "Customer not found.\n";
        return;
    }

    string newPassword;
    cout << "Enter new password: ";
    getline(cin, newPassword);

    // Presupunem că ai o metodă updateCustomer în CustomerController
    Customer updatedCustomer = *customer;
    updatedCustomer.setPassword(newPassword);

    if (customerController.updateCustomer(customer->getId(), updatedCustomer)) {
        cout << "Password updated successfully.\n";
    } else {
        cout << "Failed to update password.\n";
    }
}

void CustomerUI::listOrders(const string& customerEmail) const {
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

// void CustomerUI::makeReservation(const string& customerEmail) {
//     // Exemplu simplu de rezervare
//     string productId;
//     int quantity;
//
//     cout << "Enter product ID: ";
//     getline(cin, productId);
//
//     cout << "Enter quantity: ";
//     cin >> quantity;
//     cin.ignore();
//
//     // Ca să faci comanda, trebuie să obții produsul din ProductRepository
//     // Care ar trebui expus printr-un ProductController (ideal)
//     // Pentru exemplu, presupunem că ai un ProductController disponibil (sau repo, dacă nu)
//     // Altfel, poți adăuga ProductController în constructor și aici să-l folosești
//
//     // Pseudo cod:
//     // Domain::Product product = productController.findProductById(productId);
//     // dacă produsul există și cantitatea e ok -> creezi comanda și o adaugi prin orderController
//
//     cout << "[Implementare rezervare cu ProductController și OrderController]\n";
// }

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
