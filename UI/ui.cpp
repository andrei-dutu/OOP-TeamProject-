//
// Created by Andrei Pop on 02.05.2025.
//
#include "ui.h"
#include "../Domain/employee.h"
#include "../Domain/customer.h"
#include "customer_ui.h"
#include "employee_ui.h"

namespace UI {
    LoginResult ui::login() {
        std::cout << "Login email: ";
        std::string email;
        std::cin >> email;

        std::cout << "Password: ";
        std::string password;
        std::cin >> password;

        Customer* customer = customer_controller.findByEmail(email);
        if (customer && customer->getPassword() == password) {
            std::cout << "Logged in as customer." << std::endl;
            return {UserType::Customer, customer};
        }

        Employee* employee = employee_controller.findByEmail(email);
        if (employee && employee->getPassword() == password) {
            std::cout << "Logged in as employee." << std::endl;
            return {UserType::Employee, employee};
        }

        std::cout << "Invalid email or password." << std::endl;
        return {UserType::None, nullptr};
    }

        void ui::run() {
            LoginResult result;
            do {
                result = login();
            } while (result.type == UserType::None);

            if (result.type == UserType::Customer) {
                Customer* customer = static_cast<Customer*>(result.user);
                CustomerUI customer_ui(customer_controller);
                // Call customer menu
            } else if (result.type == UserType::Employee) {
                Employee* employee = static_cast<Employee*>(result.user);
                EmployeeUI employee_ui(employee_controller);
                employee_ui.run();
                // Call employee menu
            }
        }
    }
