#ifndef EMPLOYEE_UI_H
#define EMPLOYEE_UI_H

#include "../Controller/employee_controller.h"

namespace UI {

    class EmployeeUI {
    private:
        Controller::EmployeeController& controller;

        void show_main_menu();
        void handle_add_employee();
        void handle_create_client();
        void handle_update_client();
        void handle_delete_client();


        // bool add_employee(const string & surname, const string & first_name, const string & email, const string & position,
        //                   const Date & birthdate, int salary);

    public:
        explicit EmployeeUI(Controller::EmployeeController& controller);
        void run();
    };



}

#endif // EMPLOYEE_UI_H
