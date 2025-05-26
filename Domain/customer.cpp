#include "customer.h"

using namespace std;

Customer::Customer(int id, const string& firstName, const string& lastName, const string& email,
                const Address& address, const string& notes, bool gdprDeleted)
                    : id(id), firstName(firstName), lastName(lastName), email(email),
                    address(address), notes(notes), gdprDeleted(gdprDeleted) {}

//Get

int Customer::getId() const {
    return id;
}
string Customer::getFirstName() const {
    return firstName;
}
string Customer::getLastName() const {
    return lastName;
}
string Customer::getEmail() const {
    return email;
}
Customer::Address Customer::getAddress() const {
    return address;
}
string Customer::getNotes() const {
    return notes;
}
bool Customer::isGdprDeleted() const {
    return gdprDeleted;
}

//Set

void Customer::setFirstName(const string& firstName) {
    this->firstName = firstName;
}
void Customer::setLastName(const string& lastName) {
    this->lastName = lastName;
}
void Customer::setEmail(const string& email) {
    this->email = email;
}
void Customer::setAddress(const Address& address) {
    this->address = address;
}
void Customer::setNotes(const string& notes) {
    this->notes = notes;
}
void Customer::setGdprDeleted(bool gdprDeleted) {
    this->gdprDeleted = gdprDeleted;
}


void Customer::anonymize()
{
    lastName = "Kunde-" + to_string(id);
    firstName = "Anonymus";
    email = "";
    address = {"", "", "", 0};
    notes = "";
    gdprDeleted = true;
}
