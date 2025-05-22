#ifndef EMPLOYEE_CONTROLLER_H
#define EMPLOYEE_CONTROLLER_H
#pragma once

#include "../Repository/employee_repository.h"
#include "../Domain/employee.h"

#include <vector>
#include <string>

namespace Controller {

    class EmployeeController {
    private:
        repository::EmployeeRepository& employee_repo;

    public:
        EmployeeController(repository::EmployeeRepository& employee_repo);

        bool add_employee(const std::string& surname,
                          const std::string& first_name,
                          const std::string& email,
                          const std::string& position,
                          const Domain::Date& birthdate,
                          int salary);
    };

}

#endif
