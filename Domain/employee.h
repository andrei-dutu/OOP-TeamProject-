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

    public:

        Employee(std::string& surname, std::string& first_name, std::string& email, std::string& position, Date date,
            int salary) : surname(surname), first_name(first_name), email(email), position(position), date(date),
            salary(salary) {}
        std::string getSurname();
        std::string getFirstName();
        std::string getEmail();
        std::string getDate();
        int getSalary();

    };

}
#endif //EMPLOYEE_H
