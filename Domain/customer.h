//
// Created by Andrei Pop on 02.05.2025.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

namespace Domain {

    class Customer {

    struct Address {
        std::string country;
        std::string city;
        std::string street;
        std::string number;
    };
    private:

        std::string surname;
        std::string first_name;
        std::string email;
        Address address;
        bool GDPR;

    public:

        Customer(std::string& surname, std::string& first_name, std::string& email, Address& address, bool GDPR) :
        surname(surname), first_name(first_name), email(email), address(address), GDPR(GDPR) {}
        std::string getSurname();
        std::string getFirstName();
        std::string getEmail();
        Address getAddress();
        bool getGDPR();

    };
}
#endif //CUSTOMER_H
