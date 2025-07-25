cmake_minimum_required(VERSION 3.30)
project(TeamProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(App main.cpp Controller/customer_controller.cpp Controller/customer_controller.h
        Controller/employee_controller.cpp Controller/employee_controller.h Controller/order_controller.cpp
        Controller/order_controller.h
        Controller/product_controller.cpp Controller/product_controller.h Domain/employee.cpp Domain/employee.h
        Domain/customer.cpp Domain/customer.h
        Domain/product.cpp Domain/product.h Domain/order.h Domain/order.cpp Repository/customer_repository.cpp
        Repository/customer_repository.h
        Repository/employee_repository.cpp Repository/employee_repository.h Repository/product_repository.cpp
        Repository/product_repository.h Repository/order_repository.cpp Repository/order_repository.h UI/ui.cpp
        UI/ui.h UI/employee_ui.cpp UI/employee_ui.h UI/customer_ui.cpp UI/customer_ui.h Domain Repository UI Controller)

add_executable(Test test.cpp Tests/tests.cpp Tests/tests.h Tests Controller/customer_controller.cpp
        Controller/employee_controller.cpp
        Controller/order_controller.cpp
        Controller/product_controller.cpp

        Domain/employee.cpp
        Domain/customer.cpp
        Domain/product.cpp
        Domain/order.cpp

        Repository/customer_repository.cpp
        Repository/employee_repository.cpp
        Repository/product_repository.cpp
        Repository/order_repository.cpp)

