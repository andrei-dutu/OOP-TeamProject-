#ifndef EMPLOYEE_CONTROLLER_H
#define EMPLOYEE_CONTROLLER_H
#pragma once

#include "../Repository/employee_repository.h"
#include "../Repository/order_repository.h"
#include "../Domain/employee.h"
#include "../Domain/order.h"

#include <vector>
#include <string>
#include <map>

namespace Controller {

    class EmployeeController {
    private:
        repository::EmployeeRepository& employee_repo;
        repository::OrderRepository& order_repo;

    public:
        EmployeeController(repository::EmployeeRepository& employee_repo,
                           repository::OrderRepository& order_repo);

        // 🧩 Funcții legate de angajați
        bool add_employee(const std::string& surname,
                          const std::string& first_name,
                          const std::string& email,
                          const std::string& position,
                          const Domain::Date& birthdate,
                          int salary);
        void confirm_order(int order_id, const std::string& employee_name);
        void edit_order(int order_id, const std::string& new_product, int new_quantity, const std::string& employee_name);
        void complete_order(int order_id, const std::string& employee_name);
        void claim_order(int order_id, const std::string& employee_name);
        std::vector<Domain::Order> get_all_orders() const;
        std::vector<Domain::Order> get_orders_by_status(const std::string& status) const;
        double get_total_sum_by_month(int year, int month) const;
        double get_total_sum_by_year(int year) const;
        std::map<std::string, double> get_total_sum_by_product(int year) const;
        std::map<std::string, double> get_total_sum_by_customer(int year) const;
        std::map<std::string, double> get_total_sum_by_employee(int year) const;
    };

}

#endif // EMPLOYEE_CONTROLLER_H
