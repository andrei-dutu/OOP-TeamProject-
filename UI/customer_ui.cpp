//
// Created by Dell on 09.04.2025.
//

#include "customer_ui.h"
#include "Controller/customer_controller"
#include"Domain/customer.h"

using namespace std;
using namespace ui;

CustomerUI::CustomerUI(controller::CustomerController& controller)
    : controller(controller) {
    command_handlers["list_available"] = [this]() { handle_list_available_sorted_by_price(); };
    command_handlers["search"] = [this]() { handle_search_product(); };
    command_handlers["help"] = [this]() { print_commands(); };
    command_handlers["exit"] = []() { exit(0); };
}

void CustomerUI::run() {
    print_commands();
    string command;

    while (true) {
        cout << "\n> ";
        getline(cin, command);

        auto it = command_handlers.find(command);
        if (it != command_handlers.end()) {
            it->second();
        } else {
            cout << "Invalid command. Type 'help' to see the list of commands.\n";
        }
    }
}

void CustomerUI::print_commands() const {
    cout << "\nAvailable commands:\n";
    cout << "  list_available  - Show all available products, sorted by increasing price\n";
    cout << "  search          - Search for a product by name\n";
    cout << "  help            - Display this list of commands\n";
    cout << "  exit            - Exit the application\n";
}

void CustomerUI::handle_list_available_sorted_by_price() const {
    auto available_products = controller.get_available_products_sorted_by_price();
    if (available_products.empty()) {
        cout << "There are no products available at the moment.\n";
    } else {
        cout << available_products;
    }
}

void CustomerUI::handle_search_product() const {
    cout << "Enter the product name: ";
    string name;
    getline(cin, name);

    try {
        const auto& result = controller.search_by_name(name);
        cout << result << '\n';
    } catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }
}

ostream& ui::operator<<(ostream& out, const Domain::Apotheke& product) {
    out << "ID: " << product.get_id()
        << " | Name: " << product.get_name()
        << " | Price: " << product.get_price()
        << " | In stock: " << product.get_stock()
        << " | Reserved: " << product.get_reserved() << '\n';
    return out;
}

ostream& ui::operator<<(ostream& out, const vector<Domain::Apotheke>& list) {
    for (const auto& product : list) {
        out << product;
    }
    return out;
}
