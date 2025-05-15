#include "employee_repository.h"

namespace repository {

    using namespace Domain;

    void EmployeeRepository::add(const Employee& employee) {
        all.push_back(employee);
    }

    const std::vector<Employee>& EmployeeRepository::get_all() const {
        return all;
    }

    std::vector<Employee>& EmployeeRepository::get_all_ref() {
        return all;
    }

    std::optional<size_t> EmployeeRepository::find_index_by_email(const std::string& email) {
        for (size_t i = 0; i < all.size(); ++i) {
            if (all[i].getEmail() == email) {
                return i;
            }
        }
        return std::nullopt;
    }

    bool EmployeeRepository::update_employee(const std::string& email, const Employee& updated_employee) {
        auto index = find_index_by_email(email);
        if (index.has_value()) {
            all[index.value()] = updated_employee;
            return true;
        }
        return false;
    }

    bool EmployeeRepository::set_active_status(const std::string& email, bool active) {
        auto index = find_index_by_email(email);
        if (index.has_value()) {
            all[index.value()].setActive(active);
            return true;
        }
        return false;
    }

    bool EmployeeRepository::remove_employee(const std::string& email) {
        auto index = find_index_by_email(email);
        if (index.has_value()) {
            all.erase(all.begin() + index.value());
            return true;
        }
        return false;
    }

    bool EmployeeRepository::set_admin_rights(const std::string& email, bool is_admin) {
        auto index = find_index_by_email(email);
        if (index.has_value()) {
            all[index.value()].setAdmin(is_admin);
            return true;
        }
        return false;
    }

    bool EmployeeRepository::reset_password(const std::string& email, const std::string& new_password) {
        auto index = find_index_by_email(email);
        if (index.has_value()) {
            all[index.value()].setPassword(new_password);
            return true;
        }
        return false;
    }

}
