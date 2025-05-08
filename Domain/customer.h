#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>

using namespace std;

namespace Domain {

    class Customer {

    struct Address {
        string country;
        string city;
        string street;
        string number;
    };
    private:

        string surname;
        string first_name;
        string email;
        Address address;
        bool GDPR;

    public:

        Customer(string& surname, string& first_name, string& email, Address& address, bool GDPR) :
        surname(surname), first_name(first_name), email(email), address(address), GDPR(GDPR) {}
        string getSurname();
        string getFirstName();
        string getEmail();
        Address getAddress();
        bool getGDPR();

    };
}
#endif 
