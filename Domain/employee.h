#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>
#pragma once

using namespace std;

class Employee {
private:
    int id;
    string firstName;
    string lastName;
    string email;
    string password;
    string position;
    string birthDate;  // format dd.mm.yyyy
    double salary;

public:
    Employee(int id, const string& firstName, const string& lastName, const string& email, const string& password,
             const string& position, const string& birthDate, double salary);

    // Getters
    int getId() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    string getPassword() const;
    string getPosition() const;
    string getBirthDate() const;
    double getSalary() const;
    string toString() const;

    // Setters
    void setFirstName(const string& firstName);
    void setLastName(const string& lastName);
    void setEmail(const string& email);
    void setPassword(const string& password);
    void setPosition(const string& position);
    void setBirthDate(const string& birthDate);
    void setSalary(double salary);
};

#endif
