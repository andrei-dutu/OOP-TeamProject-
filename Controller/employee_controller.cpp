#include "employee_controller.h"
#include "../Repository/employee_repository.h"
#include <stdexcept>
#include <ctime>
#include <sstream>

namespace Controller {

    using namespace Domain;

    EmployeeController::EmployeeController(repository::EmployeeRepository& employee_repo)
        : employee_repo(employee_repo) {}

    int calculate_age(const Date& birthdate) {
        time_t now_time = time(nullptr);
        tm* now = localtime(&now_time);

        int age = now->tm_year + 1900 - birthdate.year;

        if (birthdate.month > now->tm_mon + 1 ||
            (birthdate.month == now->tm_mon + 1 && birthdate.day > now->tm_mday)) {
            age--;
        }

        return age;
    }

    bool EmployeeController::add_employee(const std::string& surname,
                                          const std::string& first_name,
                                          const std::string& email,
                                          const std::string& position,
                                          const Date& birthdate,
                                          int salary) {
        if (surname.empty() || first_name.empty() || email.empty()) {
            throw std::runtime_error("All fields are required except position and remarks.");
        }

        if (salary < 100) {
            throw std::runtime_error("Salary must be at least 100 EUR.");
        }

        int age = calculate_age(birthdate);
        if (age < 0 || age > 80) {
            throw std::runtime_error("Age must be between 0 and 80.");
        }

        std::string new_shortcut = first_name.substr(0, 2) + surname.substr(0, 2);

        for (const auto& emp : employee_repo.get_all()) {
            if (emp.getEmail() == email) {
                throw std::runtime_error("Email must be unique.");
            }

            std::string existing_shortcut = emp.getFirstName().substr(0, 2) + emp.getSurname().substr(0, 2);
            if (existing_shortcut == new_shortcut) {
                throw std::runtime_error("Shortcut (first 2 letters of first name + surname) must be unique.");
            }
        }

        Employee emp(surname, first_name, email, position, birthdate, salary);
        employee_repo.add(emp);
        return true;
    }

}
