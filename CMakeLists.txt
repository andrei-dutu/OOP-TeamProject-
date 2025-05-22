cmake_minimum_required(VERSION 3.30)
project(TeamProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(App main.cpp Controller/customer_controller.cpp Controller/customer_controller.h
        Controller/employee_controller.cpp Controller/employee_controller.h Controller/order_controller.cpp
        Controller/order_controller.h Controller/user_controller.cpp Controller/user_controller.h
        Controller/product_controller.cpp Controller/product_controller.h Domain/user.cpp
        Domain/user.h Domain/employee.cpp Domain/employee.h Domain/customer.cpp Domain/customer.h
        Domain/product.cpp Domain/product.h Domain/order.h Domain/order.cpp Repository/user_repository.cpp
        Repository/user_repository.h Repository/customer_repository.cpp Repository/customer_repository.h
        Repository/employee_repository.cpp Repository/employee_repository.h Repository/product_repository.cpp
        Repository/product_repository.h Repository/order_repository.cpp Repository/order_repository.h UI/ui.cpp
        UI/ui.h Domain Repository UI
        )

add_executable(Test test.cpp)

