#include "employee_ui.h"
#include <iostream>
#include <limits>
#include <sstream>

namespace UI {
    using namespace std;
    using namespace Controller;

    EmployeeUI::EmployeeUI(EmployeeController& controller) : controller(controller), productController() {
    }

    void EmployeeUI::show_main_menu() {
        cout << "\n=== Employee Menu ===\n";
        cout << "1. Add Employee\n";
        cout << "2. Create Client\n";
        cout << "3. Update Client\n";
        cout << "4. Delete Client\n";
        cout << "5. Anonymize Client (GDPR)\n";
        cout << "6. Show all employees\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
    }

    void EmployeeUI::run() {
        int choice;
        do {
            show_main_menu();
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            try {
                switch (choice) {
                    case 1: handle_add_employee(); break;
                    case 2: handle_create_client(); break;
                    case 3: handle_update_client(); break;
                    case 4: handle_delete_client(); break;
                    case 5: handle_anonymize_client(); break;
                    case 6: showAllEmployees(); break;
                    case 0: cout << "Exiting...\n"; break;
                    default: cout << "Invalid choice. Try again.\n"; break;
                }
            } catch (const exception& ex) {
                cout << "Error: " << ex.what() << "\n";
            }

        } while (choice != 0);
    }

    void EmployeeUI::handle_add_employee() {
        string lastName, firstName, email, password, position;
        int day, month, year;
        double salary;

        cout << "Last Name: "; getline(cin, lastName);
        cout << "First Name: "; getline(cin, firstName);
        cout << "Email: "; getline(cin, email);
        cout << "Password: "; getline(cin, password);
        cout << "Position: "; getline(cin, position);
        cout << "Birthdate (DD MM YYYY): "; cin >> day >> month >> year;
        cout << "Salary (EUR): "; cin >> salary;
        cin.ignore();

        stringstream birthDateStream;
        birthDateStream << (day < 10 ? "0" : "") << day << "."
                        << (month < 10 ? "0" : "") << month << "."
                        << year;

        string birthDate = birthDateStream.str();

        int id = controller.getAllEmployees().size() + 1; // simplistic ID generation
        Employee newEmployee(id, firstName, lastName, email, password, position, birthDate, salary);

        controller.addEmployee(newEmployee);
        cout << "Employee added successfully.\n";
        pause();
    }

    void EmployeeUI::handle_create_client() {
        cout << "[Create Client] Feature not implemented yet.\n";
        pause();
    }

    void EmployeeUI::handle_update_client() {
        cout << "[Update Client] Feature not implemented yet.\n";
        pause();
    }

    void EmployeeUI::handle_delete_client() {
        size_t id;
        cout << "Client ID to delete: "; cin >> id;
        cin.ignore();

        if (controller.deleteEmployee(id))
            cout << "Client deleted successfully.\n";
        pause();
    }

    void EmployeeUI::handle_anonymize_client() {
        cout << "[Anonymize Client] Feature not implemented yet.\n";
        pause();
    }

    void EmployeeUI::pause() {
        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void EmployeeUI::showAllEmployees() {
        std::vector<Employee> employees = controller.getAllEmployees();
        if (employees.empty()) {
            std::cout << "No employees found.\n";
        } else {
            for (const auto& emp : employees) {
                std::cout << emp.toString() << "\n"; // assuming toString() exists
            }
        }
    }

    void EmployeeUI::showAllProducts() {
        const std::vector<Domain::Product>& products = productController.getAllProducts();

        if (products.empty()) {
            std::cout << "No products available.\n";
        } else {
            for (const auto& p : products) {
                std::cout << "ID: " << p.getId()
                          << ", Name: " << p.getName()
                          << ", Price: " << p.getPrice()
                          << ", Stock: " << p.getStock() << "\n";
            }
        }
        pause();
    }


}
