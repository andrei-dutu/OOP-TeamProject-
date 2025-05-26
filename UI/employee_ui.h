#ifndef EMPLOYEECONTROLLER_H
#define EMPLOYEECONTROLLER_H

#include "Repository/order_repository.h"
#include "Domain/order.h"
#include <vector>
#include <string>
#include <map>

namespace controller {

    class EmployeeController {
    private:
        repository::OrderRepository& order_repo;

    public:
        explicit EmployeeController(repository::OrderRepository& repo);

        std::vector<domain::Order> get_all_orders() const;

        std::vector<domain::Order> get_orders_by_status(const std::string& status) const;

        double get_total_sum_by_month(int year, int month) const;
        double get_total_sum_by_year(int year) const;

        // Optional: group by
        std::map<std::string, double> get_total_sum_by_product(int year) const;
        std::map<std::string, double> get_total_sum_by_customer(int year) const;
        std::map<std::string, double> get_total_sum_by_employee(int year) const;
    };

} // namespace controller

#endif // EMPLOYEECONTROLLER_H
