//
// Created by Andrei Pop on 02.05.2025.
//

#ifndef ORDER_H
#define ORDER_H
#include "employee.h"
#include <string>
#include "product.h"

namespace Domain {

    struct Date {
        int day, month, year;
        Date(const int day, const int month, const int year) : day(day), month(month), year(year) {};
    };

    class Order {
    private:
        int order_number;
        Date date;
        std::string status;
        Product product;
        int quantity;
        std::string customer_email;
        std::string employee_email;
        int total_amount;

    public:
        Order(int order_number, Date date, std::string status, Product product, int quantity,
            std::string customer_email, std::string employee_email) : order_number(order_number), date(date),
            status(status), product(product), quantity(quantity), customer_email(customer_email),
            employee_email(employee_email) {
            total_amount = product.getPrice() * quantity;
        }

        int getOrderNumber() const;
        Date getDate() const;
        std::string getStatus();
        Product getProduct();
        int getQuantity() const;
        std::string getCustomerEmail();
        std::string getEmployeeEmail();
        int getTotalAmount() const;
        void setOrderNumber(int order_number);
        void setDate(Date date);
        void setStatus(const std::string& status);
        void setProduct(const Product& product);
        void setQuantity(int quantity);
        void setCustomerEmail(const std::string& customer_email);
        void setEmployeeEmail(const std::string& employee_email);
        void setTotalAmount(int total_amount);
    };
}

#endif //ORDER_H
