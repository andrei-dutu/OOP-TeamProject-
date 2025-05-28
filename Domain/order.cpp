//
// Created by Andrei Pop on 02.05.2025.
//
#include "order.h"
#include <string>
namespace Domain {

    int Order::getOrderNumber() const {
        return order_number;
    }

     Date Order::getDate() const {
        return date;
    }

    std::string Order::getStatus() const{
        return status;
    }

    Product Order::getProduct() {
        return product;
    }

    int Order::getQuantity() const {
        return quantity;
    }

    std::string Order::getCustomerEmail() {
        return customer_email;
    }

    std::string Order::getEmployeeEmail() {
        return employee_email;
    }

    int Order::getTotalAmount() const {
        return total_amount;
    }

    void Order::setOrderNumber(int order_number) {
        this->order_number = order_number;
    }

    void Order::setDate(const Date date) {
        this->date = date;
    }

    void Order::setStatus(const std::string& status) {
        this->status = status;
    }

    void Order::setProduct(const Product& product) {

        this->product = product;
        total_amount = this->product.getPrice() * quantity;
    }

    void Order::setQuantity(int quantity) {
        this->quantity = quantity;
        total_amount = product.getPrice() * this->quantity;
    }

    void Order::setCustomerEmail(const std::string& customer_email) {
        this->customer_email = customer_email;
    }

    void Order::setEmployeeEmail(const std::string& employee_email) {
        this->employee_email = employee_email;
    }

    void Order::setTotalAmount(const int total_amount) {
        this->total_amount = total_amount;
    }

}