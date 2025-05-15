#ifndef EMPLOYEE_CONTROLLER_H
#define EMPLOYEE_CONTROLLER_H
#pragma once

#include "../Repository/employee_repository.h"
#include "../Repository/customer_repository.h"
#include "../Domain/employee.h"
#include "../Domain/customer.h"

#include <vector>
#include <string>

namespace Controller {

    class EmployeeController {
    private:
        Repository::EmployeeRepository& employee_repo;
        Repository::ClientRepository& client_repo;

    public:
        EmployeeController(Repository::EmployeeRepository& employee_repo,
                           Repository::CustomerRepository& client_repo);

        bool add_employee(const std::string& surname,
                          const std::string& first_name,
                          const std::string& email,
                          const std::string& position,
                          const Domain::Date& birthdate,
                          int salary);

        bool create_client(size_t id,
                           const std::string& name,
                           const std::string& vorname,
                           const std::string& email,
                           const std::string& handy,
                           const std::string& adresse,
                           const std::string& bemerkungen);

        bool update_client(size_t client_id,
                           const std::string& name,
                           const std::string& vorname,
                           const std::string& email,
                           const std::string& handy,
                           const std::string& adresse,
                           const std::string& bemerkungen);

        bool delete_client(size_t client_id);
        bool anonymize_client_gdpr(size_t client_id);
    };

}

#endif
