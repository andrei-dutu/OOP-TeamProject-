#ifndef EMPLOYEE_UI_H
#define EMPLOYEE_UI_H

#include "../Controller/employee_controller.h"
#include <string>
#include <unordered_map>
#include <functional>

namespace ui {

    class EmployeeUI {
    private:
        Controller::EmployeeController& controller;
        std::string employee_name;

        std::unordered_map<std::string, std::function<void()>> command_handlers;

        void print_commands() const;
        void confirm_order();
        void edit_order();
        void complete_order();
        void claim_order();
        void list_all_orders();
        void list_by_status();
        void show_total_sum();

    public:
        EmployeeUI(Controller::EmployeeController& controller, const std::string& employee_name);
        void run();
    };

} // namespace ui

#endif // EMPLOYEE_UI_H
