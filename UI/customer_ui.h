//
// Created by Andrei Pop on 16.05.2025.
//
//
// Created by Dell on 09.04.2025.
//

#ifndef CUSTOMERUI_H
#define CUSTOMERUI_H

#pragma once
#include"Controller/customer_controller.h"
#include"Domain/customer.h"
#include <iostream>
#include <unordered_map>
#include <functional>


namespace ui {

    class CustomerUI {
    public:
        explicit CustomerUI(Controller::CustomerController& controller);
        void run();

    private:
        controller::CustomerController& controller;
        std::unordered_map<std::string, std::function<void()>> command_handlers;

        void print_commands() const;
        void handle_list_available_sorted_by_price() const;
        void handle_search_product() const;
    };

    std::ostream& operator<<(std::ostream& out, const Domain::Apotheke& product);
    std::ostream& operator<<(std::ostream& out, const std::vector<Domain::Apotheke>& list);
}

#endif // CUSTOMERUI_H

