#include "Employee.h"

namespace Domain {

    Employee::Employee(const std::string& surname, const std::string& first_name, const std::string& email,
                       const std::string& position, Date date, int salary)
        : surname(surname), first_name(first_name), email(email), position(position), date(date), salary(salary) {}

    std::string Employee::getSurname() const {
        return surname;
    }

    std::string Employee::getFirstName() const {
        return first_name;
    }

    std::string Employee::getEmail() const {
        return email;
    }

    std::string Employee::getPosition() const {
        return position;
    }

    Date Employee::getDate() const {
        return date;
    }

    int Employee::getSalary() const {
        return salary;
    }

    std::string Employee::getPassword() const {
        return password;
    }

    bool Employee::isActive() const {
        return active;
    }

    bool Employee::isAdmin() const {
        return is_admin;
    }

    std::string Employee::getRemarks() const {
        return remarks;
    }

    void Employee::setActive(bool status) {
        active = status;
    }

    void Employee::setAdmin(bool status) {
        is_admin = status;
    }

    void Employee::setPassword(const std::string& new_password) {
        password = new_password;
    }

    void Employee::setRemarks(const std::string& new_remarks) {
        remarks = new_remarks;
    }

}
