#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
#pragma once

using namespace std;

class Customer {
private:
    int id;
    string firstName;
    string lastName;
    string email;
    string password;

    struct Address {
        string country;
        string city;
        string street;
        int streetNumber;
    };
    Address address;

    string notes;

    bool gdprDeleted;

public:
    Customer(int id, const string& firstName, const string& lastName, const string& email, const string& password,
                const Address& address, const string& notes = "", bool gdprDeleted = false);

    //Get
    int getId() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    string getPassword() const;
    Address getAddress() const;
    string getNotes() const;
    bool isGdprDeleted() const;

    //Set
    void setFirstName(const string& firstName);
    void setLastName(const string& lastName);
    void setEmail(const string& email);
    void setPassword(const string& password);
    void setAddress(const Address& address);
    void setNotes(const string& notes);
    void setGdprDeleted(bool gdprDeleted);

    void anonymize();
};

#endif 
