#include "customer_ui.h"
#include <stdexcept>

using namespace std;

CustomerUI::CustomerUI(Controller::CustomerController& cCtrl,
                       Controller::OrderController& oCtrl,
                       Controller::ProductController& pCtrl,
                       const string& email)
    : customerController(cCtrl), orderController(oCtrl), productController(pCtrl), customerEmail(email) {}


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

void CustomerUI::makeReservation() {
    const vector<Domain::Product>& products = productController.getAvailableProducts();

    if (products.empty()) {
        cout << "No products available for reservation.\n";
        return;
    }

    cout << "\nAvailable Products:\n";
    for (const Domain::Product& product : products) {
        cout << "- ID: " << product.getId()
             << " | Name: " << product.getName()
             << " | Price: " << product.getPrice()
             << " | Stock: " << product.getStock() << '\n';
    }

    string selectedId;
    cout << "Enter product ID to reserve: ";
    getline(cin, selectedId);

    Domain::Product* productPtr = productController.getProductRepository().findProductById(selectedId);
    if (!productPtr || productPtr->getStock() <= 0) {
        cout << "Invalid product ID or out of stock.\n";
        return;
    }

    int quantity;
    cout << "Enter quantity: ";
    cin >> quantity;
    cin.ignore();

    if (quantity <= 0 || quantity > productPtr->getStock()) {
        cout << "Invalid quantity.\n";
        return;
    }

    int newOrderNumber = orderController.getAllOrders().size() + 1; // Simple order number generation
    Domain::Date today = { 29, 5, 2025 }; // Replace with actual date logic if needed
    string status = "Pending";
    string assignedEmployee = "employee@shop.com"; // Use a real assignment logic later

    Domain::Order newOrder(newOrderNumber, today, *productPtr, quantity, customerEmail, assignedEmployee, status);
    orderController.addOrder(newOrder);
    productController.decreaseStock(productPtr->getId(), quantity);

    cout << "Reservation placed successfully.\n";
}

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
                makeReservation();
                break;
            case 3:
                listOrders();
                break;
            case 0:
                cout << "Logging o    ut...\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }

    } while (choice != 0);
}