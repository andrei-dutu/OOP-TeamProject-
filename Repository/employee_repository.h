#ifndef EMPLOYEE_REPOSITORY_H
#define EMPLOYEE_REPOSITORY_H

#include <vector>
#include <iostream>
#include "../Domain/employee.h"

using namespace std;

class EmployeeRepository {

private:
    vector<Employee> employees;

public:
    EmployeeRepository();

    vector<Employee>& getEmployees();
    void addEmployee(const Employee& employee);
    bool updateEmployee(int id, const Employee& updatedEmployee);
    bool deleteEmployee(int id);
    Employee* findByEmail(const string& email);
    int getEmployeeCount() const;
};

#endif
