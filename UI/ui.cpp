//
// Created by Andrei Pop on 02.05.2025.
//
#include "ui.h"
namespace UI {
    void UI::run() {
        std::cout<<"Login:";
        std::string email;
        cin>>email;

        if (customer_controller.findByEmail(email) != nullptr) {
            std::string password;
            cin>>password;
            if (customer_controller.findByEmail(email)->getPassword() == password)

        }//if (employee_controller.)
    }

}