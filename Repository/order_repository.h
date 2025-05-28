//
// Created by Andrei Pop on 02.05.2025.
//

#ifndef ORDER_REPOSITORY_H
#define ORDER_REPOSITORY_H
#include <vector>
#include "../Domain/order.h"

namespace Repository {

    class OrderRepository {

    private:

        std::vector<Domain::Order> order_storage;

    public:
        OrderRepository():order_storage {
    {1,  {15, 5, 2025}, "Processing", {"P100", "Laptop", 999.99, 10}, 2, "ion.popescu@test.ro", "max.mustermann@test.de"},
    {2,  {16, 5, 2025}, "Completed",  {"P200", "Smartphone", 699.99, 15}, 1, "maria.smith@test.com", "anna.schmidt@test.de"},
    {3,  {17, 5, 2025}, "Processing", {"P300", "Tablet", 349.99, 5}, 3, "andrei.georgescu@test.ro", "lukas.meier@test.de"},
    {4,  {18, 5, 2025}, "Cancelled",  {"P400", "Monitor", 249.99, 8}, 1, "elena.garcia@test.es", "julia.klein@test.de"},
    {5,  {19, 5, 2025}, "Completed",  {"P500", "Keyboard", 49.99, 20}, 4, "vasile.marinescu@test.ro", "peter.fischer@test.de"},
    {6,  {20, 5, 2025}, "Processing", {"P100", "Laptop", 999.99, 10}, 1, "ioana.mueller@test.de", "laura.becker@test.de"},
    {7,  {21, 5, 2025}, "Completed",  {"P200", "Smartphone", 699.99, 15}, 2, "george.stan@test.ro", "tom.schneider@test.de"},
    {8,  {22, 5, 2025}, "Shipped",    {"P300", "Tablet", 349.99, 5}, 1, "ion.popescu@test.ro", "max.mustermann@test.de"},
    {9,  {23, 5, 2025}, "Pending",    {"P400", "Monitor", 249.99, 8}, 2, "maria.smith@test.com", "anna.schmidt@test.de"},
    {10, {24, 5, 2025}, "Processing", {"P500", "Keyboard", 49.99, 20}, 5, "andrei.georgescu@test.ro", "lukas.meier@test.de"},
    {11, {25, 5, 2025}, "Completed",  {"P100", "Laptop", 999.99, 10}, 1, "elena.garcia@test.es", "julia.klein@test.de"},
    {12, {26, 5, 2025}, "Cancelled",  {"P200", "Smartphone", 699.99, 15}, 3, "vasile.marinescu@test.ro", "peter.fischer@test.de"},
    {13, {27, 5, 2025}, "Shipped",    {"P300", "Tablet", 349.99, 5}, 2, "ioana.mueller@test.de", "laura.becker@test.de"},
    {14, {28, 5, 2025}, "Pending",    {"P400", "Monitor", 249.99, 8}, 1, "george.stan@test.ro", "tom.schneider@test.de"},
    {15, {29, 5, 2025}, "Completed",  {"P500", "Keyboard", 49.99, 20}, 2, "ion.popescu@test.ro", "max.mustermann@test.de"},
    {16, {30, 5, 2025}, "Processing", {"P100", "Laptop", 999.99, 10}, 1, "maria.smith@test.com", "anna.schmidt@test.de"},
    {17, {31, 5, 2025}, "Shipped",    {"P200", "Smartphone", 699.99, 15}, 2, "andrei.georgescu@test.ro", "lukas.meier@test.de"},
    {18, {1, 6, 2025},  "Completed",  {"P300", "Tablet", 349.99, 5}, 1, "elena.garcia@test.es", "julia.klein@test.de"},
    {19, {2, 6, 2025},  "Cancelled",  {"P400", "Monitor", 249.99, 8}, 3, "vasile.marinescu@test.ro", "peter.fischer@test.de"},
    {20, {3, 6, 2025},  "Pending",    {"P500", "Keyboard", 49.99, 20}, 1, "ioana.mueller@test.de", "laura.becker@test.de"}
}{}
        std::vector<Domain::Order> returnStorage();
        void addOrder(const Domain::Order& order);
        Domain::Order searchOrder(int id) const;
        std::vector<Domain::Order> findOrdersByEmployee(const std::string& email) const;
        std::vector<Domain::Order> findOrdersByCustomer(const std::string& email) const;
        std::vector<Domain::Order> findOrdersByStatus(const std::string& status) const;
        std::vector<Domain::Order> findOrdersByYearAndMonth(int year, int month) const;
        std::vector<Domain::Order> findOrdersByYear(int year) const;
        std::vector<Domain::Order> findOrdersByDate(Domain::Date date) const;
        void modifyOrderStatus(int number, const std::string& new_status);
        void modifyOrderNumber(int number, int new_number);
        void modifyOrderProduct(int number, const Domain::Product& new_product);
        void modifyOrderQuantity(int number, int new_quantity);
        void giveOrderToAnotherEmployee(int number, const std::string& email);
        int getTotalAmountByYear(int year);
        int getTotalAmountByMonth(int year, int month);


    };
}

#endif //ORDER_REPOSITORY_H
