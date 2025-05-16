//
// Created by Andrei Pop on 02.05.2025.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

namespace Domain {

    struct Date {
        int day, month, year;
    };

    class Employee {

    private:
        std::string surname;
        std::string first_name;
        std::string email;
        std::string position;
        Date date;
        int salary;
        bool active = true;
        bool is_admin = false;
        std::string password = "default123";
        std::string remarks;

    public:
        Employee(const std::string& surname, const std::string& first_name, const std::string& email,
                 const std::string& position, Date date, int salary);

        std::string getSurname() const;
        std::string getFirstName() const;
        std::string getEmail() const;
        std::string getPosition() const;
        Date getDate() const;
        int getSalary() const;
        std::string getPassword() const;
        bool isActive() const;
        bool isAdmin() const;
        std::string getRemarks() const;

        void setActive(bool status);
        void setAdmin(bool status);
        void setPassword(const std::string& new_password);
        void setRemarks(const std::string& new_remarks);
    };

}

#endif
