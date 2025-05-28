#include "employee.h"

using namespace std;

Employee::Employee(int id, const string& firstName, const string& lastName, const string& email, const string& password,
                   const string& position, const string& birthDate, double salary)
    : id(id), firstName(firstName), lastName(lastName), email(email), password(password),
      position(position), birthDate(birthDate), salary(salary) {}

// Getters
int Employee::getId() const {
    return id;
}
string Employee::getFirstName() const {
    return firstName;
}
string Employee::getLastName() const {
    return lastName;
}
string Employee::getEmail() const {
    return email;
}
string Employee::getPassword() const {
    return password;
}
string Employee::getPosition() const {
    return position;
}
string Employee::getBirthDate() const {
    return birthDate;
}
double Employee::getSalary() const {
    return salary;
}

// Setters
void Employee::setFirstName(const string& firstName) {
    this->firstName = firstName;
}
void Employee::setLastName(const string& lastName) {
    this->lastName = lastName;
}
void Employee::setEmail(const string& email) {
    this->email = email;
}
void Employee::setPassword(const string& password) {
    this->password = password;
}
void Employee::setPosition(const string& position) {
    this->position = position;
}
void Employee::setBirthDate(const string& birthDate) {
    this->birthDate = birthDate;
}
void Employee::setSalary(double salary) {
    this->salary = salary;
}

std::string Employee::toString() const {
string name;
    string role;

    return "ID: " + std::to_string(id) + ", Name: " + name + ", Role: " + role;
}
