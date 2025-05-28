#ifndef EMPLOYEE_CONTROLLER_H
#define EMPLOYEE_CONTROLLER_H

#include "../Repository/employee_repository.h"
namespace Controller {
    class EmployeeController {
    private:
        EmployeeRepository& repository;

    public:
        EmployeeController(EmployeeRepository& repo);

        vector<Employee>& getAllEmployees();
        void addEmployee(const Employee& employee);
        bool updateEmployee(int id, const Employee& updatedEmployee);
        bool deleteEmployee(int id);
        Employee* findByEmail(const string& email);

    };
}


#endif
