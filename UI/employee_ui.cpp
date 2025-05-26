//
// Created by Andrei Pop on 26.05.2025.
//

#include <iostream>
#include <limits>
#include "employee_ui.h"

using namespace std;
using namespace ui;

EmployeeUI::EmployeeUI(Controller::EmployeeController& controller, const string& employee_name)
    : controller(controller), employee_name(employee_name) {
    command_handlers["confirm"] = [this]() { confirm_order(); };
    command_handlers["edit"] = [this]() { edit_order(); };
    command_handlers["complete"] = [this]() { complete_order(); };
    command_handlers["claim"] = [this]() { claim_order(); };
    command_handlers["list_all"] = [this]() { list_all_orders(); };
    command_handlers["list_status"] = [this]() { list_by_status(); };
    command_handlers["total_sum"] = [this]() { show_total_sum(); };
    command_handlers["help"] = [this]() { print_commands(); };
    command_handlers["exit"] = []() { exit(0); };
}

void EmployeeUI::run() {
    print_commands();
    string command;

    while (true) {
        cout << "\n> ";
        getline(cin, command);

        auto it = command_handlers.find(command);
        if (it != command_handlers.end()) {
            it->second();
        } else {
            cout << "Invalid command. Type 'help' for available options.\n";
        }
    }
}

void EmployeeUI::print_commands() const {
    cout << "\nAvailable commands:\n";
    cout << "  confirm      - Confirm a reservation/order\n";
    cout << "  edit         - Edit one of your own non-completed orders\n";
    cout << "  complete     - Mark your order as completed\n";
    cout << "  claim        - Take over an unassigned or foreign order\n";
    cout << "  list_all     - List all orders in the system\n";
    cout << "  list_status  - List orders with a specific status\n";
    cout << "  total_sum    - Show total order value (per year/month)\n";
    cout << "  help         - Show this command list\n";
    cout << "  exit         - Exit the application\n";
}

void EmployeeUI::confirm_order() {
    cout << "Enter order ID to confirm: ";
    int id;
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    try {
        controller.confirm_order(id, employee_name);
        cout << "Order confirmed successfully.\n";
    } catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }
}

void EmployeeUI::edit_order() {
    cout << "Enter order ID to edit: ";
    int id;
    cin >> id;
    cin.ignore();

    cout << "Enter new product name: ";
    string product;
    getline(cin, product);

    cout << "Enter new quantity: ";
    int quantity;
    cin >> quantity;
    cin.ignore();

    try {
        controller.edit_order(id, product, quantity, employee_name);
        cout << "Order updated successfully.\n";
    } catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }
}

void EmployeeUI::complete_order() {
    cout << "Enter order ID to mark as completed: ";
    int id;
    cin >> id;
    cin.ignore();

    try {
        controller.complete_order(id, employee_name);
        cout << "Order marked as completed.\n";
    } catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }
}

void EmployeeUI::claim_order() {
    cout << "Enter order ID to claim: ";
    int id;
    cin >> id;
    cin.ignore();

    try {
        controller.claim_order(id, employee_name);
        cout << "Order successfully claimed.\n";
    } catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }
}

void EmployeeUI::list_all_orders() {
    auto orders = controller.get_all_orders();
    if (orders.empty()) {
        cout << "There are no orders in the system.\n";
    } else {
        for (const auto& order : orders) {
            cout << order << '\n';
        }
    }
}

void EmployeeUI::list_by_status() {
    cout << "Enter status to filter by (Pending / Confirmed / Completed): ";
    string status;
    getline(cin, status);

    auto filtered = controller.get_orders_by_status(status);
    if (filtered.empty()) {
        cout << "No orders found with status '" << status << "'.\n";
    } else {
        for (const auto& order : filtered) {
            cout << order << '\n';
        }
    }
}

void EmployeeUI::show_total_sum() {
    cout << "Choose type:\n";
    cout << " 1 - By year\n";
    cout << " 2 - By month\n";
    cout << " > ";
    int option;
    cin >> option;

    if (option == 1) {
        int year;
        cout << "Enter year: ";
        cin >> year;
        double sum = controller.get_total_sum_by_year(year);
        cout << "Total sum in " << year << ": " << sum << '\n';
    } else if (option == 2) {
        int year, month;
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter month (1-12): ";
        cin >> month;
        double sum = controller.get_total_sum_by_month(year, month);
        cout << "Total sum in " << month << "/" << year << ": " << sum << '\n';
    } else {
        cout << "Invalid option.\n";
    }

    cin.ignore(); // clear newline
}
