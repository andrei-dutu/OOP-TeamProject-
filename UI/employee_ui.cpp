#include "employee_ui.h"
#include "../Controller/employee_controller.h"
#include <iostream>
#include <limits>

namespace UI {
    using namespace std;
    using namespace Controller;

    EmployeeUI::EmployeeUI(EmployeeController& controller) : controller(controller) {}

    void EmployeeUI::show_main_menu() {
        cout << "\n=== Employee Menu ===\n";
        cout << "1. Add Employee\n";
        cout << "2. Create Client\n";
        cout << "3. Update Client\n";
        cout << "4. Delete Client\n";
        cout << "5. Anonymize Client (GDPR)\n";
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
                    case 0: cout << "Exiting...\n"; break;
                    default: cout << "Invalid choice. Try again.\n"; break;
                }
            } catch (const std::exception& ex) {
                cout << "Error: " << ex.what() << "\n";
            }

        } while (choice != 0);
    }

    void EmployeeUI::handle_add_employee() {
        string surname, first_name, email, position;
        int day, month, year, salary;

        cout << "Surname: "; getline(cin, surname);
        cout << "First Name: "; getline(cin, first_name);
        cout << "Email: "; getline(cin, email);
        cout << "Position: "; getline(cin, position);
        cout << "Birthdate (DD MM YYYY): "; cin >> day >> month >> year;
        cout << "Salary (EUR): "; cin >> salary;
        cin.ignore();

        // Date birthdate{day, month, year};


        void EmployeeUI::handle_create_client() ;
        {
            size_t id;
            string name, vorname, email, handy, adresse, bemerkungen;

            cout << "Client ID: "; cin >> id; cin.ignore();
            cout << "Last Name: "; getline(cin, name);
            cout << "First Name: "; getline(cin, vorname);
            cout << "Email: "; getline(cin, email);
            cout << "Phone: "; getline(cin, handy);
            cout << "Address: "; getline(cin, adresse);
            cout << "Remarks: "; getline(cin, bemerkungen);


            void EmployeeUI::handle_update_client() ;{
                size_t id;
                string name, vorname, email, handy, adresse, bemerkungen;

                cout << "Client ID to update: "; cin >> id; cin.ignore();
                cout << "Last Name: "; getline(cin, name);
                cout << "First Name: "; getline(cin, vorname);
                cout << "Email: "; getline(cin, email);
                cout << "Phone: "; getline(cin, handy);
                cout << "Address: "; getline(cin, adresse);
                cout << "Remarks: "; getline(cin, bemerkungen);

                void EmployeeUI::handle_delete_client() ;{
                    size_t id;
                    cout << "Client ID to delete: "; cin >> id; cin.ignore();

                    if (controller.deleteEmployee(id))
                        cout << "Client deleted successfully.\n";
                }

            }
        }
    }
}
