#ifndef EMPLOYEE_UI_H
#define EMPLOYEE_UI_H

#include "../Controller/employee_controller.h"
#include "../Controller/product_controller.h"

namespace UI {

    class EmployeeUI {
    private:
        Controller::EmployeeController& controller;
        Controller::ProductController& productController;


        void show_main_menu();
        void handle_add_employee();
        void handle_create_client();
        void handle_update_client();
        void handle_delete_client();
        void handle_anonymize_client();
        void pause();


    public:

        explicit EmployeeUI(Controller::EmployeeController& controller);
        void showAllProducts();
        void showAllEmployees();
        void run();
    };
}

#endif // EMPLOYEE_UI_H

//sa afiseze toate produsele