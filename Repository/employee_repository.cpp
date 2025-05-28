#include "employee_repository.h"

using namespace std;

EmployeeRepository::EmployeeRepository() : employees {
            {1, "Max", "Mustermann", "max.mustermann@test.de", "maxpass123", "Verkäufer", "03.07.1996", 2100},
            {2, "Anna", "Schmidt", "anna.schmidt@test.de", "annapass456", "Manager", "15.04.1989", 3200},
            {3, "Lukas", "Meier", "lukas.meier@test.de", "lukaspass789", "Verkäufer", "22.11.1992", 2000},
            {4, "Julia", "Klein", "julia.klein@test.de", "juliapass000", "Buchhaltung", "30.01.1985", 2500},
            {5, "Peter", "Fischer", "peter.fischer@test.de", "peterpass999", "Verkäufer", "11.09.1990", 2200},
            {6, "Laura", "Becker", "laura.becker@test.de", "laurapass321", "Manager", "05.06.1988", 3300},
            {7, "Tom", "Schneider", "tom.schneider@test.de", "tompass654", "Verkäufer", "19.12.1994", 2100},
        } {}

vector<Employee>& EmployeeRepository::getEmployees() {
    return employees;
}

void EmployeeRepository::addEmployee(const Employee& employee) {
    employees.push_back(employee);
}

bool EmployeeRepository::updateEmployee(int id, const Employee& updatedEmployee) {
    for (int i = 0; i < employees.size(); i++) {
        if (id == employees[i].getId()) {
            employees[i] = updatedEmployee;
            return true;
        }
    }
    return false;
}

bool EmployeeRepository::deleteEmployee(int id) {
    for (int i = 0; i < employees.size(); i++) {
        if (id == employees[i].getId()) {
            employees.erase(employees.begin() + i);
            return true;
        }
    }
    return false;
}

Employee* EmployeeRepository::findByEmail(const string& email) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].getEmail() == email) {
            return &employees[i];
        }
    }
    return nullptr; // employee not found
}

int EmployeeRepository::getEmployeeCount() const {
    return employees.size();
}

vector<Employee> EmployeeRepository::getAllEmployees() const {
    return employees;  // assuming 'employees' is your internal list
}

