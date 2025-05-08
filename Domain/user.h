//
// Created by Andrei Pop on 02.05.2025.
//

#ifndef USER_H
#define USER_H
#include <string>

namespace Domain {

    enum class UserType {
        Customer,
        Employee
    };

    class User {

    private:

        std::string email;
        std::string password;
        UserType type;

    public:

        User(const std::string& email, const std::string& password, UserType type) : email(email),
        password(password), type(type){}
        std::string getEmail();
        std::string getPassword();
        UserType getType();

    };
}

#endif //USER_H
